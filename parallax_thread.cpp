/*Written by Ajinkya Datalkar*/
#include "parallax_thread.h"
#include <QLabel>
#include <QMovie>

parallax_thread::parallax_thread(QGraphicsScene *scene_item, QGraphicsView *view_item)
{
    this->start(QThread::LowPriority);

    QLabel *background_label = new QLabel();
    QMovie *background_movie = new QMovie;

    background_movie->setFileName(":/images/background.gif");
    background_movie->setCacheMode(QMovie::CacheAll);
    background_movie->start();
    background_label->setMovie(background_movie);
    background_label->setGeometry(0,0,view_item->width(),view_item->height());
    QGraphicsProxyWidget *background_parallax = scene_item->addWidget(background_label);
    background_parallax->setZValue(-1);
    scene_item->addItem(background_parallax);
}
