#ifndef PLAYER_H
#define PLAYER_H

#include"drzwi.h"
#include"skarb.h"
#include<QList>

class Player: public QObject
{
    Q_OBJECT
public:
    Player();
private:
    int poziom=1;
    int stalyBonus=0;
    int chwilowyBonus=0;
    QList<Skarb*> skarbyNaRece;
    QList<Skarb*> aktywneSkarby;
    QList<Skarb*> nieaktywneSkarby;
    QList<Drzwi*> drzwiNarece;
};

#endif // PLAYER_H
