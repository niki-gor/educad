#include "canvas.h"
#include "QPicture"
#include "QLabel"
#include <math.h>
#include <QBrush>
#include "QBoxLayout"
#include "QPushButton"
#include "QCursor"
#include "QPainterPath"


void Canvas::addPoint(int x, int y, QString name) {
    qp qp1;
    qp1.pos = QPoint (x,y);
    qp1.fl = 0;
    qp1.objType = POINT;
    qp1.qpColor=Qt::black;
    qp1.needsProjection=false;
    qp1.qpName=name;
    qp1.planeNumber=1;
    vcp.append(qp1); //добавили в массив для рисования
    this->update();
}

void Canvas::addLine(int x1, int y1, int x2, int y2, QString name) {
    qp qp1;
    qp1.pos = this->pos;
    qp1.pos = QPoint (x1,y1);
    qp1.endpos =  QPoint (x2,y2);
    qp1.fl = 0;
    qp1.objType = LINE;
    qp1.qpColor=Qt::black;
    qp1.needsProjection=false;
    qp1.qpName=name;
    qp1.planeNumber=1;
    vcp.append(qp1); //добавили в массив для рисования
    this->update();
}

 InputName:: InputName( QWidget* parent ) : QDialog( parent ) {
    QBoxLayout* layout = new QHBoxLayout;
    m_edit = new QLineEdit;
    layout->addWidget( m_edit );

    QPushButton* okBtn = new QPushButton( "OK" );
    connect( okBtn, SIGNAL( clicked() ), SLOT( accept() ) );
    layout->addWidget( okBtn );

    setLayout( layout );
}

int Canvas::findInVcp (int x, int y) {
    for (int i = 0; i < vcp.size(); ++i) {
        if (  ( (vcp[i].pos.x() >= x - 4) && (vcp[i].pos.x() <= x + 4) )
                && ((vcp[i].pos.y() >= y - 4) && (vcp[i].pos.y() <= y + 4)) ) {
            return i;
        }
    }
    return -1;
}

Canvas::Canvas(QWidget* parent, QMainWindow* _parent, ProjectStructureList* _projectStructureList) : QWidget(parent)
{
    LineContextEdit lineRMB;
    PointContextEdit pointRMB;
    projectStructureList = _projectStructureList;
    condition=0;
    parentWindow=_parent;
    this->resize(1000,600);
    QPalette pl; //объект палитра необходим для заданимя фона окна
    pl.setColor(QPalette::Background, QColor(255, 255, 255)); //определить цвет
    this->setAutoFillBackground(true); //фон окна заливается автоматически
    this->setPalette(pl); //устанавливаем фон окна
    selected=NOTHING;
    this->setMouseTracking(true);
    f = 0;
}

