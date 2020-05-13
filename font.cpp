/*Written by Ajinkya Datalkar*/
#include "font.h"


fonts::fonts()
{
    QFontDatabase::addApplicationFont(":/fonts/game.ttf");
    this->setFamily("Lithos Pro");
    this->setPointSize(25);
    this->setBold(true);
}
