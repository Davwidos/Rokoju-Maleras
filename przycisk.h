#ifndef PRZYCISK_H
#define PRZYCISK_H

#include <QGraphicsSceneMouseEvent>
#include <QGraphicsRectItem>
#include<QMediaPlayer>
class Przycisk:public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    Przycisk(QString nazwa,QGraphicsItem *parent=0);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event);
signals:
    void clicked();
private:
    QGraphicsTextItem *text;
};
#endif // PRZYCISK_H
