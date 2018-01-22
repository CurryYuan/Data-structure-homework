#ifndef MYLABEL_H
#define MYLABEL_H
#include <QLabel>
#include <QWidget>
#include <QObject>
#include "tree.h"

class MyLabel : public QLabel
{
    Q_OBJECT
public:
    MyLabel(const QString& text="", QWidget* parent=0);
    ~MyLabel();
    void setInfo(node* in);
signals:
    void clicked(node* info);
protected:
    void mousePressEvent(QMouseEvent* event);
private:
    node* info;
    QString str;
};

#endif // MYLABEL_H
