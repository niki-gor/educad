#include "canvas.h"
#define EPS 1000

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
    std::get<0>(result) = startPoint;
    std::get<1>(result) = endPoint;
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
    PTR<ProjectionPlane> plane;
    PTR<TwoDPoint> twoDLineBegin;
    PTR<TwoDPoint> twoDLineEnd;
    twoDLineBegin = std::make_shared<TwoDPoint>(x1, y1, plane);
    twoDLineEnd = std::make_shared<TwoDPoint>(x2, y2, plane);
    if (planeNumber==1) {
        y1 = canvasBegin.y() + y1;
        y2 = canvasBegin.y() + y2;
    } else {
        y1 = canvasBegin.y() - y1;
        y2 = canvasBegin.y() - y2;
    }
    PTR<TwoDEntity> twoDLine (new TwoDLine(twoDLineBegin, twoDLineEnd, plane));
    qp1->objectEntity = twoDLine;
    x1 = canvasBegin.x()-x1;
    x2 = canvasBegin.x()-x2;
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
        if (vcp[i]->objType==LINE) {
            PTR<TwoDLine> currLine = std::dynamic_pointer_cast<TwoDLine>(vcp[i]->objectEntity);
            int newY; int newX=width()-x-10;
            if (this->pos.y()<height()/2) newY = height()/2-y; else newY = y-height()/2;
            if ((abs(currLine->getA()*newX+currLine->getB()*newY+currLine->getC()) - EPS) <= 0) {
                return i;
            }
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

void Canvas::deletePoint(int x, int y, int xBegin, int yBegin, int planeNumber, std::string name) {
    x = canvasBegin.x() - x;
    if (planeNumber==1) {
        y = canvasBegin.y() + y;
    }  else {
        y -= canvasBegin.y();
    }
    for (int i=0; i<vcp.size(); i++) {
        if (vcp[i]->pos == QPoint (x,y)) {
            vcp.erase(vcp.begin()+i);
        }
    }
}

void Canvas::deleteLine(int x1, int y1, int x2, int y2, int xBegin, int yBegin, int planeNumber, std::string name) {
    x1 = canvasBegin.x() - x1;
    x2 = canvasBegin.x() - x2;
    if (planeNumber==1) {
        y1 = canvasBegin.y() + y1;
        y2 = canvasBegin.y() + y2;
    }  else {
        y1 -= canvasBegin.y();
        y2 -= canvasBegin.y();
    }
    for (int i=0; i<vcp.size(); i++) {
        if ((vcp[i]->pos == QPoint (x1,y1)) && ((vcp[i]->pos == QPoint (x2,y2)))) {
            vcp.erase(vcp.begin()+i);
        }
    }
}
