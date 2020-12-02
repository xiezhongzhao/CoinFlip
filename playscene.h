#ifndef PLAYSCENE_H
#define PLAYSCENE_H

#include <QMainWindow>
#include "mycoin.h"

class PlayScene : public QMainWindow
{
    Q_OBJECT
public:
    //explicit PlayScene(QWidget *parent = 0);

    PlayScene(int levelNum);

    int levelIndex ; //内部成员属性 记录所选的关卡

    //重写paintEvent事件
    void paintEvent(QPaintEvent *);

    int gameArray[4][4]; //二维数组维护每个关卡的具体数据

    myCoin* coinBtn[4][4];

    bool isWin; //是否胜利


signals:
    void chooseSceneBack();
public slots:
};

#endif // PLAYSCENE_H
