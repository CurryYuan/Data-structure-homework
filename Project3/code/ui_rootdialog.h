/********************************************************************************
** Form generated from reading UI file 'rootdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ROOTDIALOG_H
#define UI_ROOTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RootDialog
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QLabel *label_2;

    void setupUi(QDialog *RootDialog)
    {
        if (RootDialog->objectName().isEmpty())
            RootDialog->setObjectName(QStringLiteral("RootDialog"));
        RootDialog->resize(400, 300);
        buttonBox = new QDialogButtonBox(RootDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        widget = new QWidget(RootDialog);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(30, 70, 341, 81));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        lineEdit = new QLineEdit(widget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        horizontalLayout->addWidget(lineEdit);


        verticalLayout->addLayout(horizontalLayout);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout->addWidget(label_2);


        retranslateUi(RootDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), RootDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), RootDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(RootDialog);
    } // setupUi

    void retranslateUi(QDialog *RootDialog)
    {
        RootDialog->setWindowTitle(QApplication::translate("RootDialog", "Dialog", 0));
        label->setText(QApplication::translate("RootDialog", "Root name:", 0));
        label_2->setText(QApplication::translate("RootDialog", "Root can only be a man", 0));
    } // retranslateUi

};

namespace Ui {
    class RootDialog: public Ui_RootDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ROOTDIALOG_H
