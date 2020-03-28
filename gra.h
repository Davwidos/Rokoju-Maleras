#ifndef GRA_H
#define GRA_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include<QPixmap>
#include<QAction>
#include<QMediaPlayer>
#include<QTextStream>
#include<QList>
#include<QGraphicsTextItem>
#include"drzwi.h"
#include"skarb.h"
#include"przycisk.h"

class Gra : public QGraphicsView
{
    Q_OBJECT
public:
    Gra(QWidget *parent=0);
    void displaymenu();
    void clear();
    void keyPressEvent(QKeyEvent *event);
public slots:
   void start();
   void wyjscie();
private:
    QGraphicsScene *scene;
    QMediaPlayer *bgmusic;
    QList<Skarb*> skarbList;
    QList<Drzwi*> drzwiList;
    QList<QGraphicsItem*> menu;
};
#endif // GRA_H
