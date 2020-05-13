/*Written by Ajinkya Datalkar*/
#include "player.h"
#include "enemy.h"
#include "twisted_control.h"
#include "thunder.h"
#include "buttons.h"
#include <QLabel>
#include <QThread>
#include "common_variables.h"
#include "parallax.h"

#include "game_thread.h"
#include "parallax_thread.h"

void player::rocket(QGraphicsScene *scene_item, QGraphicsView *view_item,QGraphicsScene *pause_screen,QGraphicsScene *retry_screen)
{
    parallax_thread *b = new parallax_thread(scene_item,view_item);
#include "player.h"
#include "enemy.h"
#include "twisted_control.h"
#include "buttons.h"
#include "parallax_animation.h"
#include <QLabel>
#include <QThread>

void player::rocket(QGraphicsScene *scene_item, QGraphicsView *view_item,QGraphicsScene *pause_screen,QGraphicsScene *retry_screen)
{

    enemy *start_game = new enemy(view_item,scene_item,pause_screen,retry_screen);
    QTimer *enemy_timer1 = new QTimer();

    QLabel *rocket_label = new QLabel;
    rocket_label->setAttribute(Qt::WA_TranslucentBackground, true);
    QMovie *rocket_movie = new QMovie;
    rocket_movie->setFileName(":/images/rocket.gif");
    rocket_movie->setCacheMode(QMovie::CacheAll);
    rocket_movie->start();
    rocket_label->setMovie(rocket_movie);
    QGraphicsProxyWidget *rocket_widget = scene_item->addWidget(rocket_label);
    rocket_widget->setPos(DISPLAY_WIDTH/2 - QPixmap::fromImage(QImage(":/images/rocket.png")).width()/2,DISPLAY_HEIGHT - 700);
    rocket_movie->start();
    rocket_label->setMovie(rocket_movie);
    QGraphicsProxyWidget *rocket_widget = scene_item->addWidget(rocket_label);
    rocket_widget->setPos(view_item->width()/2 - QPixmap::fromImage(QImage(":/images/rocket.png")).width()/2,view_item->height() - 700);
    rocket_widget->setFlag(QGraphicsItem::ItemIsFocusable);
    rocket_widget->setFocus();
    rocket_widget->setZValue(-1);
    scene_item->addItem(rocket_widget);


    threads *t = new threads(view_item,scene_item,retry_screen,pause_screen,rocket_widget);
    twisted_control *add_twist = new twisted_control();
    add_twist->twist(view_item,scene_item,rocket_widget);

    scene_item->removeItem(start_game->enemy_rocket1);
    scene_item->removeItem(start_game->enemy_rocket1);
    scene_item->removeItem(start_game->enemy_rocket1);
    connect(enemy_timer1,&QTimer::timeout,[=](){
        start_game->enemy_params(view_item,scene_item,retry_screen,rocket_widget,enemy_timer1);
        enemy_timer1->setInterval(view_item->height());// Controls speed of enemy.
      });
    enemy_timer1->start();


    QTimer *parallax_timer = new QTimer();
       connect(parallax_timer,&QTimer::timeout,[=](){
        parallax_animation *para = new parallax_animation(view_item,scene_item);
        parallax_timer->setInterval(5000);
       });
    parallax_timer->start();


    start_game->one_time_params(enemy_timer1,view_item,scene_item,pause_screen,retry_screen);
}
