/********************************************************************************
** Form generated from reading UI file 'marriagedialog.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MARRIAGEDIALOG_H
#define UI_MARRIAGEDIALOG_H

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

class Ui_MarriageDialog
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QLabel *label_2;
    QLineEdit *lineEdit_2;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *MarriageDialog)
    {
        if (MarriageDialog->objectName().isEmpty())
            MarriageDialog->setObjectName(QStringLiteral("MarriageDialog"));
        MarriageDialog->resize(400, 300);
        gridLayout = new QGridLayout(MarriageDialog);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(MarriageDialog);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        lineEdit = new QLineEdit(MarriageDialog);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        gridLayout->addWidget(lineEdit, 0, 1, 1, 1);

        label_2 = new QLabel(MarriageDialog);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        lineEdit_2 = new QLineEdit(MarriageDialog);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));

        gridLayout->addWidget(lineEdit_2, 1, 1, 1, 1);

        buttonBox = new QDialogButtonBox(MarriageDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 2, 0, 1, 2);


        retranslateUi(MarriageDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), MarriageDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), MarriageDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(MarriageDialog);
    } // setupUi

    void retranslateUi(QDialog *MarriageDialog)
    {
        MarriageDialog->setWindowTitle(QApplication::translate("MarriageDialog", "Dialog", 0));
        label->setText(QApplication::translate("MarriageDialog", "Groom name: ", 0));
        label_2->setText(QApplication::translate("MarriageDialog", "Bride name: ", 0));
    } // retranslateUi

};

namespace Ui {
    class MarriageDialog: public Ui_MarriageDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MARRIAGEDIALOG_H
