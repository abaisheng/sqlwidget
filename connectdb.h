#ifndef CONNECTDB
#define CONNECTDB

#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

void connectDb(QSqlDatabase db)
{
    //使用qt5自带的sqlite
//    db = QSqlDatabase::addDatabase("QSQLITE");
//    db.setDatabaseName("MyDataBase.db");
//    db.setUserName("UserName");
//    db.setPassword("123456Pwd!");

    //使用自己配置的mysql数据库
    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");                        //127.0.0.1也是一样的,属于本地地址
    db.setUserName("root");                                 //登陆MYSQL的用户名
    db.setPassword("MySql");
    db.setDatabaseName("qtdb");

    if (!db.open())
    {
       qDebug() << "Database Opened Fail";
       qDebug() << db.lastError();
    }
    else  //所有操作必须在数据库成功打开下进行
    {
       qDebug() << "Database Opened";
       QSqlQuery query;

       if (!db.tables().contains("student"))
       {
           bool createStuTb = query.exec("create table student \
                                         (Id char(10) primary key, Name varchar(20), Sex varchar(10),\
                                          Major varchar(30), Birth char(8), Tel char(11), Address varchar(50))");

           if (createStuTb)
           {
               query.exec("insert into student values(1,NULL,NULL,NULL,NULL,NULL,NULL)");
           }
       }
       else
       {
           qDebug() << "Table student already exsit" ;
           qDebug() << query.lastError();
       }

       if (!db.tables().contains("teacher"))
       {
           bool createTeaTb = query.exec("create table teacher \
                                         (Id char(10) primary key, Name varchar(20), Sex varchar(10), Major varchar(30),\
                                          Birth char(8), Tel char(11), Address varchar(50), Class varchar(20))");

           if (createTeaTb)
           {
               query.exec("insert into teacher values(1,NULL,NULL,NULL,NULL,NULL,NULL,NULL)");
           }
       }
       else
       {
           qDebug() << "Table teacher already exsit" ;
           qDebug() << query.lastError();
       }
    }
}

#endif // CONNECTDB

