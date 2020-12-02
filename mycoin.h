#ifndef MYCOIN_H
#define MYCOIN_H

#include <QPushButton>
#include <QTimer>

class myCoin : public QPushButton
{
    Q_OBJECT
public:
//    explicit myCoin(QWidget *parent = nullptr);
    myCoin(QString btnImg);

    //金币属性
    int posX;
    int posY;
    int flag;

    //改变标志的方法
    void changeFlag();
    QTimer* timer1; //正面翻反面的定时器
    QTimer* timer2; //反面翻正面的定时器
    int min = 1;
    int max = 8;

    //执行动画标志
    bool isAnimation = false;

    //重写 按下 和 释放
    void mousePressEvent(QMouseEvent* e);

    bool isWin = false;

signals:

};

#endif // MYCOIN_H
