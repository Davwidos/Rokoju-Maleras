#include "gra.h"
#include<QApplication>
#include<QDesktopWidget>
#include<QKeyEvent>
#include<QFile>
#include<QBrush>

Gra::Gra(QWidget *parent) //co się dzieje po stworzeniu obiektu gra
{
    //konfigurowanie wyświetlanego ekranu
    QRect rec=QApplication::desktop()->screenGeometry();
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,rec.width(),rec.height());
    setBackgroundBrush(QBrush(QImage(":/images/bg.jpg").scaled(rec.width(),rec.height())));
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(rec.width(),rec.height());
    setScene(scene);

    //konfigurowanie menu
    QGraphicsTextItem *titleText=new QGraphicsTextItem(QString("Rokoju Maleras"));
    titleText->setDefaultTextColor(Qt::green);
    QFont titleFont("algerian",50);
    titleText->setFont(titleFont);
    int txP=this->width()/2-titleText->boundingRect().width()/2;
    int tyP=0;

    titleText->setPos(txP,tyP);
    menu.insert(menu.end(),titleText);
    Przycisk *przyciskGraj=new Przycisk(QString("Graj"));
    int bxP=this->width()/2-przyciskGraj->boundingRect().width()/2;
    int byP=100;
    przyciskGraj->setPos(bxP,byP);
    connect(przyciskGraj,SIGNAL(clicked()),this,SLOT(start()));
    menu.insert(menu.end(),przyciskGraj);

    Przycisk *przyciskWyjscie=new Przycisk(QString("Wyjscie"));
    bxP=this->width()/2-przyciskWyjscie->boundingRect().width()/2;
    byP=250;
    przyciskWyjscie->setPos(bxP,byP);
    connect(przyciskWyjscie,SIGNAL(clicked()),this,SLOT(wyjscie()));
    menu.insert(menu.end(),przyciskWyjscie);

    //konfigurowanie muzuki w tle
    bgmusic=new QMediaPlayer();
    bgmusic->setMedia(QUrl("qrc:/sounds/bgsound.mp3"));

    //tworzenie kart drzwi na podstawie danych z pliku
    QFile data;
    data.setFileName(":/text/drzwi.txt");
    data.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream karty(&data);
    QString typDzialania;
    for(Drzwi *d;!karty.atEnd();)
    {
        typDzialania=karty.readLine();
        if(typDzialania=="potwor")
        {
            d=new Potwor(& karty);
        }
        drzwiList.insert(drzwiList.end(),d);
    }

}
void Gra::displaymenu() // wyświetlanie menu
{
    bgmusic->stop();
    clear();
    for(QGraphicsItem *m:menu) scene->addItem(m);

}
void Gra::start() //co sie dzieje po wczisnięciu przycisku w menu: Graj
{
    clear();
    bgmusic->play();
    for(Drzwi *k:drzwiList)
    {
        k->setPos(0,0);
        scene->addItem(k);
    }

}
void Gra::keyPressEvent(QKeyEvent *event) //obsuga zdarzeń zwiazanych z klawiatura
{
    if(event->key()==Qt::Key_Escape)
        displaymenu();
}
void Gra::clear() //czyszczenie ekranu z obiektów
{
    for(QGraphicsItem *m:items())
        if(m->parentItem()==0) scene->removeItem(m);
}
void Gra::wyjscie() //co się dzieje po wcisnieciu przycisku w menu: Wyjscie
{
    QApplication::quit();
}
