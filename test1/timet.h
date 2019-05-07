#ifndef TIMET_H
#define TIMET_H

#include <QObject>
#include <QThread>

class timeT : public QThread
{
    Q_OBJECT
public:
    timeT();
signals:
    void corn(double, int);
public slots:
    void Tstart(int);
protected:
    void run();
private:
    const double PI = 3.141592653589;
    double i = 0;
    int j = 0;
    bool stop = false;
};

#endif // TIMET_H
