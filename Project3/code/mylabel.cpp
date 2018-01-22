#include "mylabel.h"

MyLabel::MyLabel(const QString& text,QWidget* parent)
    :QLabel(parent)
{
    setText(str);
    info=NULL;
}

MyLabel::~MyLabel()
{

}

void MyLabel::mousePressEvent(QMouseEvent *event)
{

    emit clicked(info);
}

void MyLabel::setInfo(node *in)
{
    info=in;
}
