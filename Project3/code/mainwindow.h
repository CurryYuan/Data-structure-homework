#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "myitem.h"
#include "tree.h"
#include "mylabel.h"
#include "borndialog.h"
#include "marriagedialog.h"
#include "divorcedialog.h"
#include "diedialog.h"
#include "rootdialog.h"
#include <QMainWindow>
#include <QPainter>
#include <QGraphicsView>
#include <QLabel>
#include <QString>
#include <QToolTip>
#include <QHelpEvent>
#include <QVector>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    //void paint(node* root,int i);
protected:
    void paintEvent(QPaintEvent *event);
    //bool event(QEvent *event);
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void print(node* info);

    void on_pushButton_5_clicked();

private:
    Ui::MainWindow *ui;
    //QGraphicsScene scene;
    QPen pen;
    QBrush brush;
    Tree* tre;
    QVector<MyLabel*> store;
    void recursion(node* ptr);
};

#endif // MAINWINDOW_H
