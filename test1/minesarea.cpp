#include "minesarea.h"
#include "autoai.h"
#include "aicontrol.h"
#include "QDebug"

MinesArea::MinesArea(QWidget *parent) : QWidget(parent)
{
    setMouseTracking(true);
    setAutoFillBackground(true);
    setMinimumSize(800, 400);
    replay();
}

void MinesArea::mouseMoveEvent(QMouseEvent *e)
{
    if(gameOver==-1&&!isWin)
        movePos = e->pos();
    else{
        movePos.setX(0);
        movePos.setY(0);
    }
    update();
}

void MinesArea::mousePressEvent(QMouseEvent *e)
{
    if(gameOver==-1&&!isWin){
        if(e->button() == Qt::LeftButton)
            pressPos = e->pos();
        if(e->button() == Qt::RightButton)
            rightPressPos = e->pos();
        update();
    }
}

void MinesArea::paintEvent(QPaintEvent *)
{
    int x, y, mineH, mineW;
    QVector<int> Attr = getAttr();
    x = Attr[0];
    y = Attr[1];
    mineH = Attr[2];
    mineW = Attr[3];
    int sizeX = minesNum.size();
    int sizeY = minesNum[0].size();
    QPainter p(this);
    QPen whitePen(Qt::white);
    QPen grayPen(Qt::gray);
    QPen blackPen(Qt::black);
    QPen lgrayPen(QColor(0xC4, 0xC4, 0xC4));
    QPen redPen(Qt::red);
    QBrush redBrush(Qt::red, Qt::SolidPattern);
    QBrush whiteBrush(Qt::white, Qt::SolidPattern);
    QBrush grayBrush(Qt::gray, Qt::SolidPattern);
    QBrush blackBrush(Qt::black, Qt::SolidPattern);
    QBrush lgrayBrush(QColor(0xC4, 0xC4, 0xC4), Qt::SolidPattern);
    QFont mineFont("幼圆", mineH * 0.5, Qt::black);
    p.setFont(mineFont);
    for(int i=0;i<16;i++)
        for(int j=0;j<32;j++){
            if(pressPos.x()>=x+j*mineW+2&&pressPos.x()<=x+(j+1)*mineW-2&&pressPos.y()>=y+i*mineH+2&&pressPos.y()<=y+(i+1)*mineH-2&&!isFlag[i][j]){
                if(initFlat){
                    firstPress = i * sizeY + j;
                    init();
                    initFlat = false;
                }
                if(isPressed[i][j]){
                    int flagsNearNum = 0;
                    for(int ni=i-1;ni<=i+1;ni++)
                        for(int nj=j-1;nj<=j+1;nj++)
                            if(ni>=0&&ni<sizeX&&nj>=0&&nj<sizeY&&isFlag[ni][nj])
                                flagsNearNum++;
                    if(flagsNearNum == minesNum[i][j]){
                        for(int ni=i-1;ni<=i+1;ni++)
                            for(int nj=j-1;nj<=j+1;nj++)
                                if(ni>=0&&ni<sizeX&&nj>=0&&nj<sizeY&&!isFlag[ni][nj])
                                    isPressed[ni][nj] = true;
                    }
                }
                else{
                    isPressed[i][j] = true;
                }
            }
            if(rightPressPos.x()>=x+j*mineW+2&&rightPressPos.x()<=x+(j+1)*mineW-2&&rightPressPos.y()>=y+i*mineH+2&&rightPressPos.y()<=y+(i+1)*mineH-2&&!isPressed[i][j]){
                if(isFlag[i][j]){
                    flagSum--;
                    flag(flagSum);
                }
                else{
                    flagSum++;
                    flag(flagSum);
                }
                isFlag[i][j] = !isFlag[i][j];
            }
        }
    for(int i=0;i<16;i++)
        for(int j=0;j<32;j++){
            if(!isFlag[i][j]&&isPressed[i][j]&&minesNum[i][j]==0)
                zeroBeIsPress(i, j);
        }
    int clickNum = 0;
    if(!isWin){
        for(int i=0;i<16;i++)
            for(int j=0;j<32;j++){
                if(isPressed[i][j]&&minesNum[i][j]==-1){
                    gameOver = i * sizeY + j;
                    Tstart(2);
                }
                if(isPressed[i][j])
                    clickNum++;
            }
        if(clickNum==sizeX*sizeY-minesSum){
            isWin = true;
            Tstart(2);
        }
    }
    for(int i=0;i<16;i++)
        for(int j=0;j<32;j++){
            if(movePos.x()>=x+j*mineW+2&&movePos.x()<=x+(j+1)*mineW-2&&movePos.y()>=y+i*mineH+2&&movePos.y()<=y+(i+1)*mineH-2&&!isFlag[i][j]){
                p.setPen(grayPen);
                p.setBrush(grayBrush);
            }
            else{
                p.setPen(lgrayPen);
                p.setBrush(lgrayBrush);
            }
            QRectF mineArea(x+j*mineW+2, y+i*mineH+2, mineW-4, mineH-4);
            p.drawRoundRect(mineArea, 10, 10);
            if(isPressed[i][j]){
                p.setPen(whitePen);
                p.setBrush(whiteBrush);
                if(gameOver!=-1&&i==gameOver/sizeY&&j==gameOver%sizeY){
                    p.setPen(redPen);
                    p.setBrush(redBrush);
                }
                QRectF mineArea(x+j*mineW+2, y+i*mineH+2, mineW-4, mineH-4);
                p.drawRoundRect(mineArea, 10, 10);
                if(minesNum[i][j]==-1){
                    p.setRenderHint(QPainter::Antialiasing, true);
                    QPointF center(x+((2*j+1)*mineW)/2, y+((2*i+1)*mineH)/2);
                    blackPen.setWidth(0);
                    p.setPen(blackPen);
                    p.setBrush(blackBrush);
                    p.drawEllipse(center, (mineW)/4.5, (mineH)/4.5);
                    blackPen.setWidth(mineW * 0.1);
                    blackPen.setCapStyle(Qt::RoundCap);
                    p.setPen(blackPen);
                    p.setBrush(blackBrush);
                    p.drawLine(x+(2*j+1)*mineW/2-mineW/3, y+(2*i+1)*mineH/2, x+(2*j+1)*mineW/2+mineW/3, y+(2*i+1)*mineH/2);
                    p.drawLine(x+(2*j+1)*mineW/2, y+(2*i+1)*mineH/2-mineW/3, x+(2*j+1)*mineW/2, y+(2*i+1)*mineH/2+mineW/3);
                    p.drawLine(x+(2*j+1)*mineW/2-mineW/(3*sqrt(2)), y+(2*i+1)*mineH/2-mineW/(3*sqrt(2)), x+(2*j+1)*mineW/2+mineW/(3*sqrt(2)), y+(2*i+1)*mineH/2+mineW/(3*sqrt(2)));
                    p.drawLine(x+(2*j+1)*mineW/2-mineW/(3*sqrt(2)), y+(2*i+1)*mineH/2+mineW/(3*sqrt(2)), x+(2*j+1)*mineW/2+mineW/(3*sqrt(2)), y+(2*i+1)*mineH/2-mineW/(3*sqrt(2)));
                    p.setRenderHint(QPainter::Antialiasing, false);
                }
                else{
                    p.setPen(blackPen);
                    p.setBrush(blackBrush);
                    if(minesNum[i][j]!=0){
                        char a[] = {char(minesNum[i][j] + 48), '\0'};
                        p.drawText(mineArea, Qt::AlignCenter, tr(a));
                    }
                }
            }
            else if(isFlag[i][j]){
                blackPen.setWidth(mineW * 0.1);
                blackPen.setCapStyle(Qt::FlatCap);
                p.setPen(blackPen);
                p.setBrush(blackBrush);
                p.drawLine(x+j*mineW+mineW/3.5, y+i*mineH+2+(mineH-4)/6, x+j*mineW+mineW/3.5, y+(i+1)*mineH-2-(mineH-4)/6);
                blackPen.setWidth(0);
                p.setPen(blackPen);
                QPoint triangle[3] = {QPoint(x+j*mineW+mineW/3.5, y+i*mineH+2+(mineH-4)/6),
                                      QPoint(x+j*mineW+mineW/3.5, y+i*mineH+2+(mineH-4)/6+4*(mineH-4)/9),
                                      QPoint(x+(j+1)*mineW-mineW/4, y+i*mineH+2+(mineH-4)/6+2*(mineH-4)/9)};
                p.setRenderHint(QPainter::Antialiasing, true);
                p.drawPolygon(triangle, 3);
                p.setRenderHint(QPainter::Antialiasing, false);
            }
            else if(gameOver!=-1&&minesNum[i][j]==-1){
                p.setRenderHint(QPainter::Antialiasing, true);
                QPointF center(x+((2*j+1)*mineW)/2, y+((2*i+1)*mineH)/2);
                blackPen.setWidth(0);
                p.setPen(blackPen);
                p.setBrush(blackBrush);
                p.drawEllipse(center, (mineW)/4.5, (mineH)/4.5);
                blackPen.setWidth(mineW * 0.1);
                blackPen.setCapStyle(Qt::RoundCap);
                p.setPen(blackPen);
                p.setBrush(blackBrush);
                p.drawLine(x+(2*j+1)*mineW/2-mineW/3, y+(2*i+1)*mineH/2, x+(2*j+1)*mineW/2+mineW/3, y+(2*i+1)*mineH/2);
                p.drawLine(x+(2*j+1)*mineW/2, y+(2*i+1)*mineH/2-mineW/3, x+(2*j+1)*mineW/2, y+(2*i+1)*mineH/2+mineW/3);
                p.drawLine(x+(2*j+1)*mineW/2-mineW/(3*sqrt(2)), y+(2*i+1)*mineH/2-mineW/(3*sqrt(2)), x+(2*j+1)*mineW/2+mineW/(3*sqrt(2)), y+(2*i+1)*mineH/2+mineW/(3*sqrt(2)));
                p.drawLine(x+(2*j+1)*mineW/2-mineW/(3*sqrt(2)), y+(2*i+1)*mineH/2+mineW/(3*sqrt(2)), x+(2*j+1)*mineW/2+mineW/(3*sqrt(2)), y+(2*i+1)*mineH/2-mineW/(3*sqrt(2)));
                p.setRenderHint(QPainter::Antialiasing, false);
            }
            /*if(isWin){
                QPen sblackPen(QColor(0xCF, 0xCF, 0xCF, 128), 99);

                QFont winFont("幼圆", mineH * 5, Qt::gray);
                QRect allArea(x, y, w, h);
                p.setPen(sblackPen);
                p.setFont(winFont);
                p.drawText(allArea, Qt::AlignCenter, tr("WIN"));
                p.setFont(mineFont);
            }*/

        }
    QPoint zero(0, 0);
    pressPos = zero;
    rightPressPos = zero;
    emit updateComplete();
}

