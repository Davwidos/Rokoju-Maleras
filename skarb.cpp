#include"skarb.h"

Skarb::Skarb(QTextStream *plik, QGraphicsItem *parent): QObject(),QGraphicsPixmapItem(parent)
{
    id=plik->readLine().toInt();
    nazwa=plik->readLine().toUpper();
    srcObrazek=plik->readLine();
    setPixmap(srcObrazek);
    wartosc=plik->readLine().toInt();
}
