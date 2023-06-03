#ifndef GAME_H
#define GAME_H

#include <QWidget>
#include<QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class game; }
QT_END_NAMESPACE

class game : public QWidget
{
    Q_OBJECT

private:
    QPixmap background[3]; //游戏地图
   // QPixmap before_start;
    QPixmap ground; //地面



public:
    explicit game(QWidget *parent = nullptr,int wid=1280,int heig=720);
    ~game();

    double backImgX[3]={0,200,0}; //图片水平移动参数
    double imgSpeed[3]={0.15,1.0,0.5};//移动速度参数
    double ground_X; //X 点
    double ground_speed; //地面移动参数
    int ground_Y; //Y点
    //bool isRunning;//是否游戏中
    bool up;
    bool down;
    bool right;
    bool left;
    QTimer remove;

    void paintEvent(QPaintEvent *event);//绘图
    //void keyPressEvent(QKeyEvent * event);
   //void keyReleaseEvent(QKeyEvent *event);


private:
    Ui::game *ui;
};
#endif // GAME_H
