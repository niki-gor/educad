#include "canvas.h"
#include "QPicture"
#include "QBrush"
#include "QBoxLayout"
#include "QPushButton"
#include "QCursor"
#include "QPainterPath"
#include "QMenu"
#include "QApplication"
//#include "QDesktopWidget"
#include "utils.h"
#include "Entity.hpp"
#include <tuple>

std::tuple<int, int> Canvas::canvasCoordsToPlaneCoords (int x, int y, PTR<ProjectionPlane> projectionPlane) {
    std::tuple <int, int> result;
    int yResult;
    int xResult = projectionPlane->originPoint->x + x + canvasBegin.x();
    if (projectionPlane->ordinat->point2->z != 0) {
        yResult = projectionPlane->originPoint->z - y + canvasBegin.y();
    }  else if (projectionPlane->ordinat->point2->y!=0) {
        yResult = projectionPlane->originPoint->z + y + canvasBegin.y();
    }
    std::get<0>(result) = xResult;
    std::get<1>(result) = yResult;
    return result;
}

std::tuple<int,int,int> Canvas::pointPlaneCoordsToCanvasCoords (qp* object) {
    int x,y,z;
    std::tuple<int,int,int> result;
    x=canvasBegin.x()-object->pos.x();
    if (object->planeNumber == 2) {
        y = object->projections[0]->pos.y() - height() / 2;
        z = height() / 2 - object->pos.y();
    } else {
        y = object->pos.y() - height() / 2;
        z = height() / 2 - object->projections[0]->pos.y();
    }
    std::get<0>(result) = x;
    std::get<1>(result) = y;
    std::get<2>(result) = z;
    return result;
}

std::tuple<std::tuple<int,int,int>,std::tuple<int,int,int>> Canvas::linePlaneCoordsToCanvasCoords (qp* object) {
    int x1,y1,z1,x2,y2,z2;
    std::tuple<std::tuple<int,int,int>,std::tuple<int,int,int>> result;
    std::tuple<int,int,int> startPoint;
    std::tuple<int,int,int> endPoint;
    x1=canvasBegin.x()-object->pos.x();
    x2=canvasBegin.x()-object->endpos.x();
    if (object->planeNumber == 2) {
        y1 = object->projections[0]->pos.y() - height() / 2;
        z1 = height() / 2 - object->pos.y();
        y2 = object->projections[0]->endpos.y() - height() / 2;
        z2 = height() / 2 - object->endpos.y();
    } else {
        y1 = object->pos.y() - height() / 2;
        z1 = height() / 2 - object->projections[0]->pos.y();
        y2 = object->endpos.y() - height() / 2;
        z2 = height() / 2 - object->projections[0]->endpos.y();
    }
    std::get<0>(startPoint) = x1;
    std::get<1>(startPoint) = y1;
    std::get<2>(startPoint) = z1;
    std::get<0>(endPoint) = x2;
    std::get<1>(endPoint) = y2;
    std::get<2>(endPoint) = z2;
    std::get<0>(result);
    std::get<1>(result);
    return result;
}

void Canvas::addPoint(int x, int y, int xBegin, int yBegin, int planeNumber, std::string name) {
    qp* qp1 = new qp;
    qp1->pos = QPoint(x, y);
    qp1->objType = POINT;
    qp1->qpColor = Qt::black;
    qp1->needsProjection = false;
    qp1->qpName = QString::fromStdString(name);
    qp1->planeNumber = 1;
    vcp.append(qp1); //добавили в массив для рисования
    this->update();
}

void Canvas::addLine(int x1, int y1, int x2, int y2, int xBegin, int yBegin, int planeNumber, std::string name) {
    qp* qp1 = new qp;
    x1 = canvasBegin.x()-x1;
    x2 = canvasBegin.x()-x2;
    if (planeNumber==1) {
        y1 = canvasBegin.y() + y1;
        y2 = canvasBegin.y() + y2;
    } else {
        y1 = canvasBegin.y() - y1;
        y2 = canvasBegin.y() - y2;
    }
    qp1->pos = QPoint(x1, y1);
    qp1->endpos = QPoint(x2, y2);
    qp1->objType = LINE;
    qp1->qpColor = Qt::black;
    qp1->needsProjection = false;
    qp1->qpName =  QString::fromStdString(name);
    qp1->planeNumber = planeNumber;
    vcp.append(qp1); //добавили в массив для рисования
    this->update();
}

