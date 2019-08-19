#include "autoai.h"
#include "cmath"

autoAI::autoAI()
{

}

QVector<int> autoAI::nextPress(QVector<QVector<int>> mines, QVector<QVector<bool>> isPress, QVector<QVector<bool>> isFlag){
    QVector<int> predict(2);
    int sizeX = isPress.size();
    int sizeY = isPress.size();
    //如果没有格子被按下
    if(unPressJudge(isPress)){
        predict[0] = rand() % sizeX;
        predict[1] = rand() % sizeY;
        return predict;
    }

    return predict;
}

bool autoAI::unPressJudge(QVector<QVector<bool>> &isPress){
    bool result = true;
    for(int i=0;i<isPress.size();i++){
        for(int j=0;j<isPress[0].size();j++){
            if(isPress[i][j]) result = false;
        }
    }
    return result;
}
