#include "game.h"
#include "ui_game.h"
#include<QPainter>
#include<QPaintEvent>
#include<QDebug>
#include<QVector>
#include<vector>
#include<time.h>
#include<QTime>
#include<ctime>
#include<QMessageBox>
#include<QFile>
#include<QDesktopServices>

#define back1 "../image/background.png"
//#define back2 "../../Qtt/pic/startBkg2.png"
//#define back3 "../../Qtt/pic/foggy.png"
#define ground_img "../image/ground.png"

game::game(QWidget *parent,int wid,int heig)
    : QWidget(parent)
    , ui(new Ui::game)
{
    ui->setupUi(this);

    this->resize(wid,heig);
    ground_Y=heig-70;

    //背景
    background[0].load(back1);
    //background[1].load(back2);
    //background[2].load(back3);
    ground.load(ground_img);
    up=down=left=right=false;
    //isRunning=false;
    ground_speed=1;
    ground_X=0;

    remove.setInterval(17);
    this->grabKeyboard();
    connect(&remove,&QTimer::timeout,
            [=](){

            }
    );
}

game::~game()
{
    delete ui;
}

void game::paintEvent(QPaintEvent *event){
    QPainter painter(this);

    for(int i=0;i<1;++i){//画背景
        painter.drawPixmap(QRect(0,0,this->width(),this->height())
                           ,background[i]
                           ,QRect(0,0,this->width()-(background[i].width()-backImgX[i]),this->height()));
        if(backImgX[i]>0){
            painter.drawPixmap(QRect(background[i].width()-backImgX[i],0,this->width()-(background[i].width()-backImgX[i]),this->height())
                               ,background[i]
                               ,QRect(0,0,this->width()-(background[i].width()-backImgX[i]),this->height()));   //补充右边的空白区域
        }
        if(backImgX[i]>=background[i].width())
            backImgX[i]-=background[i].width();
        backImgX[i]+=imgSpeed[i];

    }
    //画地面
    painter.drawPixmap(QRect(0,ground_Y,this->width(),this->height()-ground_Y),
                       ground,
                       QRect(0,0,this->width()-(ground.width()-ground_X),this->height()-this->ground_Y));
    if(this->width()>(ground.width()-ground_X)){
        painter.drawPixmap(QRect(ground.width()-ground_X,this->ground_Y,this->width()-(ground.width()-ground_X),this->height()-this->ground_Y)
                           ,ground
                           ,QRect(0,0,this->width()-(ground.width()-ground_X),this->height()-this->ground_Y));
    }
    if(ground_X>=ground.width())
        ground_X-=ground.width();
    ground_X+=ground_speed;
}

