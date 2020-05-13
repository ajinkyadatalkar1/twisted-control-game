#ifndef TWISTED_CONTROL_H
#define TWISTED_CONTROL_H

#include "display.h"

class twisted_control : public QTimer,public QGraphicsRectItem
{
public:
    void twist(QGraphicsProxyWidget *rocket_item);
    QPushButton *btn2 = new QPushButton("Right");
    QPushButton *btn1 = new QPushButton("Left");
    QPushButton *ctR = new QPushButton("Centre");

    static bool control_status;

    void assign_keys(QGraphicsScene *scene_item, QGraphicsProxyWidget *rocket_item);
};

#endif // TWISTED_CONTROL_H
