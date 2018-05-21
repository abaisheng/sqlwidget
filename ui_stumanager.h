/********************************************************************************
** Form generated from reading UI file 'stumanager.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STUMANAGER_H
#define UI_STUMANAGER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_stuManager
{
public:
    QGridLayout *gridLayout;
    QTableView *tableView;

    void setupUi(QWidget *stuManager)
    {
        if (stuManager->objectName().isEmpty())
            stuManager->setObjectName(QStringLiteral("stuManager"));
        stuManager->resize(427, 292);
        gridLayout = new QGridLayout(stuManager);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        tableView = new QTableView(stuManager);
        tableView->setObjectName(QStringLiteral("tableView"));

        gridLayout->addWidget(tableView, 0, 0, 1, 1);


        retranslateUi(stuManager);

        QMetaObject::connectSlotsByName(stuManager);
    } // setupUi

    void retranslateUi(QWidget *stuManager)
    {
        stuManager->setWindowTitle(QApplication::translate("stuManager", "Form", 0));
    } // retranslateUi

};

namespace Ui {
    class stuManager: public Ui_stuManager {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STUMANAGER_H