void MinesArea::init()
{
    srand((unsigned)time(NULL));
    int sizeX = minesNum.size();
    int sizeY = minesNum[0].size();
    QVector<int> minesSort(sizeX * sizeY);
    for(int i=0;i<minesSort.size();i++)
        minesSort[i] = i;
    swap(minesSort[firstPress], minesSort[sizeX*sizeY-1]);
    if(firstPress-sizeY-1>=0) swap(minesSort[firstPress-sizeY-1], minesSort[sizeX*sizeY-2]);
    if(firstPress-sizeY>=0) swap(minesSort[firstPress-sizeY], minesSort[sizeX*sizeY-3]);
    if(firstPress-sizeY+1>=0) swap(minesSort[firstPress-sizeY+1], minesSort[sizeX*sizeY-4]);
    if(firstPress-1>=0) swap(minesSort[firstPress-1], minesSort[sizeX*sizeY-5]);
    if(firstPress+1<sizeX*sizeY) swap(minesSort[firstPress+1], minesSort[sizeX*sizeY-6]);
    if(firstPress+sizeY-1<sizeX*sizeY) swap(minesSort[firstPress+sizeY-1], minesSort[sizeX*sizeY-7]);
    if(firstPress+sizeY<sizeX*sizeY) swap(minesSort[firstPress+sizeY], minesSort[sizeX*sizeY-8]);
    if(firstPress+sizeY+1<sizeX*sizeY) swap(minesSort[firstPress+sizeY+1], minesSort[sizeX*sizeY-9]);
    for(int i=0;i<minesSort.size()-9;i++){
        int j = rand() % (sizeX * sizeY - 9);
        swap(minesSort[i], minesSort[j]);
    }
    for(int i=0;i<minesSum;i++){
            int posXY = minesSort[i];
            int posX = posXY / sizeY;
            int posY = posXY % sizeY;
            minesNum[posX][posY] = -1;
            if(posX>0&&posY>0&&minesNum[posX-1][posY-1]!=-1) minesNum[posX-1][posY-1]++;
            if(posX>0&&minesNum[posX-1][posY]!=-1) minesNum[posX-1][posY]++;
            if(posX>0&&posY<sizeY-1&&minesNum[posX-1][posY+1]!=-1) minesNum[posX-1][posY+1]++;
            if(posY>0&&minesNum[posX][posY-1]!=-1) minesNum[posX][posY-1]++;
            if(posY<sizeY-1&&minesNum[posX][posY+1]!=-1) minesNum[posX][posY+1]++;
            if(posX<sizeX-1&&posY>0&&minesNum[posX+1][posY-1]!=-1) minesNum[posX+1][posY-1]++;
            if(posX<sizeX-1&&minesNum[posX+1][posY]!=-1) minesNum[posX+1][posY]++;
            if(posX<sizeX-1&&posY<sizeY-1&&minesNum[posX+1][posY+1]!=-1) minesNum[posX+1][posY+1]++;
        }
    Tstart(0);
}

