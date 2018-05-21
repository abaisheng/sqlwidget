#ifndef mainWidget_H
#define mainWidget_H

#include <QWidget>
//#include <QSql>
#include <QDebug>
#include <QPushButton>
#include <QWidget>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QString>
#include "stumanager.h"
#include "teamanager.h"

namespace Ui
{
class mainWidget;
}

class mainWidget : public QWidget
{
    Q_OBJECT

public:
    explicit mainWidget(QWidget *parent = 0);
    ~mainWidget();

private slots:
    void addBtnClicked();
    void updateBtnClicked();
    void deleteBtnClicked();
    void setCurTabIndex();
    void getSearchText();

private:
    Ui::mainWidget *ui;
    QString str;
    int tabNum;

    QLineEdit *searchEdit;
//    QPushButton *refreshBtn;
    QPushButton *addBtn;
    QPushButton *updateBtn;
    QPushButton *deleteBtn;
    stuManager *m_pStuManager;
    teaManager *m_pTeaManager;
    void initUI();
    void refresh();

    void creatCornerBtn();
//    void connectDb();
//    void createTables();

protected:
    QSqlDatabase database;
};

#endif // mainWidget_H
