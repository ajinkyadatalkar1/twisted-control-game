/*Written by Ajinkya Datalkar*/
#include "display.h"
#include "buttons.h"
#include <QLabel>
#include <QPixmap>
#include <QBrush>
#include <QImage>
#include <QMediaPlaylist>
#include <QSplashScreen>
#include "font.h"
#include "common_variables.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setFont(fonts());

    QSplashScreen splash(QPixmap(":/images/rocket.gif"));
    splash.show();

    QSettings *settings = new QSettings("BrainFreezeGames","Twisted Control");
    settings->beginGroup("in_app_parameters");
    settings->setValue("status",0);
    settings->setValue("play",0);
    qDebug() << settings->value("status").toString();
    qDebug() << settings->value("play").toString();
    settings->endGroup();



    display *set_disp_params = new display();
    set_disp_params->set_display(set_disp_params->start_screen,set_disp_params->view);


    //set_disp_params->scene->setBackgroundBrush(QBrush(QImage(":/images/background.jpg")));



    buttons *scene_btns = new buttons();
    scene_btns->set_scene_buttons(set_disp_params->view,set_disp_params->scene,set_disp_params->start_screen,set_disp_params->leaderboard);

    QMediaPlaylist *playlist = new QMediaPlaylist();
    playlist->addMedia(QUrl("qrc:/sounds/bg_music.mp3"));
    playlist->setPlaybackMode(QMediaPlaylist::Loop);

    QMediaPlayer *bg_music = new QMediaPlayer();
    bg_music->setMedia(playlist);
    bg_music->setVolume(100);
    bg_music->play();

    splash.finish(set_disp_params->view);

    set_disp_params->view->showFullScreen();
    return a.exec();
}
