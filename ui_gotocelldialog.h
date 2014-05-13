/********************************************************************************
** Form generated from reading UI file 'gotocelldialog.ui'
**
** Created by: Qt User Interface Compiler version 5.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GOTOCELLDIALOG_H
#define UI_GOTOCELLDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GoToCellDialog
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *CellLocation;
    QLineEdit *lineEdit;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *OkButton;
    QPushButton *Cancel;

    void setupUi(QWidget *GoToCellDialog)
    {
        if (GoToCellDialog->objectName().isEmpty())
            GoToCellDialog->setObjectName(QStringLiteral("GoToCellDialog"));
        GoToCellDialog->resize(240, 71);
        verticalLayout = new QVBoxLayout(GoToCellDialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        CellLocation = new QLabel(GoToCellDialog);
        CellLocation->setObjectName(QStringLiteral("CellLocation"));

        horizontalLayout->addWidget(CellLocation);

        lineEdit = new QLineEdit(GoToCellDialog);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        horizontalLayout->addWidget(lineEdit);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(58, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        OkButton = new QPushButton(GoToCellDialog);
        OkButton->setObjectName(QStringLiteral("OkButton"));
        OkButton->setEnabled(false);
        OkButton->setDefault(true);

        horizontalLayout_2->addWidget(OkButton);

        Cancel = new QPushButton(GoToCellDialog);
        Cancel->setObjectName(QStringLiteral("Cancel"));

        horizontalLayout_2->addWidget(Cancel);


        verticalLayout->addLayout(horizontalLayout_2);

#ifndef QT_NO_SHORTCUT
        CellLocation->setBuddy(lineEdit);
#endif // QT_NO_SHORTCUT
        QWidget::setTabOrder(lineEdit, OkButton);
        QWidget::setTabOrder(OkButton, Cancel);

        retranslateUi(GoToCellDialog);

        QMetaObject::connectSlotsByName(GoToCellDialog);
    } // setupUi

    void retranslateUi(QWidget *GoToCellDialog)
    {
        GoToCellDialog->setWindowTitle(QApplication::translate("GoToCellDialog", "Go to Cell", 0));
        CellLocation->setText(QApplication::translate("GoToCellDialog", "Cell Location", 0));
        OkButton->setText(QApplication::translate("GoToCellDialog", "OK", 0));
        Cancel->setText(QApplication::translate("GoToCellDialog", "Cancel", 0));
    } // retranslateUi

};

namespace Ui {
    class GoToCellDialog: public Ui_GoToCellDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GOTOCELLDIALOG_H
