#include "chooselevelscene.h"
#include <QMenuBar>
#include <QPainter>
#include <QDebug>
#include <QTimer>
#include <QLabel>

#include <QSound>
#include "mypushbutton.h"

ChooseLevelScene::ChooseLevelScene(QWidget *parent) : QMainWindow(parent)
{
    //配置选择关卡场景
    this->setFixedSize(400,688);

    //设置图标
    this->setWindowIcon(QPixmap(":/res/Coin0001.png"));

    //设置标题
    this->setWindowTitle("选择关卡场景");

    //创建菜单栏
    QMenuBar* bar = menuBar();
    setMenuBar(bar);

    //创建开始菜单
    QMenu* startMenu = bar->addMenu("开始");
    //创建退出菜单栏
    QAction* quitAction = startMenu->addAction("退出");

    //点击退出 实现退出游戏
    connect(quitAction, &QAction::triggered,[=](){
        this->close();
    });

    QSound *backSound = new QSound(":/res/BackButtonSound.wav",this);
    //返回按钮
    MypushButton* backBtn = new MypushButton(":/res/BackButton.png",":/res/BackButtonSelected.png");
    backBtn->setParent(this);
    backBtn->move(this->width()-backBtn->width(),this->height()-backBtn->height());

    //点击返回
    connect(backBtn, &MypushButton::clicked,[=](){
//        qDebug() << "点击了返回按钮";

        //播放音效
        backSound->play();

        //告诉主场景 我返回了，主场景监听ChooseLevelScene的返回按钮
        QTimer::singleShot(200, this, [=](){
            emit this->chooseSceneBack();
        });
    });

    //创建选择关卡按钮
    for(int i=0; i<20; i++){
        MypushButton* menuBtn = new MypushButton(":/res/LevelIcon.png");
        menuBtn->setParent(this);
        menuBtn->move(70 + i%4 * 70, 180 + i/4 * 70);

        //监听每个按钮的监听事件
        connect(menuBtn, &MypushButton::clicked, [=](){
            QString str = QString("您选择的是第 %1 关").arg(i+1);
            qDebug() << str;

            //进入到游戏场景
            this->close(); //隐藏选关界面
            play = new PlayScene(i+1); //创建游戏场景
            play->show(); //显示游戏场景

            connect(play,&PlayScene::chooseSceneBack,[=](){
                this->show();
                delete play;
                play = NULL;
            });
        });

        QLabel* label = new QLabel;
        label->setParent(this);
        label->setFixedSize(menuBtn->width(), menuBtn->height());
        label->setText(QString::number(i+1));
        label->move(70 + i%4 * 70, 180 + i/4 * 70);

        //设置label上的文字对齐方式
        label->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        //设置让鼠标进行穿透
        label->setAttribute(Qt::WA_TransparentForMouseEvents);
    }


}

void ChooseLevelScene::paintEvent(QPaintEvent*){

    //加载背景
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/res/OtherSceneBg.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);

    //加载标题
    pix.load(":/res/Title.png");
    painter.drawPixmap((this->width()-pix.width())*0.5,30,pix.width(),pix.height(),pix);

}






