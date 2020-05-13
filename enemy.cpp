/*Written by Ajinkya Datalkar*/
#include "enemy.h"
#include "thunder.h"
#include <QLabel>
#include <QDialog>
#include <QSettings>
#include <QSize>
#include <QPixmap>
#include <QThread>
#include "twisted_control.h"
#include "font.h"
#include "common_variables.h"


int enemy::score=0;
int enemy::pause_param=0;
int enemy::collision_param=0;
int enemy::retry_status=1;

int enemy::pos_c1=0;
int enemy::pos_c2=0;
int enemy::pos_c3=0;

int enemy::pos_p1=0;
int enemy::pos_p2=0;
int enemy::pos_p3=0;

bool enemy::enemy_end1 = true;
bool enemy::enemy_end2 = true;
bool enemy::enemy_end3 = true;

bool enemy::slow_end = true;
bool enemy::medium_end = true;
bool enemy::fast_end = true;

int enemy::switch_place=3;
int enemy::speed_control=100;

enemy::enemy(QGraphicsScene *scene_item,QGraphicsScene *pause_screen,QGraphicsScene *retry_screen)
{
    pos_c1 = DISPLAY_HEIGHT/20;
    pos_c2 = DISPLAY_HEIGHT/20;
    pos_c3 = DISPLAY_HEIGHT/20;

    QPixmap rock_pixmap_scaled = QPixmap::fromImage(QImage(":/images/rock.png")).scaled(ENEMY_ROCK_WIDTH,ENEMY_ROCK_HEIGHT);

//Position one parameters
    enemy_rocket1->setZValue(-1);
    enemy_rocket1->setPixmap(rock_pixmap_scaled);
    enemy_rocket1->setPos(0,-200);

//Position two parameters
    enemy_rocket2->setZValue(-1);
    enemy_rocket2->setPixmap(rock_pixmap_scaled);
    enemy_rocket2->setPos(0,-200);

//Position three parameters
     enemy_rocket3->setZValue(-1);
     enemy_rocket3->setPixmap(rock_pixmap_scaled);
     enemy_rocket3->setPos(0,-200);

//engine_1 pack parameters
     engine_1->setZValue(-1);
     engine_1->setPixmap(QPixmap::fromImage(QImage(":/images/slow.png")));
     engine_1->setPos(0,-200);

//engine_2 parameters
     engine_2->setPixmap(QPixmap::fromImage(QImage(":/images/engine_2.png")));
     engine_2->setZValue(-1);

//speed slow parameters
     engine_3->setPixmap(QPixmap::fromImage(QImage(":/images/engine_3.png")));
     engine_3->setZValue(-1);

//pause function parameters
    pause_game->setStyleSheet("border: none;background-color: rgb(188,252,255); width: 200px; height: 100px;");
    pause_btn->setWidget(pause_game);
    scene_item->addItem(pause_btn);
    pause_btn->setPos(DISPLAY_WIDTH - pause_btn->rect().width(),0);

//resume function parameters
    resume->setStyleSheet("border: none;background-color: rgb(188,252,255); width: 200px; height: 100px;");
    resume_btn->setWidget(resume);
    pause_screen->addItem(resume_btn);
    resume_btn->setPos(DISPLAY_WIDTH/2 - resume_btn->rect().width()/2,0);

//retry function parameters
    retry->setStyleSheet("border: none;background-color: rgb(188,252,255); width: 200px; height: 100px;");
    retry_btn->setWidget(retry);
    retry_screen->addItem(retry_btn);
    retry_btn->setPos(DISPLAY_WIDTH/2 - retry->rect().width()/2,0);

//QSetting parameters
    settings->beginGroup("in_app_parameters");
}

void enemy::pause_func(QTimer *timer,QGraphicsView *view_item,QGraphicsScene *pause_screen)
{   
    connect(pause_game,&QPushButton::clicked,[=](){
        if(timer->isActive()){
            timer->stop();
            pause_param=1;
            view_item->setScene(pause_screen);
        }
    });
}

void enemy::resume_func(QTimer *timer,QGraphicsView *view_item,QGraphicsScene *scene_item)
{
    connect(resume,&QPushButton::clicked,[=](){
        pause_param=0;
        view_item->setScene(scene_item);
        timer->start();
    });
}

void enemy::enemy_resume(QTimer *timer)
{
    QTimer *enemy_resume_check = new QTimer();// this timer does not hamper any performance as it gets destroyed in this function itself
    connect(enemy_resume_check,&QTimer::timeout,[=](){
        if(timer->isActive() && pause_param == 1){
           timer->stop();
        }
        else if(!pause_param){
           timer->start();
           enemy_resume_check->stop();
           delete enemy_resume_check;
       }
    });
    enemy_resume_check->start(10);
}

void enemy::stopmaintimer(QTimer *timer,QGraphicsScene *retry_screen,QGraphicsView *view_item)
{
    if(pause_param && collision_param){
    view_item->setScene(retry_screen);
    timer->stop();
    }
}

