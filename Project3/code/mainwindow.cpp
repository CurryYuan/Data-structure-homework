#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    tre=new Tree;
    brush.setColor(Qt::black);
    brush.setStyle(Qt::SolidPattern);


    ui->setupUi(this);
    this->setWindowTitle("Genealogy");
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::paintEvent(QPaintEvent *event)
{
    tre->set();
    for(int i=0;i<store.size();++i){
        delete store[i];
        store[i]=NULL;
    }
    store.clear();
    recursion(tre->getRoot());
}

void MainWindow::on_pushButton_clicked()
{
    MarriageDialog f(this);
    f.setWindowTitle("Marriage");
    int ret=f.exec();
    if(ret==QDialog::Accepted){
        ui->textEdit->setText(QString::fromStdString(tre->marriage(f.a,f.b)));
        update();
    }
    else{}
}

void MainWindow::on_pushButton_2_clicked()
{
    BornDialog f(this);
    f.setWindowTitle("Born");

    int ret=f.exec();
    if(ret==QDialog::Accepted){
        ui->textEdit->setText(QString::fromStdString(tre->born(f.a,f.b,f.c,f.d)));
        update();
    }
    else{}
}

void MainWindow::on_pushButton_3_clicked()
{
    DivorceDialog f(this);
    int ret=f.exec();
    if(ret==QDialog::Accepted){
        ui->textEdit->setText(QString::fromStdString(tre->divorce(f.a,f.b)));
        update();
    }
    else{}
}

void MainWindow::on_pushButton_4_clicked()
{
    DieDialog f(this);
    int ret=f.exec();
    if(ret==QDialog::Accepted){
        ui->textEdit->setText(QString::fromStdString(tre->die(f.a)));
        update();
    }
    else{}
}

void MainWindow::on_pushButton_5_clicked()
{
    RootDialog f(this);
    int ret=f.exec();
    if(ret==QDialog::Accepted){
        ui->textEdit->setText(QString::fromStdString(tre->createRoot(f.a)));
        update();
    }
    else{}

}

void MainWindow::recursion(node* ptr){
    if(ptr!=NULL){

        recursion(ptr->left);
        QPainter painter(this);
        painter.setPen(QPen(Qt::black,4));
        painter.setRenderHint(QPainter::Antialiasing, true);
        if(ptr->left!=NULL)
            painter.drawLine(ptr->x,ptr->y+30,ptr->left->x+30,ptr->left->y);
        if(ptr->right!=NULL)
            painter.drawLine(ptr->x+30,ptr->y+30,ptr->right->x,ptr->right->y);

        MyLabel *a=new MyLabel(QString::fromStdString(ptr->name),this);
        store.push_back(a);
        a->setText(QString::fromStdString(ptr->name));
        a->setGeometry(ptr->x,ptr->y,30,30);
        QFont font;
        font.setPointSize(15);
        a->setFont(font);
        a->setAlignment(Qt::AlignCenter);
        if(ptr->sex)
            a->setStyleSheet("background-color:#aaaaff");
        else
            a->setStyleSheet("background-color:pink");
        if(!ptr->alive)
            a->setStyleSheet("background-color:gray");
        a->show();
        a->setInfo(ptr);
        QObject::connect(a,&MyLabel::clicked,this,&MainWindow::print);

        recursion(ptr->right);

    }
}

void MainWindow::print(node* info)
{
    string a="INFORMATION\nName: "+info->name;
    string b="Sex: ";
    if(info->sex)
        b+="man";
    else
        b+="woman";
    string c;
    if(info->ismarriage)
        c="Married";
    else
        c="Single";
    string d;
    if(info->alive)
        d="Alive";
    else
        d="Died";

    ui->textEdit->setText(QString::fromStdString(a+"\n"+b+"\n"+c+"\n"+d));
}