void MinesArea::replay(){
    initFlat = true;
    gameOver = -1;
    minesSum = 99;
    firstPress = -1;
    flagSum = 0;
    isWin = false;
    QPoint zero(0, 0);
    pressPos = zero;
    rightPressPos = zero;
    movePos = zero;
    minesNum.resize(16);
    isPressed.resize(16);
    isFlag.resize(16);
    for(int i=0;i<minesNum.size();i++){
        minesNum[i].resize(32);
        isPressed[i].resize(32);
        isFlag[i].resize(32);
    }
    for(int i=0;i<minesNum.size();i++)
        for(int j=0;j<minesNum[0].size();j++){
            minesNum[i][j] = 0;
            isPressed[i][j] = false;
            isFlag[i][j] = false;
        }
    flag(flagSum);
    Tstart(1);
    update();
}

void MinesArea::swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void MinesArea::zeroBeIsPress(int i,int j)
{
    int sizeX = minesNum.size();
    int sizeY = minesNum[0].size();
    bool bePress = false;
    if(!isFlag[i][j]) isPressed[i][j] = true;
    if(i-1>=0&&i-1<sizeX&&j-1>=0&&j-1<sizeY&&!isFlag[i-1][j-1]&&!isPressed[i-1][j-1]){bePress = true; isPressed[i-1][j-1] = true;}
    if(i-1>=0&&i-1<sizeX&&j>=0&&j<sizeY&&!isFlag[i-1][j]&&!isPressed[i-1][j]){bePress = true; isPressed[i-1][j] = true;}
    if(i-1>=0&&i-1<sizeX&&j+1>=0&&j+1<sizeY&&!isFlag[i-1][j+1]&&!isPressed[i-1][j+1]){bePress = true; isPressed[i-1][j+1] = true;}
    if(i>=0&&i<sizeX&&j-1>=0&&j-1<sizeY&&!isFlag[i][j-1]&&!isPressed[i][j-1]){bePress = true; isPressed[i][j-1] = true;}
    if(i>=0&&i<sizeX&&j+1>=0&&j+1<sizeY&&!isFlag[i][j+1]&&!isPressed[i][j+1]){bePress = true; isPressed[i][j+1] = true;}
    if(i+1>=0&&i+1<sizeX&&j-1>=0&&j-1<sizeY&&!isFlag[i+1][j-1]&&!isPressed[i+1][j-1]){bePress = true; isPressed[i+1][j-1] = true;}
    if(i+1>=0&&i+1<sizeX&&j>=0&&j<sizeY&&!isFlag[i+1][j]&&!isPressed[i+1][j]){bePress = true; isPressed[i+1][j] = true;}
    if(i+1>=0&&i+1<sizeX&&j+1>=0&&j+1<sizeY&&!isFlag[i+1][j+1]&&!isPressed[i+1][j+1]){bePress = true; isPressed[i+1][j+1] = true;}
    if(bePress&&i-1>=0&&i-1<sizeX&&j>=0&&j<sizeY&&minesNum[i-1][j]==0) zeroBeIsPress(i-1, j);
    if(bePress&&i>=0&&i<sizeX&&j-1>=0&&j-1<sizeY&&minesNum[i][j-1]==0) zeroBeIsPress(i, j-1);
    if(bePress&&i+1>=0&&i+1<sizeX&&j>=0&&j<sizeY&&minesNum[i+1][j]==0) zeroBeIsPress(i+1, j);
    if(bePress&&i>=0&&i<sizeX&&j+1>=0&&j+1<sizeY&&minesNum[i][j+1]==0) zeroBeIsPress(i, j+1);
}

