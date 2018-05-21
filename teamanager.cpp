#include "teamanager.h"
#include "ui_teamanager.h"

teaManager::teaManager(QWidget *parent) : QWidget(parent), ui(new Ui::teaManager)
{
    ui->setupUi(this);
    curStr = "";  //养成随手初始化所有变量的习惯
    model = new QSqlTableModel;
    showTable("");

    QHeaderView *hv = ui->tableView->horizontalHeader();
    hv->setSortIndicatorShown(true); //显示排序三角
    hv->sectionsClickable();//设置标题可以被单击
    connect(hv,SIGNAL(sectionClicked(int)),ui->tableView,SLOT(sortByColumn(int)));
}

teaManager::~teaManager()
{
    delete ui;
}



void teaManager::showTable(QString str)
{
    curStr = str;
    model->setTable("teacher");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    if(!curStr.isEmpty()) model->setFilter(tr("name like '%%1%'").arg(curStr)); //根据姓名进行模糊筛选
    model->select(); //在筛选和排序的条件下，将数据库中符合要求的在mode表格中显示出来
    ui->tableView->setModel(model);
//    ui->tableView->setAlternatingRowColors(true);
//    ui->tableView->resizeColumnsToContents();
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
//    qDebug() << "showTable()";
}

void teaManager::addRow()
{
    int rowNum = model->rowCount();
    model->insertRow(rowNum);
//    model->setData(model->index(rowNum, 0), 0);
//    qDebug() << "addrow";
}

void teaManager::updateTable()
{
    model->submitAll(); //可以直接提交
    showTable("");
}

void teaManager::deleteRows()
{
    QItemSelectionModel *selections = ui->tableView->selectionModel(); //返回当前的选择模式
    QModelIndexList selected = selections->selectedIndexes();   //返回所有选定模型项目索引列表

    foreach (QModelIndex index, selected)  //对二参容器从头开始遍历
    {
        int curRow = index.row();
        model->removeRow(curRow);  //删除所有被选中的行

    }

    if (!selected.isEmpty())  //如果有选中内容
    {
       int btnClick = QMessageBox::warning(this, tr("删除行"), tr("你确定删除所选行吗？"),\
                                     QMessageBox::Yes, QMessageBox::No);

       if(QMessageBox::Yes == btnClick)
       {
            model->submitAll(); //确定删除则提交，在数据库中删除所选行
       }
       else if (QMessageBox::No == btnClick)
       {
            model->revertAll(); //如果不删除，则撤销
       }
    }
    else  //没有选中内容
    {
       QMessageBox::information(this, tr("info"), tr("No row selected!"),\
                                                  QMessageBox::Ok);
    }

    showTable("");
}
