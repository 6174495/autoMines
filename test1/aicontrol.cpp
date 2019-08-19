#include "aicontrol.h"
#include <QDebug>
#include <QSet>

AIControl::AIControl(double sleep){
    sleepTime = sleep; isRe = false;
}

void AIControl::run(){
    QVector<int> predict(3);
    QVector<int> send(2);
    while(true){
        isRe = false;
        isUpdate = false;
        emit getStatus();
        while(!isRe){
            usleep(1);
        }
        predict = nextPress();
        send[0] = predict[0];
        send[1] = predict[1];
        if(predict[2]==0)   //0是左键press
            emit setStatus(send, true);
        else if(predict[2]==1)
            emit setStatus(send, false);
        while(!isUpdate){
            usleep(1);
        }
        msleep(sleepTime);
    }
}

QVector<int> AIControl::nextPress(){
    QVector<int> predict(3);
    QVector<int> preP(3);
    int sizeX = isPress.size();
    int sizeY = isPress[0].size();

    //如果没有格子被按下
    if(isUnPressJudge(isPress)){
        predict[0] = rand() % sizeX;
        predict[1] = rand() % sizeY;
        predict[2] = 0;
        return predict;
    }

    //标旗判定 1阶,只考虑已经点开的数字和它周围格子情况
    preP = flat_1();
    if(preP[0] != -1){
        predict = preP;
        return predict;
    }

    //点击判定 1阶，只考虑已经点开的数字和它周围格子情况
    preP = click_1();
    if(preP[0] != -1){
        predict = preP;
        return predict;
    }

    //二阶判定
    preP = level_2();
    if(preP[0] != -1){
        predict = preP;
        return predict;
    }

    //无法判断时，概率学
    preP = possible();
    if(preP[0] != -1){
        predict = preP;
        return predict;
    }

    return predict;
}

//二阶判定
QVector<int> AIControl::level_2(){
    int sizeX = getX();
    int sizeY = getY();
    QVector<int> result(3, -1);
    result[2] = 0;
    bool isFind = false;
    QVector<QVectorint2> area;
    QVector<int> minesNum;
    for(int i=0;i<sizeX;i++)
        for(int j=0;j<sizeY;j++){
            if(isPress[i][j]&&!isFind&&mines[i][j]>0&&getNumUnPressNoFlat(i, j)>0){
                QVectorint2 oneArea = getSetUnPressNoFlat(i, j);
                int oneMinesNum = mines[i][j] - getFlat(i, j);
                area.push_back(oneArea);
                minesNum.push_back(oneMinesNum);
            }
        }
    for(int i=0;i<area.size();i++)
        for(int j=i+1;j<area.size();j++){
            if(!isFind){
                //计算各种情况
                QVector<QVectorint2> mergeArea = getNoMergeArea(area[i], area[j]);
                if(mergeArea.size()<=1) continue;
                QVectorint2 m0,m1;
                if(mergeArea[0].size()>=1){
                    for(int i=1;i<mergeArea[0].size();i++)
                        m0.push_back(mergeArea[0][i]);
                }
                if(mergeArea[1].size()>=1){
                    for(int i=1;i<mergeArea[1].size();i++)
                        m1.push_back(mergeArea[1][i]);
                }

                int size0 = m0.size();
                int size1 = m1.size();

                //区域没有交集,直接跳过
                if(size0 == area[i].size()) continue;

                //区域重叠，跳过
                if(size0==0 && size1==0) continue;

                //一个区域包含另一个区域
                if(size0==0 && size1>0){
                    if(minesNum[j] - minesNum[i] == size1){
                        int re = rand() % size1;
                        result[0] = m1[re][0];
                        result[1] = m1[re][1];
                        result[2] = 1;
                        return result;
                    }
                    if(minesNum[j] == minesNum[i]){
                        int re = rand() % size1;
                        result[0] = m1[re][0];
                        result[1] = m1[re][1];
                        result[2] = 0;
                        return result;
                    }
                }
                if(size0>0 && size1==0){
                    if(minesNum[i] - minesNum[j] == size0){
                        int re = rand() % size1;
                        result[0] = m0[re][0];
                        result[1] = m0[re][1];
                        result[2] = 1;
                        return result;
                    }
                    if(minesNum[j] == minesNum[i]){
                        int re = rand() % size0;
                        result[0] = m0[re][0];
                        result[1] = m0[re][1];
                        result[2] = 0;
                        return result;
                    }
                }

                //有交集也有独立区域
                if(size0>0 && size1>0){
                    if(minesNum[i] - minesNum[j] == size0){
                        int re = rand() % size0;
                        result[0] = m0[re][0];
                        result[1] = m0[re][1];
                        result[2] = 1;
                        return result;
                    }
                    if(minesNum[j] - minesNum[i] == size1){
                        int re = rand() % size1;
                        result[0] = m1[re][0];
                        result[1] = m1[re][1];
                        result[2] = 1;
                        return result;
                    }
                }
            }
        }
    return result;
}

