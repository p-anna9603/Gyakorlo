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
                while(query.next())
                {
                    QString usernameFromDB = query.value(0).toString();
                    QString passwordFromDB = query.value(1).toString();
                    if(usernameFromDB == username && passwordFromDB == password)
                    {
                        if ((username=="admin" && password=="admin"))
                        {
                            adminFelulet *testAdmin=new adminFelulet(db);
                            testAdmin->show();
                            this->close();
                        }
                    }
                    else
                    {
                        QMessageBox::information(this, "Failed","Login Failed");
                    }
                }
            }
        }
        else
        {
            QMessageBox::information(this, "Not Connected", "Database not connected");
        }
}
