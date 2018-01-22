#include "rootdialog.h"
#include "ui_rootdialog.h"

RootDialog::RootDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RootDialog)
{
    ui->setupUi(this);
    setWindowTitle("Create root");
}

RootDialog::~RootDialog()
{
    delete ui;
}

void RootDialog::on_buttonBox_accepted()
{
    a=ui->lineEdit->text().toStdString();
}
