#ifndef TEAMANAGER_H
#define TEAMANAGER_H

#include <QWidget>
#include <QTableView>
#include <QSqlTableModel>
#include <QSqlDatabase>
#include <QDebug>
#include <QMessageBox>

namespace Ui
{
class teaManager;
}

class teaManager : public QWidget
{
    Q_OBJECT

public:
    explicit teaManager(QWidget *parent = 0);
    ~teaManager();
    void showTable(QString str);
    void addRow();
    void updateTable();
    void deleteRows();

private:
    Ui::teaManager *ui;
    QString curStr;
    QSqlTableModel *model ;
};

#endif // TEAMANAGER_H
