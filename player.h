<<<<<<< HEAD
/*Written by Ajinkya Datalkar*/
=======
>>>>>>> 3923d1ae76dffce459d9593948cf8405efe9892c
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
