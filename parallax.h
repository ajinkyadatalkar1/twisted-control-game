/*Written by Ajinkya Datalkar*/
#ifndef PARALLAX_H
#define PARALLAX_H

#include "display.h"

class parallax {

public:
    static bool scroll_status1;
    static bool scroll_status2;

    int parallax_pos1;
    int parallax_pos2;

    int step_size1;
    int step_size2;

    void parallax_effect();
    parallax(QGraphicsView *view_item, QGraphicsScene *scene_item);

    QGraphicsPixmapItem *parallax_pixmap1 = new QGraphicsPixmapItem;
    QGraphicsPixmapItem *parallax_pixmap2 = new QGraphicsPixmapItem;
};

#endif // PARALLAX_H
