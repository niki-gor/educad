#include "canvas.h"

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