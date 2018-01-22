#ifndef BORNDIALOG_H
#define BORNDIALOG_H

#include <QDialog>
#include <string>
using namespace std;
namespace Ui {
class BornDialog;
}

class BornDialog : public QDialog
{
    Q_OBJECT

public:
    explicit BornDialog(QWidget *parent = 0);
    ~BornDialog();
    string a,b,c;
    int d;
private slots:
    void on_buttonBox_accepted();

private:
    Ui::BornDialog *ui;

};

#endif // BORNDIALOG_H
