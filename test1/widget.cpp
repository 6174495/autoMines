#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    minesArea = new MinesArea;
    buttonLayout = new QVBoxLayout;
    replayButton = new QPushButton(tr("replay"));
    replayButton->setMaximumSize(100,50);
    connect(replayButton, SIGNAL(clicked()), minesArea, SLOT(replay()));
    buttonLayout->addWidget(replayButton);
    buttonLayout->setMargin(10);
    QHBoxLayout *mainLayout = new QHBoxLayout;
    mainLayout->addWidget(minesArea);
    mainLayout->addLayout(buttonLayout);
    mainLayout->setStretchFactor(minesArea, 0);
    mainLayout->setStretchFactor(buttonLayout, 1);
    setLayout(mainLayout);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::resizeEvent(QResizeEvent *size)
{
    minesArea->pressPos.setX(0);
    minesArea->pressPos.setY(0);
    minesArea->movePos.setX(0);
    minesArea->movePos.setY(0);
    minesArea->rightPressPos.setX(0);
    minesArea->rightPressPos.setY(0);
    minesArea->update();
}
