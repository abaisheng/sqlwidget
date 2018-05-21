/********************************************************************************
** Form generated from reading UI file 'sqlwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SQLWIDGET_H
#define UI_SQLWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_sqlWidget
{
public:
    QGridLayout *gridLayout;
    QTabWidget *tabWidget;

    void setupUi(QWidget *sqlWidget)
    {
        if (sqlWidget->objectName().isEmpty())
            sqlWidget->setObjectName(QStringLiteral("sqlWidget"));
        gridLayout = new QGridLayout(sqlWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        tabWidget = new QTabWidget(sqlWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));

        gridLayout->addWidget(tabWidget, 0, 0, 1, 1);


        retranslateUi(sqlWidget);

        tabWidget->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(sqlWidget);
    } // setupUi

    void retranslateUi(QWidget *sqlWidget)
    {
        sqlWidget->setWindowTitle(QApplication::translate("sqlWidget", "sqlWidget", 0));
    } // retranslateUi

};

namespace Ui {
    class sqlWidget: public Ui_sqlWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SQLWIDGET_H