InputName::InputName(QWidget *parent) : QDialog(parent) {
    QBoxLayout *layout = new QHBoxLayout;
    m_edit = new QLineEdit;
    layout->addWidget(m_edit);
    QPushButton *okBtn = new QPushButton("OK");
    connect(okBtn, SIGNAL(clicked()), SLOT(accept()));
    layout->addWidget(okBtn);
    setLayout(layout);
}

removeRelated::removeRelated(QWidget *parent) : QMessageBox(parent) {
    this->setText("Remove related?");
    YESButton = this->addButton("Yes", ButtonRole::YesRole);
    NOButton = this->addButton("No", ButtonRole::NoRole);
    connect(YESButton, SIGNAL(clicked()), SLOT(accept()));
    connect(NOButton, SIGNAL(clicked()), SLOT(accept()));
}

int Canvas::findInVcp(int x, int y) {
    for (int i = 0; i < vcp.size(); ++i) {
        if (((vcp[i]->pos.x() >= x - 4) && (vcp[i]->pos.x() <= x + 4))
            && ((vcp[i]->pos.y() >= y - 4) && (vcp[i]->pos.y() <= y + 4))) {
            return i;
        }
    }
    return -1;
}

int Canvas::findInSelected(int x, int y) {
    for (int i = 0; i < selectedObjects.size(); ++i) {
        if (((selectedObjects[i]->pos.x() >= x - 4) && (selectedObjects[i]->pos.x() <= x + 4))
            && ((selectedObjects[i]->pos.y() >= y - 4) && (selectedObjects[i]->pos.y() <= y + 4))) {
            return i;
        }
    }
    return -1;
}

Canvas::Canvas(QWidget *parent, QMainWindow *_parent, ProjectStructureList *_projectStructureList,ControllerObservable* controllerObservable) : QWidget(parent) {
    LineContextEdit lineRMB;
    PointContextEdit pointRMB;
    pointAndLineRMB.setParent(this);
    twoPointsRMB.setParent(this);
    pointAndLineRMB.hide();
    twoPointsRMB.hide();
    projectStructureList = _projectStructureList;
    condition = 0;
    parentWindow = _parent;
    this->controllerObservable = controllerObservable;
    QRect rec = QGuiApplication::primaryScreen()->geometry();
    int scrHeight = rec.height() * 9 / 10;
    int scrWidth = rec.width();
    this->resize(scrWidth * 3 / 4, scrHeight * 9444 / 10000);
    QPalette pl; //объект палитра необходим для заданимя фона окна
    pl.setColor(QPalette::Window, QColor(255, 255, 255)); //определить цвет
    this->setAutoFillBackground(true); //фон окна заливается автоматически
    this->setPalette(pl); //устанавливаем фон окна
    selected = NOTHING;
    selectedIndex=-1;
    selectedObjects.clear();
    canvasBegin.setX(this->geometry().width()-10);
    canvasBegin.setY(this->geometry().height()/2);
    this->setMouseTracking(true);
    f = 0;
}

