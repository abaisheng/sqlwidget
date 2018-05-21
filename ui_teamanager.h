/********************************************************************************
** Form generated from reading UI file 'teamanager.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEAMANAGER_H
#define UI_TEAMANAGER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_teaManager
{
public:
    QGridLayout *gridLayout;
    QTableView *tableView;

    void setupUi(QWidget *teaManager)
    {
        if (teaManager->objectName().isEmpty())
            teaManager->setObjectName(QStringLiteral("teaManager"));
        teaManager->resize(320, 240);
        gridLayout = new QGridLayout(teaManager);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        tableView = new QTableView(teaManager);
        tableView->setObjectName(QStringLiteral("tableView"));

        gridLayout->addWidget(tableView, 0, 0, 1, 1);


        retranslateUi(teaManager);

        QMetaObject::connectSlotsByName(teaManager);
    } // setupUi

    void retranslateUi(QWidget *teaManager)
    {
        teaManager->setWindowTitle(QApplication::translate("teaManager", "Form", 0));
    } // retranslateUi

};

namespace Ui {
    class teaManager: public Ui_teaManager {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEAMANAGER_H
