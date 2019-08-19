#include "widget.h"
#include "ui_widget.h"
#include <QVector>
#include <QMetaType>

typedef QVector<QVector<int>> QVectorint2;
typedef QVector<QVector<bool>> QVectorbool2;

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    qRegisterMetaType<QVectorint2> ("QVectorint2");
    qRegisterMetaType<QVectorbool2> ("QVectobool2");
    ui->setupUi(this);
    minesArea = new MinesArea;
    timeArea = new timeView;
    T = new timeT;
    AI = new AIControl(1);
    connect(AI, SIGNAL(getStatus()), minesArea, SLOT(returnStatus()));
    connect(AI, SIGNAL(setStatus(QVector<int>, bool)), minesArea, SLOT(setStatus(QVector<int>, bool)));
    connect(minesArea, SIGNAL(sendStop()), AI, SLOT(beStop()));
    connect(minesArea, SIGNAL(updateComplete()), AI, SLOT(updateComplete()));
    connect(minesArea, SIGNAL(sendStatus(QVector<QVector<int>>, QVector<QVector<bool>>, QVector<QVector<bool>>)), AI, SLOT(gainStatus(QVector<QVector<int>>, QVector<QVector<bool>>, QVector<QVector<bool>>)));
    buttonLayout = new QVBoxLayout;
    replayButton = new QPushButton(tr("replay"));
    replayButton->setMaximumSize(100, 50);
    autoButtion = new QPushButton(tr("auto"));
    autoButtion->setMaximumSize(100, 50);
    connect(autoButtion, SIGNAL(clicked()), AI, SLOT(start()));
    connect(replayButton, SIGNAL(clicked()), minesArea, SLOT(replay()));
    buttonLayout->addWidget(timeArea);
    buttonLayout->addWidget(autoButtion);
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