void Canvas::paintEvent(QPaintEvent *event) {
    QBrush brush;
    brush.setColor(Qt::black);
    QPainter p(this);
    pen.setStyle(Qt::SolidLine);
    pen.setWidth(5);
    pen.setBrush(Qt::black);
    p.setPen(pen);
    int xAxisX1 = width() - 10;
    int xAxisY1 = height() / 2;
    int xAxisX2 = 10;
    int xAxisY2 = height() / 2;
    p.drawLine(xAxisX1, xAxisY1, xAxisX2, xAxisY2);
    p.drawLine(xAxisX2, xAxisY2, xAxisX2 + 5, xAxisY2 - 5);
    p.drawLine(xAxisX2, xAxisY2, xAxisX2 + 5, xAxisY2 + 5);
    QFont font("Times", 16);
    p.setFont(font);
    p.drawText(QPoint(xAxisX2 + 10, xAxisY2 - 10), "X");
    QString posX = QString::number(pos.x());
    QString posY = QString::number(pos.y());
    p.drawText(this->size().width() * 88 / 100, this->size().height() * 95 / 100, "X: " + posX + " Y: " + posY);
    int yzAxisX1 = width() - 10;
    int yzAxisY1 = 10;
    int yzAxisX2 = width() - 10;
    int yzAxisY2 = height() - 10;
    p.drawLine(yzAxisX1, yzAxisY1, yzAxisX2, yzAxisY2);
    p.drawLine(yzAxisX1, yzAxisY1, yzAxisX1 - 5, yzAxisY1 + 5);
    p.drawLine(yzAxisX1, yzAxisY1, yzAxisX1 + 5, yzAxisY1 + 5);
    p.drawLine(yzAxisX2 - 5, yzAxisY2 - 5, yzAxisX2, yzAxisY2);
    p.drawLine(yzAxisX2 + 5, yzAxisY2 - 5, yzAxisX2, yzAxisY2);
    p.drawText(QPoint(yzAxisX1 - 30, yzAxisY1 + 35), "Z");
    p.drawText(QPoint(yzAxisX2 - 30, yzAxisY2 - 30), "Y");
    p.setBrush(Qt::black);
    pen.setWidth(10);
    p.setPen(pen);
    for (int i = 0; i < vcp.size(); ++i) {
        QString text = vcp[i]->qpName;
        pen.setColor(vcp[i]->qpColor);
        pen.setBrush(vcp[i]->qpColor);
        p.setPen(pen);
        QPainterPath path;
        if (vcp[i]->objType == POINT) {
            pen.setWidth(15);
            p.setPen(pen);
            p.drawEllipse(vcp[i]->pos.x(), vcp[i]->pos.y(), 4, 4);
            //  p.fillPath(QPainterPath(QPoint(vcp[i].pos.x(), vcp[i].pos.y())), p.brush());
            if (vcp[i]->planeNumber == 1)
                projectStructureList->addPointToXZPlaneStructure(vcp[i]->qpName);
            if (vcp[i]->planeNumber == 2)
                projectStructureList->addPointToXYPlaneStructure(vcp[i]->qpName);
        }
        if (vcp[i]->objType == LINE) {
            pen.setWidth(3);
            p.setPen(pen);
            if (vcp[i]->planeNumber == 1)
                projectStructureList->addLineToXZPlaneStructure(vcp[i]->qpName);
            if (vcp[i]->planeNumber == 2)
                projectStructureList->addLineToXYPlaneStructure(vcp[i]->qpName);
            if (vcp[i]->endpos.x() > 0)
                p.drawLine(vcp[i]->pos.x(), vcp[i]->pos.y(), vcp[i]->endpos.x(), vcp[i]->endpos.y());
        }
        for (int j = 0; j < vcp[i]->planeNumber; j++) {
            text.append('\'');
        }
        p.drawText(QPoint(vcp[i]->pos.x() - 10, vcp[i]->pos.y() - 10), text);
    }
    for (int i = 0; i < help.size(); ++i) {
        pen.setColor(help[i].qpColor);
        pen.setBrush(help[i].qpColor);
        p.setPen(pen);
        QPainterPath path;
        if (help[i].objType == LINE) {
            pen.setWidth(3);
            p.setPen(pen);
            if (help[i].endpos.x() > 0)
                p.drawLine(help[i].pos.x(), help[i].pos.y(), help[i].endpos.x(), help[i].endpos.y());
        }
    }
    for (int i = 0; i < xMatch.size(); ++i) {
        pen.setColor(xMatch[i].qpColor);
        pen.setBrush(xMatch[i].qpColor);
        pen.setStyle(Qt::DashLine);
        pen.setWidth(5);
        p.setPen(pen);
        QPainterPath path;
        if (xMatch[i].objType == LINE) {
            pen.setWidth(3);
            p.setPen(pen);
            if (xMatch[i].endpos.x() > 0)
                p.drawLine(xMatch[i].pos.x(), xMatch[i].pos.y(), xMatch[i].endpos.x(), xMatch[i].endpos.y());
        }
        pen.setStyle(Qt::SolidLine);
    }
}