int enemy::position1(QGraphicsScene *scene_item,QGraphicsProxyWidget *rocket_item)
{
    if(enemy_end1){
    scene_item->addItem(enemy_rocket1);
    enemy_rocket1->setPos(0, -100);
    enemy_end1 = false;
    }
    else{
            enemy_rocket1->setPos(0, pos_c1);
            pos_c1+=DISPLAY_HEIGHT/20;
            if(pos_c1 >= DISPLAY_HEIGHT - QPixmap::fromImage(QImage(":/images/rock.png")).height())
            {
                score+=2;
                pos_c1=DISPLAY_HEIGHT/20;
                scene_item->removeItem(enemy_rocket1);
                enemy_end1 = true;
            }
            else if(enemy_rocket1->collidesWithItem(rocket_item))
            {
                pos_c1=DISPLAY_HEIGHT/20;
                scene_item->removeItem(enemy_rocket1);
                pause_param=1;
                collision_param=1;
                enemy_end1 = true;
             }
    }
}

int enemy::position2(QGraphicsScene *scene_item,QGraphicsProxyWidget *rocket_item)
{
    if(enemy_end2){
    scene_item->addItem(enemy_rocket2);
    enemy_rocket2->setPos(DISPLAY_WIDTH/3 + 50, -100);
    enemy_end2 = false;
    }
    else{
        enemy_rocket2->setPos(DISPLAY_WIDTH/3 + 50, pos_c2);
        pos_c2+=DISPLAY_HEIGHT/20; //increasing the denominator will decrease the speed... this is the step size
        if(pos_c2 >= DISPLAY_HEIGHT - QPixmap::fromImage(QImage(":/images/rock.png")).height())
        {
            score+=2;
            scene_item->removeItem(enemy_rocket2);
            qDebug()<<"enemy destroyed";
            pos_c2=DISPLAY_HEIGHT/20;
            enemy_end2 = true;
        }
        else if(enemy_rocket2->collidesWithItem(rocket_item)){
            scene_item->removeItem(enemy_rocket2);
            pos_c2=DISPLAY_HEIGHT/20;
            pause_param=1;
            collision_param=1;
            enemy_end2 = true;
        }
    }
}

int enemy::position3(QGraphicsScene *scene_item, QGraphicsProxyWidget *rocket_item)
{
    if(enemy_end3){
    scene_item->addItem(enemy_rocket3);
    enemy_rocket3->setPos(DISPLAY_WIDTH - 300, -100);
    enemy_end3 = false;
    }
    else{
      enemy_rocket3->setPos(DISPLAY_WIDTH - 300,pos_c3);
      pos_c3+=DISPLAY_HEIGHT/20;
      if(pos_c3 >= DISPLAY_HEIGHT - QPixmap::fromImage(QImage(":/images/rock.png")).height())
      {
          score+=2;
          scene_item->removeItem(enemy_rocket3);
          pos_c3=DISPLAY_HEIGHT/20;
          enemy_end3 = true;
       }
       else if(enemy_rocket3->collidesWithItem(rocket_item)){
           scene_item->removeItem(enemy_rocket3);
           pos_c3=DISPLAY_HEIGHT/20;
           pause_param=1;
           collision_param=1;
           enemy_end3 = true;
       }
    }
}

int enemy::slow(QGraphicsScene *scene_item, QGraphicsProxyWidget *rocket_item)
{

    //will come at position 3

    if(slow_end){
    scene_item->addItem(engine_1);
    engine_1->setPos(DISPLAY_WIDTH - 300, -100);
    slow_end = false;
    }
    else{
      engine_1->setPos(DISPLAY_WIDTH - 300,pos_p1);
      pos_p1+=DISPLAY_HEIGHT/25;
      if(pos_p1 >= DISPLAY_HEIGHT - ENGINE_HEIGHT)
      {
          score+=2;
          scene_item->removeItem(engine_1);
          pos_p1=DISPLAY_HEIGHT/20;
          slow_end = true;
       }
       else if(engine_1->collidesWithItem(rocket_item)){
           scene_item->removeItem(engine_1);
           pos_p1=DISPLAY_HEIGHT/20;
           slow_end = true;
           speed_control = 150;
       }
    }

}

int enemy::medium(QGraphicsScene *scene_item, QGraphicsProxyWidget *rocket_item)
{

    //will come at position 2
    if(medium_end){
    scene_item->addItem(engine_2);
    engine_2->setPos(DISPLAY_WIDTH/3 + 50, -100);
    medium_end = false;
    }
    else{
      engine_2->setPos(DISPLAY_WIDTH/3 + 50,pos_p2);
      pos_p2+=DISPLAY_HEIGHT/25;
      if(pos_p2 >= DISPLAY_HEIGHT - ENGINE_HEIGHT)
      {
          score+=2;
          scene_item->removeItem(engine_2);
          pos_p2=DISPLAY_HEIGHT/20;
          medium_end = true;
       }
       else if(engine_2->collidesWithItem(rocket_item)){
           scene_item->removeItem(engine_2);
           pos_p2=DISPLAY_HEIGHT/20;
           medium_end = true;
           speed_control = 100;
       }
    }
}