void MinesArea::returnStatus(){
    emit sendStatus(minesNum, isPressed, isFlag);
}

QVector<int> MinesArea::getAttr(){
    int x, y, w, h;
    int mainH = height();
    int mainW = width();
    if(mainW >= 2 * mainH){
        x = (mainW - 2 * mainH) / 2;
        y = 0;
        w = 2 * mainH;
        h = mainH;
    }
    else{
        x = 0;
        y = (mainH - mainW / 2) / 2;
        w = mainW;
        h = mainW / 2;
    }
    int mineH = h / 16;
    int mineW = w / 32;
    QVector<int> res = {x, y, mineH, mineW};
    return res;
}

void MinesArea::setStatus(QVector<int> predict, bool isPress){
    QVector<int> Attr = getAttr();
    int x = Attr[0];
    int y = Attr[1];
    int mineH = Attr[2];
    int mineW = Attr[3];
    int i = predict[0];
    int j = predict[1];
    if(isPress){
        pressPos.setX(x+(j+0.5)*mineW);
        pressPos.setY(y+(i+0.5)*mineH);
    }
    else{
        rightPressPos.setX(x+(j+0.5)*mineW);
        rightPressPos.setY(y+(i+0.5)*mineH);
    }
    update();
    if(gameOver!=-1||isWin)
        emit sendStop();
}

void MinesArea::resizeEvent(QResizeEvent *event)
{
    pressPos.setX(0);
    pressPos.setY(0);
    movePos.setX(0);
    movePos.setY(0);
    rightPressPos.setX(0);
    rightPressPos.setY(0);
    update();
}
