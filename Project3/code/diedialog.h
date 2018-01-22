#ifndef DIEDIALOG_H
#define DIEDIALOG_H

#include <QDialog>
#include <string>
using namespace std;

namespace Ui {
class DieDialog;
}

class DieDialog : public QDialog
{
    Q_OBJECT

public:
    explicit DieDialog(QWidget *parent = 0);
    ~DieDialog();
    string a;
private slots:
    void on_buttonBox_accepted();

private:
    Ui::DieDialog *ui;
};

#endif // DIEDIALOG_H
