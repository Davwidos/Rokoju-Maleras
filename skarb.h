#ifndef SKARB_H
#define SKARB_H

#include<QObject>
#include<QGraphicsItem>
#include<QTextStream>
#include<QString>

class Skarb: public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Skarb(QTextStream*,QGraphicsItem *parent=0);
    virtual void dzialanie()=0;
protected:
    int id;
    QString nazwa;
    QString srcObrazek;
    int wartosc;
};
#endif // SKARB_H
