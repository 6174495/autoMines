#ifndef TIMEVIEW_H
#define TIMEVIEW_H

#include <QWidget>
#include <QPen>
#include <QPainter>
#include <QBrush>
#include <QPoint>
#include "timethread.h"
#include <cmath>
#include <QString>
#include <QPoint>

class timeView : public QWidget
{
    Q_OBJECT
public:
    explicit timeView(QWidget *parent = nullptr);
    void mouseMoveEvent(QMouseEvent*);
    void paintEvent(QPaintEvent *);
signals:

public slots:
    void corn(double, int);
    void flag(int);
private:
    double angle = 0;
    int time = 0;
    int flagCount = 0;
};

#endif // TIMEVIEW_H
