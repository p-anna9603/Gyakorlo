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
    QString firstName = ui->firstname->text();
    QString lastName = ui->lastname->text();
    QString groupName = ui->groupname->text();
    qDebug() << firstName << " " << lastName << " " << groupName;

    if(db->getDb().open())
    {
        QSqlQuery query(db->getDb());
        query.prepare(QString("INSERT INTO Gyakorlas (Firstname,Lastname,Groupname) VALUES (:fname,:lname,:gname)"));
        query.bindValue(":fname",firstName);
        query.bindValue(":lname",lastName);
        query.bindValue(":gname",groupName);
       // query.exec();
        if(query.exec())
        {
            QMessageBox::information(this,"Success", "Values inserted into database");
        }
        else
        {
            QMessageBox::information(this,"Failure", "Values not inserted into database");
        }

    }
    else
    {
        QMessageBox::information(this, "Not Connected", "Database not connected");
    }
}
