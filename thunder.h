/*Written by Ajinkya Datalkar*/
#ifndef THUNDER_H
#define THUNDER_H

#include "display.h"
#include <QMovie>
#include <QLabel>

class thunder : public QTimer,public QGraphicsRectItem{
    Q_OBJECT
public:
    thunder();
    QMediaPlayer *thunderclap = new QMediaPlayer();

    QPixmap *lightning = new QPixmap(":/images/lightning.png");
    QPixmap *lightning2 = new QPixmap(":/images/lightning2.png");
    QPixmap *lightning3 = new QPixmap(":/images/lightning3.png");

    QGraphicsPixmapItem *thunder_box = new QGraphicsPixmapItem();
    QGraphicsPixmapItem *thunder_box2 = new QGraphicsPixmapItem();
    QGraphicsPixmapItem *thunder_box3 = new QGraphicsPixmapItem();

    void create_thunder(QGraphicsScene *scene_item, QTimer *timer);
};

#endif // THUNDER_H
