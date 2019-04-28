#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <minesarea.h>
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
    void resizeEvent(QResizeEvent* size);

private:
    Ui::Widget *ui;
    MinesArea *minesArea;
    QVBoxLayout *buttonLayout;
    QPushButton *replayButton;
};

#endif // WIDGET_H
