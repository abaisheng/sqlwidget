#ifndef STUMANAGER_H
#define STUMANAGER_H

#include <QWidget>
#include <QTableView>
#include <QSqlTableModel>
#include <QSqlDatabase>
#include <QDebug>
#include <QMessageBox>

namespace Ui
{
class stuManager;
}

class stuManager : public QWidget
{
    Q_OBJECT

public:
    explicit stuManager(QWidget *parent = 0);
    ~stuManager();
    void showTable(QString str);
    void addRow();
    void updateTable();
    void deleteRows();

private:
    Ui::stuManager *ui;
    QString curStr;
    QSqlTableModel *model ;


};

#endif // STUMANAGER_H