void Canvas::paintEvent(QPaintEvent *event)
{
    QBrush brush;
    brush.setColor(Qt::black);
    QPainter p(this);
    pen.setStyle(Qt::SolidLine);
    pen.setWidth(2);
    pen.setBrush(Qt::black);
    p.setPen (pen);
    int xAxisX1 = width()-10;
    int xAxisY1 = height()/2;
    int xAxisX2 = 10;
    int xAxisY2 = height()/2;
    p.drawLine(xAxisX1, xAxisY1, xAxisX2, xAxisY2);
    p.drawLine(xAxisX2, xAxisY2, xAxisX2+5, xAxisY2-5);
    p.drawLine(xAxisX2, xAxisY2, xAxisX2+5, xAxisY2+5);
    QFont font ("Times", 16);
    p.setFont(font);
    p.drawText(QPoint(xAxisX2+10,xAxisY2-10), "X");
    int yzAxisX1 = width()-10;
    int yzAxisY1 = 10;
    int yzAxisX2 = width()-10;
    int yzAxisY2 = height()-10;
    p.drawLine(yzAxisX1, yzAxisY1, yzAxisX2, yzAxisY2);
    p.drawLine(yzAxisX1, yzAxisY1, yzAxisX1-5, yzAxisY1+5);
    p.drawLine(yzAxisX1, yzAxisY1, yzAxisX1+5, yzAxisY1+5);
    p.drawLine(yzAxisX2-5, yzAxisY2-5, yzAxisX2, yzAxisY2);
    p.drawLine(yzAxisX2+5, yzAxisY2-5, yzAxisX2, yzAxisY2);
    p.drawText(QPoint(yzAxisX1-20,yzAxisY1+25), "Z");
    p.drawText(QPoint(yzAxisX2-20,yzAxisY2-10), "Y");
    p.setBrush(Qt::black);
    pen.setWidth(10);
    p.setPen(pen);
    for (int i = 0; i < vcp.size(); ++i)
    {
        QString text = vcp[i].qpName;
        pen.setColor(vcp[i].qpColor);
        pen.setBrush(vcp[i].qpColor);
        p.setPen(pen);
        QPainterPath path;

        if (vcp[i].objType==POINT) {
            pen.setWidth(10);
            p.setPen(pen);
        p.drawEllipse(vcp[i].pos.x(), vcp[i].pos.y(), 4, 4);
        p.fillPath(QPainterPath(QPoint(vcp[i].pos.x(), vcp[i].pos.y())), p.brush());
        if (vcp[i].planeNumber==1)
            projectStructureList->addPointToXZPlaneStructure(vcp[i].qpName);
        if (vcp[i].planeNumber==2)
            projectStructureList->addPointToXYPlaneStructure(vcp[i].qpName);
        }
        if (vcp[i].objType==LINE) {
            pen.setWidth(3);
            p.setPen(pen);
            if (vcp[i].endpos.x()>0)
            p.drawLine(vcp[i].pos.x(), vcp[i].pos.y(), vcp[i].endpos.x(), vcp[i].endpos.y());
        //if (vcp[i].planeNumber==1)
        //    projectStructureList->addPointToXZPlaneStructure(vcp[i].qpName);
       // if (vcp[i].planeNumber==2)
        //    projectStructureList->addPointToXYPlaneStructure(vcp[i].qpName);
        }
        for (int j=0;j<vcp[i].planeNumber; j++) {
            text.append('\'');
        }
        p.drawText(QPoint(vcp[i].pos.x()-10, vcp[i].pos.y()-10), text);
    }
}
//обработка движения мыши
void Canvas::mouseMoveEvent(QMouseEvent *event)
{
    QCursor c; //положение курсора мыши
    this->pos = event->pos();
    if (!blocked) {
        int index=findInVcp(this->pos.x(), this->pos.y());
        if (index>=0) {
            qp temp = vcp[index];
            temp.qpColor = Qt::blue;
            selected = temp.objType;
            vcp.remove(index);
            vcp.append(temp);
        } else {
            selected=NOTHING;
            for (int i = 0; i < vcp.size(); ++i) {
                if (vcp[i].qpColor==Qt::blue) vcp[i].qpColor=Qt::black;
            }
        }
        //обновить экран
        this->update();
    } else {
        if ((event->pos().x()!=xBlocked) && (xBlocked!=-1)) {
            printf ("\nban\n");
            c.setPos(267+parentWindow->pos().x()+xBlocked, 90+parentWindow->pos().y() + event->pos().y());
        }
        if (yBlocked==2) {
                if (event->pos().y()<height()/2) {
                    if (xBlocked!=-1)
                        c.setPos(267+parentWindow->pos().x()+xBlocked, 90+parentWindow->pos().y() + height()/2);
                    else
                        c.setPos(267+parentWindow->pos().x()+this->pos.x(), 90+parentWindow->pos().y() + height()/2);
                }

        }
        if (yBlocked==1) {
            if (event->pos().y()>height()/2) {
                 if (xBlocked!=-1)
                c.setPos(267+parentWindow->pos().x()+xBlocked, 90+parentWindow->pos().y() + height()/2);
                 else
                     c.setPos(267+parentWindow->pos().x()+this->pos.x(), 90+parentWindow->pos().y() + height()/2);
            }
        }
    }
}

