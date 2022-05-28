#include "canvas.h"

void Canvas::mouseMoveEvent(QMouseEvent *event) {
    QCursor c; //положение курсора мыши
    this->pos = event->pos();
    QRect rec = QGuiApplication::primaryScreen()->geometry();
    int scrHeight = rec.height();
    int scrWidth = rec.width();
    int xDefault = scrWidth / 4;
    int yDefault = scrHeight * 556 / 10000 * 9 / 10 + QApplication::style()->pixelMetric(QStyle::PM_TitleBarHeight);
    if (!blocked) {
        int index = findInVcp(this->pos.x(), this->pos.y());
        if (index >= 0) {
            qp *temp = vcp[index];
            temp->qpColor = Qt::blue;
            selected = temp->objType;
            vcp.remove(index);
            vcp.append(temp);
            selectedIndex = vcp.size() - 1;
        } else {
            selected = NOTHING;
            if (selectedIndex != -1)
                if (!vcp[selectedIndex]->isSelected) {
                    if (vcp[selectedIndex]->needsProjection)
                        vcp[selectedIndex]->qpColor = Qt::red;
                    else
                        vcp[selectedIndex]->qpColor = Qt::black;
                }
            selectedIndex = -1;
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


