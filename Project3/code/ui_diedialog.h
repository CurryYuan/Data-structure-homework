/********************************************************************************
** Form generated from reading UI file 'diedialog.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIEDIALOG_H
#define UI_DIEDIALOG_H

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

class Ui_DieDialog
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *DieDialog)
    {
        if (DieDialog->objectName().isEmpty())
            DieDialog->setObjectName(QStringLiteral("DieDialog"));
        DieDialog->resize(400, 300);
        gridLayout = new QGridLayout(DieDialog);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(DieDialog);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        lineEdit = new QLineEdit(DieDialog);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        gridLayout->addWidget(lineEdit, 0, 1, 1, 1);

        buttonBox = new QDialogButtonBox(DieDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 1, 0, 1, 2);


        retranslateUi(DieDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), DieDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DieDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(DieDialog);
    } // setupUi

    void retranslateUi(QDialog *DieDialog)
    {
        DieDialog->setWindowTitle(QApplication::translate("DieDialog", "Dialog", 0));
        label->setText(QApplication::translate("DieDialog", "Died name:", 0));
    } // retranslateUi

};

namespace Ui {
    class DieDialog: public Ui_DieDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIEDIALOG_H
