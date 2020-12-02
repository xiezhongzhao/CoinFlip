#include "mainscene.h"
#include "ui_mainscene.h"
#include "QPainter"
#include "mypushbutton.h"
#include "chooselevelscene.h"

#include <QSound>
#include <QDebug>
#include <QTimer>

MainScene::MainScene(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainScene)
{
    ui->setupUi(this);

    //配置主场景

    //设置固定大小
    setFixedSize(400, 688);
    //设置图标
    setWindowIcon(QIcon(":/res/Coin0001.png"));
    //设置标题
    setWindowTitle("翻金币的主场景");

    //退出按钮实现
    connect(ui->actionQuit, &QAction::triggered, [=](){
        this->close();
    });

    //准备开始音效
    QSound* startSound = new QSound(":/res/LevelWinSound.wav", this);
//    startSound->setLoops(-1);
    startSound->play();

    //开始按钮
    MypushButton* startBtn = new MypushButton(":/res/MenuSceneStartButton.png");
    startBtn->setParent(this);
    startBtn->move(this->width()*0.5-startBtn->width()*0.5,this->height()*0.7);

    //实例化选择关卡场景
    chooseScene = new ChooseLevelScene;

    //监听选择关卡的返回按钮信号
    connect(chooseScene,&ChooseLevelScene::chooseSceneBack,this,[=]{

        chooseScene->hide();
        this->show();
    });

    connect(startBtn, &MypushButton::clicked, [=](){

        //播放音效
        startSound->play();

        qDebug() << "弹跳按钮";
        startBtn->zoom1();
        startBtn->zoom2();

        //延时进入到选择关卡场景中
        QTimer::singleShot(500,this,[=](){
            //自身隐藏
            this->hide();
            //显示关卡场景
            chooseScene->show();

        });

    });
}

void MainScene::paintEvent(QPaintEvent*){

    QPainter painter(this);
    QPixmap pix;
    pix.load(":/res/PlayLevelSceneBg.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);

    //画背景上图标
    pix.load(":/res/Title.png");
    painter.drawPixmap(0,0,pix);
}


MainScene::~MainScene()
{
    delete ui;
}