//标旗判定 1阶
QVector<int> AIControl::flat_1(){
    int sizeX = getX();
    int sizeY = getY();
    QVector<int> result(3, -1);
    result[2] = 1;
    bool isFind = false;
    for(int i=0;i<sizeX;i++)
        for(int j=0;j<sizeY;j++){
            if(isPress[i][j]&&!isFind&&!isFlag[i][j]){
                if(getNumUnPressNoFlat(i, j) == mines[i][j]-getFlat(i, j) && mines[i][j]-getFlat(i, j)>0){
                    QVector<int> q = ranChooseNoFlat(i, j);
                    if(q.size()>0){
                        result[0] = q[0];
                        result[1] = q[1];
                        return result;
                    }
                }
            }
        }
    return result;
}

//点击判定 1阶
QVector<int> AIControl::click_1(){
    int sizeX = getX();
    int sizeY = getY();
    QVector<int> predict(3, -1);
    predict[2] = 0;
    bool isFind = false;
    for(int i=0;i<sizeX;i++)
        for(int j=0;j<sizeY;j++){
            if(isPress[i][j]&&!isFlag[i][j]&&mines[i][j]>0){
                if(mines[i][j] == getFlat(i, j)&& getNumUnPressNoFlat(i,j)>0 && !isFind){
                    predict[0] = i;
                    predict[1] = j;
                    return predict;
                }
            }
        }
    return predict;
}

//概率判定
QVector<int> AIControl::possible(){
    QVector<int> res(3, -1);
    QVector<QVectorint2> area;
    QVector<double> areaPoss;

    //未知空间地雷概率
    QVectorint2 unKnowPoss = getSetUnKnowPoss();
    if(unKnowPoss.size()>0){
        area.push_back(getSetUnKnowPoss());
        areaPoss.push_back((getMinesNoFlat() - getEdgeMines()) / unKnowPoss.size()*2);
    }

    //边缘地带地雷概率
    int sizeX = getX();
    int sizeY = getY();
    for(int i=0;i<sizeX;i++)
        for(int j=0;j<sizeY;j++){
            if(isPress[i][j]&&mines[i][j]-getFlat(i, j)>0){
                QVectorint2 set = getSetUnPressNoFlat(i, j);
                int minesNum = mines[i][j] - getFlat(i, j);
                area.push_back(set);
                areaPoss.push_back(minesNum/set.size());
            }
        }

    //找出最小值来
    if(area.size()>0){
        int local = min(areaPoss);
        QVectorint2 local2 = area[local];
        int local3 = rand() % local2.size();
        res[0] = local2[local3][0];
        res[1] = local2[local3][1];
        res[2] = 0;
    }

    return res;
}

