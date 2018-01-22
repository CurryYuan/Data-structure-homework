#ifndef DIVORCEDIALOG_H
#define DIVORCEDIALOG_H

#include <QDialog>
#include "string"
using namespace std;

namespace Ui {
class DivorceDialog;
}

class DivorceDialog : public QDialog
{
    Q_OBJECT

public:
    explicit DivorceDialog(QWidget *parent = 0);
    ~DivorceDialog();
    string a,b;
private slots:
    void on_buttonBox_accepted();

private:
    Ui::DivorceDialog *ui;
};

#endif // DIVORCEDIALOG_H
