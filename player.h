/*Written by Ajinkya Datalkar*/
#ifndef ROCKET_H
#define ROCKET_H

#include "display.h"

class player: public QObject,public QGraphicsRectItem
{
    Q_OBJECT
public:
    static int rocket_pos;
    void rocket(QGraphicsScene *scene_item, QGraphicsView *view_item, QGraphicsScene *pause_screen, QGraphicsScene *retry_screen);
};

#endif // ROCKET_H
