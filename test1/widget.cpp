#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    minesArea = new MinesArea;
    timeArea = new timeView;
    T = new timeT;
    buttonLayout = new QVBoxLayout;
    replayButton = new QPushButton(tr("replay"));
    replayButton->setMaximumSize(100,50);
    connect(replayButton, SIGNAL(clicked()), minesArea, SLOT(replay()));
    buttonLayout->addWidget(timeArea);
    buttonLayout->addWidget(replayButton);
    connect(T, SIGNAL(corn(double, int)), timeArea, SLOT(corn(double, int)));
    connect(minesArea, SIGNAL(flag(int)), timeArea, SLOT(flag(int)));
    connect(minesArea, SIGNAL(Tstart(int)), T, SLOT(Tstart(int)));

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


