#ifndef AICONTROL_H
#define AICONTROL_H
#include <QThread>
#include <QVector>
#include <QObject>

typedef QVector<QVector<int>> QVectorint2;
typedef QVector<QVector<bool>> QVectorbool2;

class AIControl : public QThread
{
    Q_OBJECT
public:
    AIControl(double sleep);
private:
    double sleepTime;
    bool isUpdate = false;
    bool isRe = false;
    QVectorint2 mines;
    QVectorbool2 isPress;
    QVectorbool2 isFlag;
    QVector<int> nextPress();                           //核心函数，预测下一个操作
    bool isUnPressJudge(QVector<QVector<bool>>&);       //是否第一次按下
    QVector<int> possible();                            //最终无法判断时，概率学
    QVectorint2 getSetUnKnowPoss();                     //未知空间格子集合
    QVector<int> flat_1();                              //一阶插旗判定
    QVector<int> click_1();                             //一阶点击判定
    QVector<int> level_2();                             //二阶判定
    int getNumUnPress(int, int);                        //周围未被按下的格子数,含旗子
    int getNumUnPressNoFlat(int, int);                  //周围未被按下的格子数,不含旗子
    QVectorint2 getSetUnPressNoFlat(int ,int);          //周围未被按下的格子集合，不含旗子
    QVector<int> ranChooseNoFlat(int, int);             //随机周围一个没有被插旗子的格子
    int contentArea(QVectorint2, QVectorint2);          //区域包含判定
    QVector<QVectorint2> getNoMergeArea(QVectorint2, QVectorint2);//返回区域非交集部分
    bool isEdge(int, int);                              //是否边缘格子
    int getMinesNoFlat();                               //获取总雷数
    int getEdgeMines();                                 //获取边缘雷数
    int getFlat(int, int);                              //获取周围旗子数
    int min(QVector<double>);                           //获取最小值坐标
    int getX();                                         //棋盘第一维度大小
    int getY();                                         //棋盘第二维度大小
    int abs(int);                                       //绝对值

protected:
    void run();
signals:
    void getStatus();
    void setStatus(QVector<int>, bool); //布尔值，true代表press, false代表flag
public slots:
    void gainStatus(QVector<QVector<int>> mines, QVector<QVector<bool>> isPress, QVector<QVector<bool>> isFlag){
        this->mines = mines;
        this->isPress = isPress;
        this->isFlag = isFlag;
        isRe = true;
    }
    void beStop(){
        this->terminate();
    }
    void updateComplete(){
        isUpdate = true;
    }
};

#endif // AICONTROL_H