//区域包含判定
int AIControl::contentArea(QVectorint2 a, QVectorint2 b){
    int count = 0;
    for(int i=0;i<a.size();i++)
        for(int j=0;j<b.size();j++){
            if(a[i][0]==b[j][0] && a[i][1]==b[j][1]){
                count++;
            }
        }
    if(count==0)
        return -10; //完全没有关联
    if(count==a.size() && count == b.size())
        return 0;   //完全重叠
    if(count==a.size() || count==b.size()){
        return a.size() - b.size(); //一方包含另一方
    }
    return 10;  //有交集，非子集
}

//返回区域非交集部分
QVector<QVectorint2> AIControl::getNoMergeArea(QVectorint2 a, QVectorint2 b){
    QVector<QVectorint2> res(2, QVectorint2(0));
    QVectorint2 merge;
    for(int i=0;i<a.size();i++)
        for(int j=0;j<b.size();j++){
            if(a[i][0]==b[j][0] && a[i][1]==b[j][1]){
                merge.push_back(a[i]);
            }
        }
    //a的交集外部分
    for(int i=0;i<a.size();i++){
        int isIn = false;
        for(int j=0;j<merge.size();j++){
            if(a[i][0]==merge[j][0] && a[i][1]==merge[j][1]){
                isIn = true;
            }
        }
        if(!isIn){
            res[0].push_back(a[i]);
        }
    }
    //b的交集外部分
    for(int i=0;i<b.size();i++){
        int isIn = false;
        for(int j=0;j<merge.size();j++){
            if(b[i][0]==merge[j][0] && b[i][1]==merge[j][1]){
                isIn = true;
            }
        }
        if(!isIn){
            res[1].push_back(b[i]);
        }
    }
    return res;
}

//获取边缘地雷数,不含旗子
int AIControl::getEdgeMines(){
    int sizeX = getX();
    int sizeY = getY();
    int count = 0;
    QSet<int> edgeSet;
    for(int i=0;i<sizeX;i++)
        for(int j=0;j<sizeY;j++){
            if(isPress[i][j]&&getNumUnPressNoFlat(i, j)>0&&mines[i][j]>0){
                QVectorint2 set = getSetUnPressNoFlat(i, j);
                bool isInSet = false;
                for(int k=0;k<set.size();k++){
                    int setInt = set[k][0]*16 + set[k][1];
                    if(edgeSet.contains(setInt)){
                        isInSet = true;
                        break;
                    }
                }
                if(!isInSet){
                    for(int k=0;k<set.size();k++){
                        int setInt = set[k][0]*16 + set[k][1];
                        edgeSet.insert(setInt);
                    }
                    count += (mines[i][j] - getFlat(i, j));    //mark
                }
        }
    }
    return count;
}

//未知空间格子数,不含旗子
QVectorint2 AIControl::getSetUnKnowPoss(){
    QVector<QVector<int>> set;
    int sizeX = getX();
    int sizeY = getY();
    for(int i=0;i<sizeX;i++)
        for(int j=0;j<sizeY;j++){
            if(!isEdge(i, j)&&!isFlag[i][j]){
                QVector<int> temp(2);
                temp[0] = i;
                temp[1] = j;
                set.push_back(temp);
            }
        }
    return set;
}

//是否第一次按下判定
bool AIControl::isUnPressJudge(QVector<QVector<bool>> &isPress){
    bool result = true;
    for(int i=0;i<isPress.size();i++){
        for(int j=0;j<isPress[0].size();j++){
            if(isPress[i][j]) result = false;
        }
    }
    return result;
}

//获取周围未按下格子集合，不含旗子
QVectorint2 AIControl::getSetUnPressNoFlat(int x, int y){
    int sizeX = isPress.size();
    int sizeY = isPress[0].size();
    QVectorint2 res;
    for(int i=x-1;i<=x+1;i++)
        for(int j=y-1;j<=y+1;j++){
            if(i<0||i>=sizeX) continue;
            if(j<0||j>=sizeY) continue;
            if(!isPress[i][j]&&!isFlag[i][j]){
                QVector<int> temp(2);
                temp[0] = i;
                temp[1] = j;
                res.push_back(temp);
            }
        }
    return res;
}

