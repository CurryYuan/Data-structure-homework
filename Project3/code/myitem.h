#ifndef MYITEM_H
#define MYITEM_H
#include "tree.h"
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QPainter>

class MyItem : public QGraphicsItem
{
public:
    MyItem(node* tr);
    QRectF boundingRect() const;
    void paint(QPainter *painter,const QStyleOptionGraphicsItem *option,
               QWidget *widget);
private:
    node* root;
    void pain(node* root, QPainter *painter, int i);
};

#endif // MYITEM_H