int enemy::fast(QGraphicsScene *scene_item, QGraphicsProxyWidget *rocket_item)
{

    //will come at position 1
    if(fast_end){
    scene_item->addItem(engine_3);
    engine_3->setPos(0, -100);
    fast_end = false;
    }
    else{
      engine_3->setPos(0,pos_p3);
      pos_p3+=DISPLAY_HEIGHT/25;
      if(pos_p3 >= DISPLAY_HEIGHT - ENGINE_HEIGHT)
      {
          score+=2;
          scene_item->removeItem(engine_3);
          pos_p3=DISPLAY_HEIGHT/20;
          fast_end = true;
       }
       else if(engine_3->collidesWithItem(rocket_item)){
           scene_item->removeItem(engine_3);
           pos_p3=DISPLAY_HEIGHT/20;
           fast_end = true;
           speed_control = 75;
       }
    }
}

void enemy::save_score()
{
   if(settings->value("hscore").toInt() < score){
   settings->setValue("hscore", score);
   }
}

void enemy::retry_func(QGraphicsView *view_item,QGraphicsScene *scene_item,QTimer *timer)
{
    connect(retry,&QPushButton::clicked,[=](){
        qDebug() << "Health:" << settings->value("health").toInt();
        if(!timer->isActive()){
            scene_item->removeItem(enemy_rocket1);
            scene_item->removeItem(enemy_rocket2);
            scene_item->removeItem(enemy_rocket3);
            pause_param=0;
            collision_param=0;
            score=0;
            settings->setValue("play",0);
            settings->setValue("status",0);
            view_item->setScene(scene_item);
            timer->start();
        }
        else{
            qDebug() << "You don't have any life left.";
        }
    });
}

void enemy::update_score(QTimer *timer)
{

    QString s = QString::number(score);
    if(!timer->isActive() && settings->value("play").toInt()){
        pause_param = 0;
        collision_param = 0;
        score= 0;
        timer->start();
        settings->setValue("play",0);
        settings->setValue("status",0);
        qDebug() << "Executed";
    }

    save_score();
    //score_label->setHtml("Score:" + s);
    score_label->setHtml("<div style='background-color:#666666;'> Score:" + s + "</div>");
    high_score->setPlainText("HighScore:" + settings->value("hscore").toString());
    high_score2->setPlainText("HighScore:" + settings->value("hscore").toString());

}

void enemy::one_time_params(QTimer *timer, QGraphicsView *view_item, QGraphicsScene *scene_item, QGraphicsScene *pause_screen,QGraphicsScene *retry_screen)
{
    scene_item->addItem(score_label);
    pause_screen->addItem(high_score);
    retry_screen->addItem(high_score2);

    retry_func(view_item,scene_item,timer);
    pause_func(timer,view_item,pause_screen);
    resume_func(timer,view_item,scene_item);
}

void enemy::enemy_params(QGraphicsView *view_item, QGraphicsScene *scene_item,QGraphicsScene *retry_screen,QGraphicsScene *pause_screen,QGraphicsProxyWidget *rocket_item,QTimer *timer){


    timer->setInterval(speed_control);
    update_score(timer);
    if(!enemy_end1){
        position1(scene_item,rocket_item);
    }


    if(!enemy_end2){
        position2(scene_item,rocket_item);
    }


    if(!enemy_end3){
        position3(scene_item,rocket_item);
    }

    if(!slow_end){
          slow(scene_item,rocket_item);
    }

    if(!fast_end){
          fast(scene_item,rocket_item);
    }

    if(!medium_end){
          medium(scene_item,rocket_item);
    }


    if(enemy_end1 && enemy_end2 && enemy_end3 && slow_end && fast_end && medium_end){
        switch_place = rand()%10;
    }


    switch (switch_place) {
    case 1:
        if(enemy_end1 == false && enemy_end3 == false){
            position1(scene_item,rocket_item);
            position3(scene_item,rocket_item);
            }
            break;
    case 2:
            if(enemy_end1 && enemy_end2){
            position1(scene_item,rocket_item);
            position2(scene_item,rocket_item);
            }
            break;
    case 3:
            if(enemy_end3 && enemy_end2){
            position2(scene_item,rocket_item);
            position3(scene_item,rocket_item);
            }
            break;
    case 4:
            if(enemy_end1){
            position1(scene_item,rocket_item);
            }
            break;
    case 5:
            if(enemy_end2){
            position2(scene_item,rocket_item);
            }
            break;
    case 6:
            if(enemy_end3)
            {
            position3(scene_item,rocket_item);
            }
            break;
    case 7:
        if(fast_end){
            fast(scene_item,rocket_item);
        }
        break;

    case 8:
        if(medium_end){
            medium(scene_item,rocket_item);
        }
        break;

   case 9:
        if(slow_end){
            slow(scene_item,rocket_item);
        }
        break;

    default:
        qDebug() << "default";
    }
    stopmaintimer(timer,retry_screen,view_item);
}
