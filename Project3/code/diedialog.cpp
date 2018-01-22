#include "diedialog.h"
#include "ui_diedialog.h"

DieDialog::DieDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DieDialog)
{
    ui->setupUi(this);
    setWindowTitle("Die");
}

DieDialog::~DieDialog()
{
    delete ui;
}

void DieDialog::on_buttonBox_accepted()
{
    a=ui->lineEdit->text().toStdString();
}
