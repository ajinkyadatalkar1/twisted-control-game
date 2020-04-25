/*Written by Ajinkya Datalkar*/
#ifndef DISPLAY_H
#define DISPLAY_H

#include <QWidget>
#include <QApplication>
#include <QObject>
#include <QList>
#include <QDebug>
#include <QTimer>
#include <QPushButton>
#include <QDesktopWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QRect>
#include <QGraphicsItem>
#include <QGraphicsRectItem>
#include <QGraphicsProxyWidget>
#include <QGraphicsTextItem>
#include <QGraphicsPixmapItem>
#include <QSettings>
#include <QBrush>
#include <QImage>
#include <QColor>
#include <QMovie>
#include <QSoundEffect>
#include <QMediaPlayer>
#include <QFont>
#include <QFontDatabase>

class display:public QDesktopWidget,public QGraphicsRectItem{
    Q_OBJECT
public:
    void set_display(QGraphicsScene *scene_item, QGraphicsView *view_item);
    QGraphicsScene *scene = new QGraphicsScene();
    QGraphicsScene *start_screen = new QGraphicsScene();
    QGraphicsScene *leaderboard = new QGraphicsScene();
    QGraphicsView *view = new QGraphicsView(start_screen);
};


#endif // DISPLAY_H
