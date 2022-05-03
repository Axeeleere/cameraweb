#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QWebEngineView *view = new QWebEngineView(this);
       view->load(QUrl("http://admin@172.17.50.55/video.cgi"));
       view->setGeometry(20,20,550,440);
       view->show();
       QSqlDatabase db=QSqlDatabase::addDatabase("QMYSQL");
       db.setHostName("localhost");
       db.setDatabaseName("elevage");
       db.setUserName("root");
       db.setPassword("");
       if(db.open())
       {
          QSqlQuery query;
          if(query.exec("select * from temperature"))
          {
              while(query.next())
              {
                  qDebug()<<query.value(0).toString();
                  ui->label->setText(query.value(0).toString() + " | " + query.value(1).toString() + " | " + query.value(2).toString());
              }
          }
       }
}

MainWindow::~MainWindow()
{
    delete ui;
}
