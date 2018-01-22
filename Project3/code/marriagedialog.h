#ifndef MARRIAGEDIALOG_H
#define MARRIAGEDIALOG_H

#include <QDialog>
#include <string>
using namespace std;

namespace Ui {
class MarriageDialog;
}

class MarriageDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MarriageDialog(QWidget *parent = 0);
    ~MarriageDialog();
    string a,b;
private slots:
    void on_buttonBox_accepted();

private:
    Ui::MarriageDialog *ui;
};

#endif // MARRIAGEDIALOG_H
