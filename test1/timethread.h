#ifndef TIMETHREAD_H
#define TIMETHREAD_H

#include <QThread>
#include <QObject>


class timeThread : public QThread
{
    Q_OBJECT

public:
    timeThread();

signals:
    void corns(int){}

protected:
    void run();
};

#endif // TIMETHREAD_H
