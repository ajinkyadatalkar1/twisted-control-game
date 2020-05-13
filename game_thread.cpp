/*Written by Ajinkya Datalkar*/
#include "game_thread.h"


threads::threads(QGraphicsView *view_item, QGraphicsScene *scene_item, QGraphicsScene *retry_screen, QGraphicsScene *pause_screen, QGraphicsProxyWidget *rocket_item)
{
    static int twist_time_checker=50;
    this->start(QThread::HighestPriority);
    enemy *start_game = new enemy(scene_item,pause_screen,retry_screen);

    twisted_control *add_twist = new twisted_control();
    thunder *add_thunder = new thunder();

    /*
    scene_item->removeItem(start_game->enemy_rocket1);
    scene_item->removeItem(start_game->enemy_rocket2);
    scene_item->removeItem(start_game->enemy_rocket3);*/


    add_twist->assign_keys(scene_item,rocket_item);
    add_twist->twist(rocket_item);

    QTimer *enemy_timer1 = new QTimer();
    connect(enemy_timer1,&QTimer::timeout,[=](){
        start_game->enemy_params(view_item,scene_item,retry_screen,pause_screen,rocket_item,enemy_timer1);
        twist_time_checker += 50;
        if(twist_time_checker == 10000){
                add_thunder->create_thunder(scene_item,enemy_timer1);
                add_twist->twist(rocket_item);
                twist_time_checker = 0;
        }
      });
    enemy_timer1->start();

    start_game->one_time_params(enemy_timer1,view_item,scene_item,pause_screen,retry_screen);
}