//обработка движения мыши
void Canvas::mouseMoveEvent(QMouseEvent *event) {
    QCursor c; //положение курсора мыши
    this->pos = event->pos();
    QRect rec = QGuiApplication::primaryScreen()->geometry();
    int scrHeight = rec.height();
    int scrWidth = rec.width();
    int xDefault = scrWidth / 4;
    int yDefault =  scrHeight * 556 / 10000 * 9/10 + QApplication::style()->pixelMetric(QStyle::PM_TitleBarHeight);
    if (!blocked) {
        int index = findInVcp(this->pos.x(), this->pos.y());
        if (index >= 0) {
            qp* temp = vcp[index];
            temp->qpColor = Qt::blue;
            selected = temp->objType;
            vcp.remove(index);
            vcp.append(temp);
            selectedIndex = vcp.size()-1;
        } else {
            selected = NOTHING;
            if (selectedIndex!=-1)
                if (!vcp[selectedIndex]->isSelected) vcp[selectedIndex]->qpColor=Qt::black;
            selectedIndex=-1;
        }
        //обновить экран
        this->update();
    } else {
        if ((event->pos().x() != xBlocked) && (xBlocked != -1)) {
            c.setPos(xDefault + parentWindow->pos().x() + xBlocked,
                     c.pos().y());
        }
        if (yBlocked == 2) {
            if (event->pos().y() < height() / 2) {
                if (xBlocked != -1) {
                    c.setPos(xDefault + xBlocked, yDefault + height() / 2);
                } else {
                    c.setPos(this->pos.x(), height() / 2);
                }
            }

        }
        if (yBlocked == 1) {
            if (event->pos().y() > height() / 2) {
                if (xBlocked != -1)
                    c.setPos(xDefault + parentWindow->pos().x() + xBlocked,
                             yDefault + parentWindow->pos().y() + height() / 2);
                else
                    c.setPos(xDefault + parentWindow->pos().x() + this->pos.x(),
                             yDefault + parentWindow->pos().y() + height() / 2);
            }
        }
        if ((condition == 2) && (vcp.last()->endpos.x() < 0)) {
            if (help.size() > 0) help.pop_back();
            qp qp1;
            qp1.pos = vcp.last()->pos;
            qp1.objType = LINE;
            qp1.qpColor = Qt::black;
            qp1.planeNumber = 0;
            qp1.endpos = this->pos;
            qp1.needsProjection = false;
            help.append(qp1);
            this->update();
        }
        if (xBlocked > 0) {
            if (xMatch.size() > 0) xMatch.pop_back();
            qp qp1;
            if (vcp.last()->objType == LINE) {
                if (vcp.last()->endpos.x() > 0)
                    qp1.pos = vcp.last()->pos;
                else
                    qp1.pos = vcp[vcp.size() - 2]->endpos;
            } else if (vcp.last()->objType == POINT) {
                qp1.pos = vcp.last()->pos;
            }
            qp1.objType = LINE;
            qp1.qpColor = Qt::gray;
            qp1.planeNumber = 0;
            qp1.endpos = this->pos;
            qp1.needsProjection = false;
            xMatch.append(qp1);
            this->update();
        }
    }
}

