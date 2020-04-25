/*Written by Ajinkya Datalkar*/
#include "display.h"
#include "common_variables.h"
#include <QLabel>
#include <QMovie>

void display::set_display(QGraphicsScene *scene_item, QGraphicsView *view_item)
{
    qreal scalefactor = 1.0;
    view_item->setFixedSize(scalefactor*DISPLAY_WIDTH,scalefactor*DISPLAY_HEIGHT);
    scene_item->setSceneRect(0,0,DISPLAY_WIDTH,DISPLAY_HEIGHT);
    view_item->setStyleSheet("border-width: 0px; border-style: solid"); //view item by default leaves border.. this will remove unnecessary border
    start_screen->setBackgroundBrush(QBrush(QImage(":/images/play_background.jpg")));
    view_item->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view_item->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
}

