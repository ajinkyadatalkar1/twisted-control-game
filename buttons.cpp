/*Written by Ajinkya Datalkar*/
#include "buttons.h"
#include "player.h"
#include "common_variables.h"
#include <QIcon>

void buttons::set_scene_buttons(QGraphicsView *view_item, QGraphicsScene *scene_item,QGraphicsScene *start_screen,QGraphicsScene *leaderboard)
{
    display *set_disp_params = new display();
    QGraphicsScene *pause_screen = new QGraphicsScene();
    pause_screen->setBackgroundBrush(QBrush(QImage(":/images/background.jpg")));

    QGraphicsScene *retry_screen = new QGraphicsScene();
    retry_screen->setBackgroundBrush(QBrush(QImage(":/images/background.jpg")));


    set_disp_params->set_display(scene_item,view_item);
    set_disp_params->set_display(leaderboard,view_item);
    set_disp_params->set_display(pause_screen,view_item);
    set_disp_params->set_display(retry_screen,view_item);

    QPixmap play_btn_pixmap(":/images/play_button.png");
    QPixmap quit_btn_pixmap(":/images/quit_button.png");

    QIcon play_btn_icon(play_btn_pixmap);
    QIcon quit_btn_icon(quit_btn_pixmap);

    QPushButton *play = new QPushButton();
    play->setIcon(play_btn_icon);
    play->setIconSize(play_btn_pixmap.rect().size());
    play->setStyleSheet("border: none;");
    play->setAttribute(Qt::WA_TranslucentBackground, true);

    QGraphicsProxyWidget *play_btn = start_screen->addWidget(play);
    play_btn->setPos(view_item->width()/4, view_item->height()/1.5);

    QPushButton *close_app = new QPushButton();
    close_app->setStyleSheet("border: none;");
    close_app->setIcon(quit_btn_icon);
    close_app->setIconSize(quit_btn_pixmap.rect().size());
    close_app->setAttribute(Qt::WA_TranslucentBackground, true);

    QGraphicsProxyWidget *close_btn = start_screen->addWidget(close_app);
    close_btn->setPos(view_item->width()/4, view_item->height()/1.2);


    QPushButton *home_button = new QPushButton("Home");
    home_button->setStyleSheet("border: none;background-color: rgb(188,252,255); width: 200px; height: 100px;");
    QPushButton *home_button2 = new QPushButton("Home");
    home_button2->setStyleSheet("border: none;background-color: rgb(188,252,255); width: 200px; height: 100px;");
    QGraphicsProxyWidget *home_proxy = pause_screen->addWidget(home_button);
    QGraphicsProxyWidget *home_proxy2 = retry_screen->addWidget(home_button2);

    home_proxy->setPos(DISPLAY_WIDTH - home_button->rect().width() - 10,0);
    home_proxy2->setPos(DISPLAY_WIDTH - home_button->rect().width() - 10,0);

    QObject::connect(home_button,&QPushButton::clicked,[=](){
        view_item->setScene(start_screen);
        QSettings *settings = new QSettings("BrainFreezeGames","Twisted Control");
        settings->beginGroup("in_app_parameters");
        settings->setValue("status",1);
        settings->endGroup();
    });

    QObject::connect(home_button2,&QPushButton::clicked,[=](){
        view_item->setScene(start_screen);
        QSettings *settings = new QSettings("BrainFreezeGames","Twisted Control");
        settings->beginGroup("in_app_parameters");
        settings->setValue("status",1);
        settings->endGroup();
    });

    QObject::connect(play,&QPushButton::clicked,[=](){
        QSettings *settings = new QSettings("BrainFreezeGames","Twisted Control");
        settings->beginGroup("in_app_parameters");
        qDebug() << "status" + settings->value("status").toString();
        qDebug() << "play" + settings->value("play").toString();
        if(!settings->value("status").toInt()){
        settings->setValue("play",0);
        view_item->setScene(scene_item);
        player *rocket_link = new player();
        rocket_link->rocket(scene_item,view_item,pause_screen,retry_screen);
        qDebug() << "executing if";
        }
        else if(settings->value("status").toInt()){
            view_item->setScene(scene_item);
            settings->setValue("status",0);
            settings->setValue("play",1);
            qDebug() << "executing elif";
        }
        settings->endGroup();
    });

    QObject::connect(close_app,&QPushButton::clicked,[=](){
        QSettings *settings = new QSettings("BrainFreezeGames","Twisted Control");
        settings->endGroup();
        qApp->quit();
    });
}
