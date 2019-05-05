#ifndef TIMEVIEW_H
#define TIMEVIEW_H

#include <QWidget>
#include <QPen>
#include <QPainter>
#include <QBrush>
#include <QPoint>

class timeView : public QWidget
{
    Q_OBJECT
public:
    explicit timeView(QWidget *parent = nullptr);
    void mouseMoveEvent(QMouseEvent*);
    void resizeEvent(QResizeEvent* size);
    void paintEvent(QPaintEvent *);
signals:

public slots:
};

#endif // TIMEVIEW_H