//获取周围旗子数
int AIControl::getFlat(int x, int y){
    int sizeX = getX();
    int sizeY = getY();
    int count = 0;
    for(int i=x-1;i<=x+1;i++)
        for(int j=y-1;j<=y+1;j++){
            if(i<0||i>=sizeX) continue;
            if(j<0||j>=sizeY) continue;
            if(isFlag[i][j]){
                count++;
            }
        }
    return count;
}

//获取总地雷数,不含旗子
int AIControl::getMinesNoFlat(){
    int sizeX = getX();
    int sizeY = getY();
    int count = 0;
    for(int i=0;i<sizeX;i++)
        for(int j=0;j<sizeY;j++){
            if(mines[i][j]==-1&&!isFlag[i][j])
                count++;
        }
    return count;
}

//获取某格子周围格子未被点击的数量,含旗子
int AIControl::getNumUnPress(int x, int y){
    int sizeX = isPress.size();
    int sizeY = isPress[0].size();
    int count = 0;
    for(int i=x-1;i<=x+1;i++)
        for(int j=y-1;j<=y+1;j++){
            if(i<0||i>=sizeX) continue;
            if(j<0||j>=sizeY) continue;
            if(i==x&&j==y) continue;
            if(!isPress[i][j]) count++;
        }
    return count;
}

//获取某格子周围格子未被点击的数量,不含旗子
int AIControl::getNumUnPressNoFlat(int x, int y){
    int sizeX = isPress.size();
    int sizeY = isPress[0].size();
    int count = 0;
    for(int i=x-1;i<=x+1;i++)
        for(int j=y-1;j<=y+1;j++){
            if(i<0||i>=sizeX) continue;
            if(j<0||j>=sizeY) continue;
            if(i==x&&j==y) continue;
            if(!isPress[i][j]&&!isFlag[i][j]) count++;
        }
    return count;
}

//周围格子随机挑选一个未被点击的格子,不含旗子
QVector<int> AIControl::ranChooseNoFlat(int x, int y){
    int sizeX = getX();
    int sizeY = getY();
    int count = 0;
    QVector<QVector<int>> allUnPress;
    for(int i=x-1;i<=x+1;i++)
        for(int j=y-1;j<=y+1;j++){
            if(i<0||i>=sizeX) continue;
            if(j<0||j>=sizeY) continue;
            if(i==x&&j==y) continue;
            if(!isPress[i][j]&&!isFlag[i][j]){
                count++;
                QVector<int> s(2);
                s[0] = i;
                s[1] = j;
                allUnPress.push_back(s);
            }
        }
    if(count>0){
        int resCount = rand() % count;
        return allUnPress[resCount];
    }
    else{
        QVector<int> s;
        return s;
    }
}

//是否边缘格子
bool AIControl::isEdge(int x, int y){
    int sizeX = getX();
    int sizeY = getY();
    bool res = false;
    for(int i=x-1;i<=x+1;i++)
        for(int j=y-1;j<=y+1;j++){
            if(i<0||i>=sizeX) continue;
            if(j<0||j>=sizeY) continue;
            if(isPress[i][j]) res = true;
        }
    return res;
}

//获取最小值坐标
int AIControl::min(QVector<double> a){
    if(a.size()<=0)
        return -1;
    double minN = a[0];
    int res = 0;
    for(int i=0;i<a.size();i++){
        if(a[i] < minN){
            res = i;
            minN = a[i];
        }
    }
    return res;
}

int AIControl::getX(){
    return isPress.size();
}

int AIControl::getY(){
    return isPress[0].size();
}

int AIControl::abs(int a){
    if(a<0) return -a;
    return a;
}
