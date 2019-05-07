#include "timeview.h"


timeView::timeView(QWidget *parent) : QWidget(parent)
{
    setMouseTracking(true);
    setAutoFillBackground(true);
    setMaximumSize(100, 200);
    setMinimumSize(100, 200);
}

void timeView::paintEvent(QPaintEvent *)
{
    QPen blackPen(Qt::black);
    QBrush whiteBrush(Qt::white);
    QBrush blackBrush(Qt::black);
    blackPen.setWidth(5);
    blackPen.setCapStyle(Qt::RoundCap);
    QPainter p(this);
    p.setRenderHint(QPainter::Antialiasing, true);
    int h = height();
    int w = width();
    p.setPen(blackPen);
    p.setBrush(whiteBrush);
    p.drawEllipse(w/2-20, h/8-20, 40, 40);
    blackPen.setWidth(3);
    p.setPen(blackPen);
    p.drawLine(w/2, h/8, w/2+13*sin(angle),h/8-13*cos(angle));
    char hour10 = char(time/600+48);
    char hour = char(time/60+48);
    char min10 = char(time%60/10+48);
    char min = char(time%60%10+48);
    char t[6] = {hour10, hour, ':', min10, min, '\0'};
    p.drawText(w/2-18, h/4+22, t);

    QPoint tri[3] =  {QPoint(w/2-10, h/2), QPoint(w/2-10, h/2+20), QPoint(w/2+15,h/2+5)};
    p.setBrush(blackBrush);
    p.drawLine(QPoint(w/2-10, h/2),QPoint(w/2-10, h/2+30));
    blackPen.setWidth(0);
    p.setPen(blackPen);
    p.drawPolygon(tri, 3);
    char flag10 = char(flagCount / 10+48);
    char flag1 = char(flagCount % 10+48);
    char f[6] = {flag10, flag1, '/', '9', '9'};
    p.drawText(w/2-18, h/2+60, f);
}

void timeView::mouseMoveEvent(QMouseEvent *)
{

}

void timeView::corn(double c, int j){
    angle = c;
    time = j;
    update();
}

void timeView::flag(int t)
{
    flagCount = t;
    update();
}
