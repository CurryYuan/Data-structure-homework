#ifndef ROOTDIALOG_H
#define ROOTDIALOG_H

#include <QDialog>
#include <string>
using namespace std;

namespace Ui {
class RootDialog;
}

class RootDialog : public QDialog
{
    Q_OBJECT

public:
    explicit RootDialog(QWidget *parent = 0);
    ~RootDialog();
    string a;
private slots:
    void on_buttonBox_accepted();

private:
    Ui::RootDialog *ui;
};

#endif // ROOTDIALOG_H
