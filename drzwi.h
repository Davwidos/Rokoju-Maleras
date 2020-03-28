#ifndef KARTA_H
#define KARTA_H

#include<QObject>
#include<QGraphicsItem>
#include<QTextStream>
#include<QString>

class Drzwi: public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Drzwi(QTextStream*,QGraphicsItem *parent=0);
    virtual void dzialanie()=0;
protected:
    int id;
    QString nazwa;
    QString srcObrazek;
};

class Potwor: public Drzwi
{
    Q_OBJECT
public:
    Potwor(QTextStream*,QGraphicsItem *parent=0);
    void dzialanie();
private:
    int sila;
    int idBonus;
    int wartoscBonusu;
    QString czymWalczyc;
    QString marnyKoniecTyp;
    int ileSkarbow;
};

#endif // KARTA_H
