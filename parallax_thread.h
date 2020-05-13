/*Written by Ajinkya Datalkar*/
#ifndef PARALLAX_THREAD_H
#define PARALLAX_THREAD_H

#include "display.h"
#include <QThread>

class parallax_thread : public QThread {
public:
    parallax_thread(QGraphicsScene *scene_item, QGraphicsView *view_item);
};


#endif // PARALLAX_THREAD_H
