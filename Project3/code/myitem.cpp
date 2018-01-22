#include "myitem.h"

MyItem::MyItem(node* tr)
{
    root=tr;
}

QRectF MyItem::boundingRect() const
{
    qreal penWidth = 1;
    return QRectF(0 - penWidth / 2, 0 - penWidth / 2,
                  20 + penWidth, 20 + penWidth);
}

void MyItem::paint(QPainter *painter,
                   const QStyleOptionGraphicsItem *option,
                   QWidget *widget)
{
    Q_UNUSED(option);  //标明该参数没有使用
    Q_UNUSED(widget);

    painter->setBrush(Qt::red);
    if(root!=NULL){
        painter->drawRect(100,0,20,20);
        pain(root,painter,0);
    }

}

void MyItem::pain(node* root, QPainter *painter, int i)
{
    if(root==NULL)
        return;
    ++i;
    if(root->left!=NULL){
        painter->drawRect(100-i*50,i*50,20,20);
        pain(root->left,painter,i);
    }
    if(root->right!=NULL){
        painter->drawRect(100+i*50,i*50,20,20);
        pain(root->right,painter,i);
    }

}
