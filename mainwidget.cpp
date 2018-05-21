#include "mainwidget.h"
#include "connectdb.h"
#include "ui_mainWidget.h"

mainWidget::mainWidget(QWidget *parent) : QWidget(parent), ui(new Ui::mainWidget)
{
    ui->setupUi(this);
    this->setWindowTitle("SchoolManager");
    str = "";  //养成随手初始化所有变量的习惯
    tabNum = 0;
    searchEdit = new QLineEdit;
    addBtn = new QPushButton(tr("Add"));
    updateBtn = new QPushButton(tr("Update"));
    deleteBtn = new QPushButton(tr("Delete"));

    creatCornerBtn();

    connectDb(database); //连接数据库，必须在页面初始化之前，否则看不见数据
    initUI(); //初始化Tab页面
    resize(900, 600);

    connect(addBtn, SIGNAL(clicked(bool)), this, SLOT(addBtnClicked()));
    connect(updateBtn, SIGNAL(clicked(bool)), this, SLOT(updateBtnClicked()));
    connect(deleteBtn, SIGNAL(clicked(bool)), this, SLOT(deleteBtnClicked()));
    connect(searchEdit,SIGNAL(textChanged(QString)), this, SLOT(getSearchText()));
    connect(ui->tabWidget, SIGNAL(currentChanged(int)), this, SLOT(setCurTabIndex()));

}

mainWidget::~mainWidget()
{
    delete ui;
    database.close();    //数据库操作完成后，最好关闭。
    qDebug() << "Database closeed!";
}

void mainWidget::refresh()
{
    if (0 == tabNum) m_pStuManager->showTable(str);
    else if (1 == tabNum) m_pTeaManager->showTable(str);
}

void mainWidget::addBtnClicked()
{
     if (0 == tabNum) m_pStuManager->addRow();
     else if (1 == tabNum) m_pTeaManager->addRow();
}

void mainWidget::updateBtnClicked()
{
    if (0 == tabNum) m_pStuManager->updateTable();
    else if (1 == tabNum) m_pTeaManager->updateTable();
}

void mainWidget::deleteBtnClicked()
{
    if (0 == tabNum) m_pStuManager->deleteRows();
    else if (1 == tabNum) m_pTeaManager->deleteRows();
}

void mainWidget::setCurTabIndex()
{
    tabNum = ui->tabWidget->currentIndex();
    refresh();
}

void mainWidget::getSearchText()
{
    str = searchEdit->text().trimmed();  //移除字符串两端的空白符
    refresh();
//    qDebug() << QString("str = %1").arg(str);
//    qDebug() << tabNum;
}

void mainWidget::initUI()
{
    m_pStuManager = new stuManager;
    m_pTeaManager = new teaManager;
    ui->tabWidget->addTab(m_pStuManager, tr("Student"));
    ui->tabWidget->addTab(m_pTeaManager, tr("Teacher"));
}

void mainWidget::creatCornerBtn()
{
    searchEdit->setPlaceholderText(tr("Search by name"));
    searchEdit->setFixedSize(200, 20);

    QWidget *cornerWidget = new QWidget;
    QHBoxLayout *hLayout = new QHBoxLayout;
    hLayout->addWidget(searchEdit);
    hLayout->addSpacing(30);
    hLayout->addWidget(addBtn);
    hLayout->addWidget(updateBtn);
    hLayout->addWidget(deleteBtn);

    cornerWidget->setLayout(hLayout);
    ui->tabWidget->setCornerWidget(cornerWidget, Qt::TopRightCorner);
}

