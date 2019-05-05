#include "timeview.h"

timeView::timeView(QWidget *parent) : QWidget(parent)
{
    setMouseTracking(true);
    setAutoFillBackground(true);
}

void timeView::paintEvent(QPaintEvent *)
{
    QPen pen(Qt::white);
    QBrush brush(Qt::white);
    QPainter p(this);
    p.setPen(pen);
    p.setBrush(brush);
    p.drawRect(0, 0, height(), width());
}

void timeView::mouseMoveEvent(QMouseEvent *)
{

}

void timeView::resizeEvent(QResizeEvent *size)
{

}
