/*Written by Ajinkya Datalkar*/
#include "thunder.h"

thunder::thunder()
{
    thunder_box->setPixmap(*lightning);
    thunder_box2->setPixmap(*lightning2);
    thunder_box3->setPixmap(*lightning3);

    thunder_box->setPos(0,0);
    thunder_box2->setPos(0,0);
    thunder_box3->setPos(0,0);

    thunder_box->setZValue(-1);
    thunder_box2->setZValue(-1);
    thunder_box3->setZValue(-1);
}

void thunder::create_thunder(QGraphicsScene *scene_item, QTimer *timer)
{
    QTimer *thunder_timer = new QTimer();   //do not create timer in the header file or outside the function it causes memory leaks as well as when the function is re-executed its address may be lost causing leaks
    static int animate_thunder = 1;

    thunderclap->setMedia(QUrl("qrc:/sounds/thunder.mp3"));
    thunderclap->setVolume(100);

    connect(thunder_timer,&QTimer::timeout,[=](){
        thunderclap->play();
        if(animate_thunder == 1){
           timer->stop();
           scene_item->addItem(thunder_box);
           qDebug() << "thunder 1";
           animate_thunder++;
        }
        else if(animate_thunder == 2){
            timer->start();
           scene_item->addItem(thunder_box2);
           scene_item->removeItem(thunder_box);
           qDebug() << "thunder 2";
           animate_thunder++;
        }
        else if(animate_thunder == 3){
           scene_item->addItem(thunder_box3);
           scene_item->removeItem(thunder_box2);
           qDebug() << "thunder 3";
           animate_thunder++;
        }
        else if(animate_thunder == 4){
           timer->stop();
           scene_item->addItem(thunder_box);
           scene_item->removeItem(thunder_box3);
           qDebug() << "thunder 4";
           animate_thunder++;
        }
        else{
            timer->start();
            scene_item->removeItem(thunder_box);
            animate_thunder = 1;
            qDebug() << "thunder 5";
            thunderclap->stop();
            thunder_timer->stop();
            delete thunder_timer;   // DELETE to release memory.
        }
    });
  thunder_timer->start(500);
}
