#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <minesarea.h>
#include <timeview.h>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>


namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private:
    Ui::Widget *ui;
    MinesArea *minesArea;
    timeView *timeArea;
    QVBoxLayout *buttonLayout;
    QPushButton *replayButton;
};

#endif // WIDGET_H
