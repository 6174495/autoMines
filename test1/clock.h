#ifndef CLOCK_H
#define CLOCK_H

#include <QObject>
#include <QThread>

class clock : public QObject
{
    Q_OBJECT
public:
    explicit clock(QObject *parent = nullptr);
protected:

signals:

public slots:
};

#endif // CLOCK_H
