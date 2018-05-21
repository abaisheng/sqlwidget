#include "mainwidget.h"
#include <QApplication>
#include <QFile>
#include <QTextStream>
#include <QDir>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QFile file("../sqlwidget/styles/white.qss");  //该路径出错会导致界面背景崩溃
    qDebug() << QDir::currentPath();

    if (file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream in(&file);
        QString style = in.readAll();
        file.close();
        qApp->setStyleSheet(style);
    }

    mainWidget w;
    w.show();

    return a.exec();
}
