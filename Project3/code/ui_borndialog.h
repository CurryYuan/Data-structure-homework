/********************************************************************************
** Form generated from reading UI file 'borndialog.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BORNDIALOG_H
#define UI_BORNDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_BornDialog
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QLabel *label_2;
    QLineEdit *lineEdit_3;
    QLabel *label_3;
    QLineEdit *lineEdit_4;
    QLabel *label_4;
    QComboBox *comboBox;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *BornDialog)
    {
        if (BornDialog->objectName().isEmpty())
            BornDialog->setObjectName(QStringLiteral("BornDialog"));
        BornDialog->resize(400, 300);
        gridLayout = new QGridLayout(BornDialog);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(BornDialog);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        lineEdit = new QLineEdit(BornDialog);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        gridLayout->addWidget(lineEdit, 0, 1, 1, 1);

        label_2 = new QLabel(BornDialog);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        lineEdit_3 = new QLineEdit(BornDialog);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));

        gridLayout->addWidget(lineEdit_3, 1, 1, 1, 1);

        label_3 = new QLabel(BornDialog);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        lineEdit_4 = new QLineEdit(BornDialog);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));

        gridLayout->addWidget(lineEdit_4, 2, 1, 1, 1);

        label_4 = new QLabel(BornDialog);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        comboBox = new QComboBox(BornDialog);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        gridLayout->addWidget(comboBox, 3, 1, 1, 1);

        buttonBox = new QDialogButtonBox(BornDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 4, 0, 1, 2);


        retranslateUi(BornDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), BornDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), BornDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(BornDialog);
    } // setupUi

    void retranslateUi(QDialog *BornDialog)
    {
        BornDialog->setWindowTitle(QApplication::translate("BornDialog", "Dialog", 0));
        label->setText(QApplication::translate("BornDialog", "Father name", 0));
        label_2->setText(QApplication::translate("BornDialog", "Mother name", 0));
        label_3->setText(QApplication::translate("BornDialog", "Child name", 0));
        label_4->setText(QApplication::translate("BornDialog", "Sex", 0));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("BornDialog", "man", 0)
         << QApplication::translate("BornDialog", "woman", 0)
        );
    } // retranslateUi

};

namespace Ui {
    class BornDialog: public Ui_BornDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BORNDIALOG_H
