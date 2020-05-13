/*Written by Ajinkya Datalkar*/
#ifndef THREAD_H
#define THREAD_H

#include <QThread>
#include "display.h"
#include "enemy.h"
#include "thunder.h"
#include "twisted_control.h"
#include "buttons.h"
class threads : public QThread {
  public:
    threads(QGraphicsView *view_item, QGraphicsScene *scene_item, QGraphicsScene *retry_screen, QGraphicsScene *pause_screen,  QGraphicsProxyWidget *rocket_item);
};

#endif // THREAD_H
