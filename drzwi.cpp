#include "drzwi.h"

//wczytanie statystyk kart przy tworzeniu obiektu drzwi
Drzwi::Drzwi(QTextStream *plik, QGraphicsItem *parent): QObject(),QGraphicsPixmapItem(parent)
{
    id=plik->readLine().toInt();
    nazwa=plik->readLine().toUpper();
    srcObrazek=plik->readLine();
    setPixmap(srcObrazek);
}
Potwor::Potwor(QTextStream *plik,QGraphicsItem *parent): Drzwi(plik,parent)
{
    sila=plik->readLine().toInt();
    idBonus=plik->readLine().toInt();
    wartoscBonusu=plik->readLine().toInt();
    czymWalczyc=plik->readLine();
    marnyKoniecTyp=plik->readLine();
    ileSkarbow=plik->readLine().toInt();
}

void Potwor::dzialanie()
{
}