//нажатие кнопки мыши
void Canvas::mousePressEvent(QMouseEvent * e)
{
    QCursor c;
    if(e->button() == Qt::LeftButton) {
        printf ("condition=%d\n", condition);
        if (condition==1) {
                if (!blocked) {
                qp qp1;
                qp1.pos = this->pos;
                qp1.fl = 0;
                qp1.objType = POINT;
                qp1.qpColor=Qt::red;
                qp1.needsProjection=false;
                InputName inputNameWindow;
                inputNameWindow.exec();
                qp1.qpName=inputNameWindow.getInput();
                if (qp1.pos.y()<height()/2) qp1.planeNumber=2; else qp1.planeNumber=1;
                vcp.append(qp1); //добавили в массив для рисования
                blocked=true;
                xBlocked = qp1.pos.x();
                yBlocked = qp1.planeNumber;

                }
            else {
                 qp qp1;
                 qp1.pos = this->pos;
                 qp1.fl = 0;
                 qp1.objType = POINT;
                 qp1.qpColor=Qt::black;
                 qp1.needsProjection=false;
                 vcp.back().qpColor=Qt::black;
                 qp1.qpName = vcp.back().qpName;
                 if (yBlocked == 1) qp1.planeNumber =2; else qp1.planeNumber = 1;
                 vcp.append(qp1);
                 blocked = false;
                 }
             }
             if (condition==2) {
                 if ( (vcp.size()>0) && (vcp.last().needsProjection==true) && (blocked==true)) {
                     if (vcp.last().endpos.x()>0) {
                     qp qp1;
                     qp1.pos = this->pos;
                     qp1.fl = 0;
                     qp1.objType=LINE;
                     qp1.qpColor=Qt::red;
                     qp1.qpName=vcp.last().qpName;
                     if (qp1.pos.y()<height()/2) qp1.planeNumber=1; else qp1.planeNumber=2;
                     qp1.endpos = QPoint (-1, -1);
                     xBlocked = vcp.last().endpos.x();
                      qp1.needsProjection=true;
                     vcp.append(qp1); //добавили в массив для рисования
                     blocked=true;
                     yBlocked = qp1.planeNumber;
                     } else {
                       qp qp1 = vcp.back();
                       vcp.pop_back();
                       vcp.back().qpColor=Qt::black;
                       qp1.endpos = this->pos;
                       qp1.qpColor=Qt::black;
                       if (yBlocked == 1) qp1.planeNumber = 2; else qp1.planeNumber = 1;
                       vcp.append(qp1);
                       qp1.needsProjection=false;
                       blocked = false;
                       }
                 } else {
                 if (!blocked) {
                 qp qp1;
                 qp1.pos = this->pos;
                 qp1.fl = 0;
                 qp1.objType=LINE;
                 qp1.qpColor=Qt::red;
                 InputName inputNameWindow;
                 inputNameWindow.exec();
                 qp1.qpName=inputNameWindow.getInput();
                 if (qp1.pos.y()<height()/2) qp1.planeNumber=1; else qp1.planeNumber=2;
                 qp1.endpos = QPoint (-1, -1);
                 vcp.append(qp1); //добавили в массив для рисования
                 blocked=true;
                 xBlocked = -1;
                 yBlocked = qp1.planeNumber;
                 qp1.needsProjection=false;
                 } else {
                   qp qp1 = vcp.back();
                   vcp.pop_back();
                   qp1.endpos = this->pos;
                   if (yBlocked == 1) qp1.planeNumber =2; else qp1.planeNumber = 1;
                    qp1.needsProjection=true;
                   vcp.append(qp1);
                   xBlocked = qp1.pos.x();
                   yBlocked = qp1.planeNumber;
                   blocked = true;
                   }
            }
             }
    }
}
//отпускание кнопки мыши
void Canvas::mouseReleaseEvent(QMouseEvent * e)
{
    if(e->button() == Qt::RightButton)
    {
        if (selected==POINT) {
            pointRMB.contextEditWidget.show();
        } else if (selected==LINE) {
            lineRMB.contextEditWidget.show();
        }
        //удалить последний элемент линии
       /* int index=findInVcp(this->pos.x(), this->pos.y());
        if (index>=0) {
            vcp.remove(index);
        }
        //обновить экран
        this->update();*/
    }
}

