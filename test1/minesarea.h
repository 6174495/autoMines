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
#include <QObject>

class MinesArea : public QWidget
{
    Q_OBJECT
public:
    explicit MinesArea(QWidget *parent = nullptr);
    void mouseMoveEvent(QMouseEvent*);
    void mousePressEvent(QMouseEvent*);
    void resizeEvent(QResizeEvent* size);
    void paintEvent(QPaintEvent *);
    QVector<QVector<int>> getMines(){return minesNum;}
    QVector<QVector<bool>> getIsPressed(){return isPressed;}
    QVector<QVector<bool>> getIsFlag(){return isFlag;}
    QPoint movePos;
    QPoint pressPos;
    QPoint rightPressPos;
signals:
    void flag(int);
    void Tstart(int);
    void sendStatus(QVector<QVector<int>> mines, QVector<QVector<bool>> isPress, QVector<QVector<bool>> isFlag);
    void sendStop();
    void updateComplete();

public slots:
    void replay();
    void returnStatus();
    void setStatus(QVector<int>, bool);

private:
    QVector<QVector<int>> minesNum;
    int minesSum;
    bool initFlat = true;
    bool isWin = false;
    int gameOver = -1;
    int firstPress = -1;
    int flagSum = 0;
    QVector<QVector<bool>> isPressed;
    QVector<QVector<bool>> isFlag;
    void init();
    void swap(int &a, int &b);
    void zeroBeIsPress(int i, int j);
    QVector<int> getAttr();
};

#endif // MINESAREA_H
