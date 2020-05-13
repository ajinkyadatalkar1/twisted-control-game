/*Written by Ajinkya Datalkar*/
#ifndef FIRST_SCREEN_H
#define FIRST_SCREEN_H

#include "display.h"

class buttons : public QPushButton,public QGraphicsView,public QGraphicsScene
{
public:
    void set_scene_buttons(QGraphicsView *view_item, QGraphicsScene *scene_item, QGraphicsScene *start_screen, QGraphicsScene *leaderboard);
};

#endif // FIRST_SCREEN_H
