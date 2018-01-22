#include "divorcedialog.h"
#include "ui_divorcedialog.h"

DivorceDialog::DivorceDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DivorceDialog)
{
    ui->setupUi(this);
    setWindowTitle("Divorce");
}

DivorceDialog::~DivorceDialog()
{
    delete ui;
}

void DivorceDialog::on_buttonBox_accepted()
{
    a=ui->lineEdit->text().toStdString();
    b=ui->lineEdit_2->text().toStdString();
}
