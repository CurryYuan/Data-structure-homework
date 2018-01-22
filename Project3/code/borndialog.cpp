#include "borndialog.h"
#include "ui_borndialog.h"

BornDialog::BornDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BornDialog)
{
    ui->setupUi(this);
}

BornDialog::~BornDialog()
{
    delete ui;
}

void BornDialog::on_buttonBox_accepted()
{
    a=ui->lineEdit->text().toStdString();
    b=ui->lineEdit_3->text().toStdString();
    c=ui->lineEdit_4->text().toStdString();
    d=ui->comboBox->currentIndex();
}
