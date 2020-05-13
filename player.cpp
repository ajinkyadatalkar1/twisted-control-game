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

    QLabel *rocket_label = new QLabel;
    rocket_label->setAttribute(Qt::WA_TranslucentBackground, true);
    QMovie *rocket_movie = new QMovie;
    rocket_movie->setFileName(":/images/rocket.gif");
    rocket_movie->setCacheMode(QMovie::CacheAll);
    rocket_movie->start();
    rocket_label->setMovie(rocket_movie);
    QGraphicsProxyWidget *rocket_widget = scene_item->addWidget(rocket_label);
    rocket_widget->setPos(DISPLAY_WIDTH/2 - QPixmap::fromImage(QImage(":/images/rocket.png")).width()/2,DISPLAY_HEIGHT - 700);
    rocket_widget->setFlag(QGraphicsItem::ItemIsFocusable);
    rocket_widget->setFocus();
    rocket_widget->setZValue(-1);
    scene_item->addItem(rocket_widget);


    threads *t = new threads(view_item,scene_item,retry_screen,pause_screen,rocket_widget);
}
