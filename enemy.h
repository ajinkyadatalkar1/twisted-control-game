/*Written by Ajinkya Datalkar*/
#ifndef ENEMY_H
#define ENEMY_H

#include "display.h"

class enemy:public QTimer,public QGraphicsRectItem
{
    Q_OBJECT
public:
    enemy(QGraphicsScene *scene_item, QGraphicsScene *pause_screen, QGraphicsScene *retry_screen);
    //static int i,j,k;
    void enemy_params(QGraphicsView *view_item, QGraphicsScene *scene_item, QGraphicsScene *retry_screen, QGraphicsScene *pause_screen,  QGraphicsProxyWidget *rocket_item, QTimer *timer);
    void pause_func(QTimer *timer, QGraphicsView *view_item, QGraphicsScene *pause_screen);
    void resume_func(QTimer *timer, QGraphicsView *view_item, QGraphicsScene *scene_item);
    void one_time_params(QTimer *timer, QGraphicsView *view_item, QGraphicsScene *scene_item, QGraphicsScene *pause_screen, QGraphicsScene *retry_screen);
    void collision_detect(QGraphicsRectItem *rect_item,int pos,QGraphicsView *view_item);
    void retry_func(QGraphicsView *view_item, QGraphicsScene *scene_item, QTimer *timer);
    void stopmaintimer(QTimer *timer, QGraphicsScene *retry_screen, QGraphicsView *view_item);
    void update_score(QTimer *timer);

    void score_update();

    int position1(QGraphicsScene *scene_item, QGraphicsProxyWidget *rocket_item);
    int position2(QGraphicsScene *scene_item, QGraphicsProxyWidget *rocket_item);
    int position3(QGraphicsScene *scene_item, QGraphicsProxyWidget *rocket_item);

    int slow(QGraphicsScene *scene_item, QGraphicsProxyWidget *rocket_item);
    int medium(QGraphicsScene *scene_item, QGraphicsProxyWidget *rocket_item);
    int fast(QGraphicsScene *scene_item, QGraphicsProxyWidget *rocket_item);

    QGraphicsPixmapItem *enemy_rocket1 = new QGraphicsPixmapItem();
    QGraphicsPixmapItem *enemy_rocket2 = new QGraphicsPixmapItem();
    QGraphicsPixmapItem *enemy_rocket3 = new QGraphicsPixmapItem();
    QGraphicsPixmapItem *engine_1 = new QGraphicsPixmapItem();
    QGraphicsPixmapItem *engine_2 = new QGraphicsPixmapItem();
    QGraphicsPixmapItem *engine_3 = new QGraphicsPixmapItem();


    QPushButton *pause_game = new QPushButton("Pause");
    QGraphicsProxyWidget *pause_btn = new QGraphicsProxyWidget();

    QPushButton *resume = new QPushButton("Resume");
    QGraphicsProxyWidget *resume_btn = new QGraphicsProxyWidget();


    QPushButton *retry = new QPushButton("Retry");
    QGraphicsProxyWidget *retry_btn = new QGraphicsProxyWidget();

    QSettings *settings = new QSettings("BrainFreezeGames","Twisted Control");

private:

    QGraphicsTextItem *score_label = new QGraphicsTextItem();
    QGraphicsTextItem *high_score = new QGraphicsTextItem();
    QGraphicsTextItem *high_score2 = new QGraphicsTextItem();


    static int stop_main_timer;
    static int collision_param;
    static int pause_param;
    static int score;
    static int retry_status;

    static int pos1;
    static int pos2;
    static int pos3;

    static int pos_c1;//for enemies
    static int pos_c2;
    static int pos_c3;
    static int pos_p1;//for power ups
    static int pos_p2;
    static int pos_p3;

    static bool enemy_end1;
    static bool enemy_end2;
    static bool enemy_end3;
    static bool slow_end;
    static bool medium_end;
    static bool fast_end;

    static int speed_control;

    static int switch_place;
    static int bring_enemy;

    int score_func(QGraphicsScene *scene_item);
    void enemy_resume(QTimer *timer);
    void hide_control(int pause_param);
    void save_score();
    void update_score();
};

#endif // ENEMY_H
