#ifndef MINESAREA_H
#define MINESAREA_H

#include <QWidget>
#include <QPen>
#include <QPainter>
#include <QBrush>
#include <QPoint>
#include <QMouseEvent>
#include <QVector>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <QString>
#include <QColor>
#include <cmath>

class MinesArea : public QWidget
{
    Q_OBJECT
public:
    explicit MinesArea(QWidget *parent = nullptr);
    void mouseMoveEvent(QMouseEvent*);
    void mousePressEvent(QMouseEvent*);
    void paintEvent(QPaintEvent *);
    QPoint movePos;
    QPoint pressPos;
    QPoint rightPressPos;
signals:

public slots:
private:
    QVector<QVector<int>> minesNum;
    int minesSum;
    bool initFlat = true;
    int firstPress = -1;
    QVector<QVector<bool>> isPressed;
    QVector<QVector<bool>> isFlag;
    void init();
    void swap(int &a, int &b);
    void zeroBeIsPress(int i, int j);
};

#endif // MINESAREA_H
