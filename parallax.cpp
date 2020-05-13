/*Written by Ajinkya Datalkar*/
#include "parallax.h"
#include "common_variables.h"

bool parallax::scroll_status1 = false;
bool parallax::scroll_status2 = false;


parallax::parallax(QGraphicsView *view_item, QGraphicsScene *scene_item)
{
// setting one time parameters
    parallax_pixmap1->setPixmap(QPixmap(":/images/background.jpg"));
    scene_item->addItem(parallax_pixmap1);
    parallax_pixmap1->setPos(0,0);
    parallax_pixmap1->setZValue(-3);

    step_size1 = QPixmap::fromImage(QImage(":/images/background.jpg")).height()/20;

    parallax_pixmap2->setPixmap(QPixmap(":/images/background.jpg"));
    scene_item->addItem(parallax_pixmap2);
    parallax_pixmap2->setPos(0, -QPixmap::fromImage(QImage(":/images/background.jpg")).height());
    parallax_pixmap2->setZValue(-3);
    step_size2 = QPixmap::fromImage(QImage(":/images/background.jpg")).height()/20;
}

void parallax::parallax_effect()
{
    if(scroll_status1){
        parallax_pixmap1->setPos(0,-QPixmap::fromImage(QImage(":/images/background.jpg")).height());
        scroll_status1 = false;
        parallax_pixmap1->setZValue(-3);
    }
    else {
      parallax_pos1 = parallax_pixmap1->y();
      parallax_pixmap1->setPos(0,parallax_pos1 + step_size1);
      parallax_pos1 >= QPixmap::fromImage(QImage(":/images/background.jpg")).height() ? scroll_status1 = true : scroll_status1 =false;
    }
//--------------------------------------------------------
    if(scroll_status2){
        parallax_pixmap2->setPos(0,-QPixmap::fromImage(QImage(":/images/background.jpg")).height());
        scroll_status1 = false;
        parallax_pixmap2->setZValue(-3);
    }
    else{
        parallax_pos2 = parallax_pixmap2->y();
        parallax_pixmap2->setPos(0,parallax_pos2 + step_size2);
        parallax_pos2 >= QPixmap::fromImage(QImage(":/images/background.jpg")).height() ? scroll_status2 = true : scroll_status2 =false;
    }
}
