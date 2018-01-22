/********************************************************************************
** Form generated from reading UI file 'divorcedialog.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIVORCEDIALOG_H
#define UI_DIVORCEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_DivorceDialog
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QLabel *label_2;
    QLineEdit *lineEdit_2;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *DivorceDialog)
    {
        if (DivorceDialog->objectName().isEmpty())
            DivorceDialog->setObjectName(QStringLiteral("DivorceDialog"));
        DivorceDialog->resize(400, 300);
        gridLayout = new QGridLayout(DivorceDialog);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(DivorceDialog);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        lineEdit = new QLineEdit(DivorceDialog);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        gridLayout->addWidget(lineEdit, 0, 1, 1, 1);

        label_2 = new QLabel(DivorceDialog);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        lineEdit_2 = new QLineEdit(DivorceDialog);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));

        gridLayout->addWidget(lineEdit_2, 1, 1, 1, 1);

        buttonBox = new QDialogButtonBox(DivorceDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 2, 0, 1, 2);


        retranslateUi(DivorceDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), DivorceDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DivorceDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(DivorceDialog);
    } // setupUi

    void retranslateUi(QDialog *DivorceDialog)
    {
        DivorceDialog->setWindowTitle(QApplication::translate("DivorceDialog", "Dialog", 0));
        label->setText(QApplication::translate("DivorceDialog", "Husband name:", 0));
        label_2->setText(QApplication::translate("DivorceDialog", "Wife name:", 0));
    } // retranslateUi

};

namespace Ui {
    class DivorceDialog: public Ui_DivorceDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIVORCEDIALOG_H
