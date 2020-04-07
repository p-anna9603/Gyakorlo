#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    db = new DatabaseConnection();
}

MainWindow::~MainWindow()
{
    delete ui;
    db->getDb().close();
    QSqlDatabase::removeDatabase("QMYSQL");
}


void MainWindow::on_pushButton_clicked()
{
        QString username = ui->username->text();
        QString password = ui->password->text();

        if(db->getDb().open())
        {
            QSqlQuery query(db->getDb());
            query.prepare(QString("SELECT * FROM Hozzaferes WHERE username = :username AND password = :password"));
            query.bindValue(":username", username);
            query.bindValue(":password", password);
            if(!query.exec())
            {
                QMessageBox::information(this, "Failed", "Query Failed to execute");
            }
            else
            {
                if(query.size() == 0)
                {
                    QMessageBox::information(this, "Failed", "Login Failed to execute");
                }
                else
                {
                    while(query.next())
                    {
                        adminFelulet *testAdmin=new adminFelulet(db);
                        testAdmin->show();
                        this->close();
                    }
                }
            }
        }
        else
        {
            QMessageBox::information(this, "Not Connected", "Database not connected");
        }
}

//void MainWindow::on_pushButton_clicked()
//{
//        QString username = ui->username->text();
//        QString password = ui->password->text();

//        if(db->getDb().open())
//        {
//            QSqlQuery query(db->getDb());
//            query.prepare(QString("SELECT * FROM Hozzaferes"));
//            if(!query.exec())
//            {
//                QMessageBox::information(this, "Failed", "Query Failed to execute");
//            }
//            else
//            {
//                while(query.next())
//                {
//                        QString usernameFromDb = query.value(0).toString();
//                        QString passwordFromDb = query.value(1).toString();
//                        if(usernameFromDb == username && passwordFromDb == password)
//                        {
//                                adminFelulet *admin = new adminFelulet(db);
//                                admin->show();
//                                this->close();
//                        }
//                }
//            }
//        }
//        else
//        {
//            QMessageBox::information(this, "Not Connected", "Database not connected");
//        }
//}