//нажатие кнопки мыши
void Canvas::mousePressEvent(QMouseEvent *e) {
    QCursor c;
    if (e->button() == Qt::LeftButton) {
        if (condition==0) {
            int index = findInVcp(this->pos.x(), this->pos.y());
            printf ("index = %d, size = %d", index, vcp.size());
            if (index >= 0) {
                if (vcp[index]->isSelected) {
                    vcp[index]->qpColor=Qt::black;
                    selectedObjects.remove(findInSelected(vcp[index]->pos.x(), vcp[index]->pos.y()));
                } else {
                    if (QGuiApplication::keyboardModifiers() & Qt::ShiftModifier) {
                        qp *temp = vcp[index];
                        temp->qpColor = Qt::blue;
                        temp->isSelected = true;
                        selectedObjects.append(temp);
                    } else {
                        if (!selectedObjects.empty()) {
                            for (int i = 0; i < selectedObjects.size(); i++) {
                                selectedObjects[i]->isSelected = false;
                                selectedObjects[i]->qpColor = Qt::black;
                            }
                            selectedObjects.clear();
                        }
                        qp *temp = vcp[index];
                        temp->qpColor = Qt::blue;
                        temp->isSelected = true;
                        selectedObjects.append(temp);
                    }
                }
            } else {
                printf ("\nsize = %d\n", selectedObjects.size());
                if (!selectedObjects.empty()) {
                  for (int i = 0; i < selectedObjects.size(); i++) {
                        selectedObjects[i]->isSelected = false;
                        selectedObjects[i]->qpColor = Qt::black;
                    }
                }
                selectedObjects.clear();
                this->update();
            }
        }
        if (condition == 1) {
            if (!blocked) {
                qp* qp1 = new qp;
                qp1->pos = this->pos;
                qp1->objType = POINT;
                qp1->qpColor = Qt::red;
                qp1->needsProjection = false;
                InputName inputNameWindow;
                inputNameWindow.exec();
                qp1->qpName = inputNameWindow.getInput();
                if (qp1->pos.y() < height() / 2) qp1->planeNumber = 2; else qp1->planeNumber = 1;
                vcp.append(qp1); //добавили в массив для рисования
                blocked = true;
                xBlocked = qp1->pos.x();
                yBlocked = qp1->planeNumber;
            } else {
                if (xMatch.size() > 0) xMatch.pop_back();
                qp* qp1 = new qp;
                qp1->pos = this->pos;
                qp1->objType = POINT;
                qp1->qpColor = Qt::black;
                qp1->needsProjection = false;
                vcp.back()->qpColor = Qt::black;
                qp1->qpName = vcp.back()->qpName;
                int y, z;
                if (yBlocked == 1) qp1->planeNumber = 2; else qp1->planeNumber = 1;
                if (qp1->planeNumber == 2) {
                    y = vcp.back()->pos.y() - height() / 2;
                    z = height() / 2 - qp1->pos.y();
                } else {
                    y = qp1->pos.y() - height() / 2;
                    z = height() / 2 - vcp.back()->pos.y();
                }
                qp1->projections.append(vcp.back());
                vcp.back()->projections.append(qp1);
                printf("I will add this point with coords %d %d %d", qp1->pos.x(), y, z);
                PTR<Entity> point(new PointByCoords(qp1->pos.x(), y, z));
                controllerObservable->onAddEntity(point);
                vcp.append(qp1);
                blocked = false;
            }
        }
        if (condition == 2) {
            if ((vcp.size() > 0) && (vcp.last()->needsProjection == true) && (blocked == true)) {
                if (vcp.last()->endpos.x() > 0) {
                    if (xMatch.size() > 0) xMatch.pop_back();
                    qp* qp1 = new qp;
                    qp1->pos = this->pos;
                    qp1->objType = LINE;
                    qp1->qpColor = Qt::red;
                    qp1->qpName = vcp.last()->qpName;
                    if (qp1->pos.y() < height() / 2) qp1->planeNumber = 1; else qp1->planeNumber = 2;
                    qp1->endpos = QPoint(-1, -1);
                    xBlocked = vcp.last()->endpos.x();
                    qp1->needsProjection = true;
                    vcp.append(qp1); //добавили в массив для рисования
                    blocked = true;
                    yBlocked = qp1->planeNumber;
                } else {
                    if (xMatch.size() > 0) xMatch.pop_back();
                    if (help.size() > 0) help.pop_back();
                    qp* qp1 = vcp.back();
                    vcp.pop_back();
                    vcp.back()->qpColor = Qt::black;
                    qp1->endpos = this->pos;
                    qp1->qpColor = Qt::black;
                    if (yBlocked == 1) qp1->planeNumber = 2; else qp1->planeNumber = 1;
                    qp1->projections.append(vcp.back());
                    vcp.back()->projections.append(qp1);
                    vcp.append(qp1);
                    qp1->needsProjection = false;
                    blocked = false;
                }
            } else {
                if (!blocked) {
                    qp* qp1 = new qp;
                    qp1->pos = this->pos;
                    qp1->objType = LINE;
                    qp1->qpColor = Qt::red;
                    InputName inputNameWindow;
                    inputNameWindow.exec();
                    qp1->qpName = inputNameWindow.getInput();
                    if (qp1->pos.y() < height() / 2) qp1->planeNumber = 1; else qp1->planeNumber = 2;
                    qp1->needsProjection = false;
                    qp1->endpos = QPoint(-1, -1);
                    vcp.append(qp1); //добавили в массив для рисования
                    blocked = true;
                    xBlocked = -1;
                    yBlocked = qp1->planeNumber;
                } else {
                    if (help.size() > 0) help.pop_back();
                    qp* qp1 = vcp.back();
                    vcp.pop_back();
                    qp1->endpos = this->pos;
                    if (yBlocked == 1) qp1->planeNumber = 2; else qp1->planeNumber = 1;
                    qp1->needsProjection = true;
                    vcp.append(qp1);
                    xBlocked = qp1->pos.x();
                    yBlocked = qp1->planeNumber;
                    blocked = true;
                }
            }
        } else if (condition == 3) {
            int index = findInVcp(this->pos.x(), this->pos.y());
            if (index >= 0) {
                if (vcp[index]->planeNumber == 2) {
                    if (vcp[index]->objType == POINT) {
                        projectStructureList->removePointFromXZPlaneStructure(vcp[index]->qpName);
                    } else if (vcp[index]->objType == LINE) {
                        projectStructureList->removeLineFromXZPlaneStructure(vcp[index]->qpName);
                    }
                } else if (vcp[index]->planeNumber == 1) {
                    if (vcp[index]->objType == POINT) {
                        projectStructureList->removePointFromXYPlaneStructure(vcp[index]->qpName);
                    } else if (vcp[index]->objType == LINE) {
                        projectStructureList->removeLineFromXYPlaneStructure(vcp[index]->qpName);
                    }
                }
                vcp.remove(index);
            }
            rRelated.exec();
            //обновить экран
            this->update();
        }
    }
}

