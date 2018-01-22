#include "marriagedialog.h"
#include "ui_marriagedialog.h"

MarriageDialog::MarriageDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MarriageDialog)
{
    ui->setupUi(this);
}

MarriageDialog::~MarriageDialog()
{
    delete ui;
}

void MarriageDialog::on_buttonBox_accepted()
{
    a=ui->lineEdit->text().toStdString();
    b=ui->lineEdit_2->text().toStdString();
}
