#ifndef MYPUSHBUTTON_H
#define MYPUSHBUTTON_H

#include <QPushButton>

class MypushButton : public QPushButton
{
    Q_OBJECT
public:
//    explicit MypushButton(QWidget *parent = nullptr);

    //构造函数 参数1 正常显示图片 参数2 按下后显示图片
    MypushButton(QString normalImg, QString pressImg = "");

    //图片路径
    QString normalImgPath;
    QString pressImgPath;

    //弹跳特效
    void zoom1(); //向下跳
    void zoom2(); //向上跳

    //重写按钮 按下 和 释放事件
    void mousePressEvent(QMouseEvent* e);
    void mouseReleaseEvent(QMouseEvent* e);


signals:

public slots:
};

#endif // MYPUSHBUTTON_H
