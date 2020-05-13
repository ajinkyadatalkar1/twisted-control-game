#include "twisted_control.h"
#include "thunder.h"
#include "common_variables.h"
bool twisted_control::control_status = false;

void twisted_control::assign_keys(QGraphicsScene *scene_item, QGraphicsProxyWidget *rocket_item)
{
    QGraphicsProxyWidget *ctrl = scene_item->addWidget(btn1);
    QGraphicsProxyWidget *ctrr = scene_item->addWidget(btn2);
    QGraphicsProxyWidget *ctr = scene_item->addWidget(ctR);


    btn1->setStyleSheet("border: none; background-color: rgb(188,252,255);");
    btn2->setStyleSheet("border: none; background-color: rgb(188,252,255);");
    ctR->setStyleSheet("border: none; background-color: rgb(5,246,255);");

    btn1->setMinimumWidth(DISPLAY_WIDTH/3);
    btn2->setMinimumWidth(DISPLAY_WIDTH/3);
    ctR->setMinimumWidth(DISPLAY_WIDTH/3);

    btn1->setMinimumHeight(LEFT_RIGHT_MIN_HEIGHT);
    btn2->setMinimumHeight(LEFT_RIGHT_MIN_HEIGHT);

    ctr->setPos(DISPLAY_WIDTH/2 - ctR->rect().width()/2,DISPLAY_HEIGHT - ctr->rect().height()*2);
    ctrl->setPos(0,DISPLAY_HEIGHT - ctrl->rect().height()*2);
    ctrr->setPos(DISPLAY_WIDTH - ctR->rect().width(),DISPLAY_HEIGHT - ctrr->rect().height()*2);

    connect(ctR,&QPushButton::pressed,[=](){
        rocket_item->setPos(DISPLAY_WIDTH/2 - ROCKET_WIDTH/2,DISPLAY_HEIGHT - ROCKET_TOLERANCE_HEIGHT);
    });
}

void twisted_control::twist(QGraphicsProxyWidget *rocket_item)
{
        if(!control_status){
            btn1->setText("LEFT");
            connect(btn1,&QPushButton::pressed,[=](){
             rocket_item->setPos(ROCKET_TOLERANCE_WIDTH,DISPLAY_HEIGHT - ROCKET_TOLERANCE_HEIGHT);
            });

            btn2->setText("RIGHT");
            connect(btn2,&QPushButton::pressed,[=](){
             rocket_item->setPos(DISPLAY_WIDTH - ROCKET_WIDTH - ROCKET_TOLERANCE_WIDTH, DISPLAY_HEIGHT - ROCKET_TOLERANCE_HEIGHT);
            });
            control_status = true;
        }
        else{
            btn1->setText("RIGHT");
            connect(btn1,&QPushButton::pressed,[=](){
             rocket_item->setPos(DISPLAY_WIDTH - ROCKET_WIDTH - ROCKET_TOLERANCE_WIDTH, DISPLAY_HEIGHT - ROCKET_TOLERANCE_HEIGHT);
            });

            btn2->setText("LEFT");
            connect(btn2,&QPushButton::pressed,[=](){
             rocket_item->setPos(ROCKET_TOLERANCE_WIDTH,DISPLAY_HEIGHT - ROCKET_TOLERANCE_HEIGHT);
            });
            control_status = false;
        }
}
