#include "canvas.h"

Canvas::Canvas(QWidget *parent) : QWidget(parent)
{
    imCreated = false;
        QPainter painter(this); painter.drawText(0,0, "sus");
}

void Canvas::paintEvent(QPaintEvent *)
{
    if (imCreated)
    {
        QPainter painter(this);
        painter.drawImage(0, 0, im);
    }
}

void Canvas::createImage(int width, int height)
{
    im = QImage(width, height, QImage::Format_ARGB32_Premultiplied);
    im.fill(0);
    imCreated = true;
}
