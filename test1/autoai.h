#ifndef AUTOAI_H
#define AUTOAI_H

#include <QVector>


class autoAI
{
public:
    autoAI();
    QVector<int> nextPress(QVector<QVector<int>>, QVector<QVector<bool>>, QVector<QVector<bool>>);
private:
    bool unPressJudge(QVector<QVector<bool>>&);
};

#endif // AUTOAI_H