//отпускание кнопки мыши
void Canvas::mouseReleaseEvent(QMouseEvent *e) {
    if (e->button() == Qt::RightButton) {
        QRect rec = QGuiApplication::primaryScreen()->geometry();;
        int scrHeight = rec.height() * 9 / 10;
        int scrWidth = rec.width();
        int xDefault = scrWidth / 4;
        int yDefault = scrHeight * 555 / 10000 + scrWidth * 35 / 1800;
        if (selected == POINT) {
            pointRMB.contextEditWidget->move(this->pos.x() + xDefault, this->pos.y() + yDefault);
            pointRMB.contextEditWidget->show();
        } else if (selected == LINE) {
            lineRMB.contextEditWidget->move(this->pos.x() + xDefault, this->pos.y() + yDefault);
            lineRMB.contextEditWidget->show();
        } else if ((selectedObjects.size()==2) && (selectedObjects[0]->objType==POINT) && (selectedObjects[1]->objType==POINT)) {
            twoPointsRMB.twoPointsContextEditWidget->move(this->pos.x() + xDefault, this->pos.y() + yDefault);
            twoPointsRMB.twoPointsContextEditWidget->show();
        } else if ( (selectedObjects.size()==2) &&
            (((selectedObjects[0]->objType == POINT) && (selectedObjects[1]->objType==LINE)) || ((selectedObjects[1]->objType == POINT) && (selectedObjects[0]->objType==LINE))) ) {
            printf ("\n uzbek=%d tadjik=%d\n", selectedObjects[0]->pos.x(), selectedObjects[1]->pos.y());
            pointAndLineRMB.pointAndLineContextEditWidget->move(this->pos.x() + xDefault, this->pos.y() + yDefault);
            pointAndLineRMB.pointAndLineContextEditWidget->show();
        }
        //удалить последний элемент линии
        /* */
    }
}

void Canvas::clear() {
    vcp.clear();
    projectStructureList->clear();
    help.clear();
    xMatch.clear();
    this->update();
}

