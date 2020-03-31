#include "adminfelulet.h"
#include "ui_adminfelulet.h"

adminFelulet::adminFelulet(const QString& adminName,DatabaseConnection *db, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::adminFelulet),
    db(db)
{
    ui->setupUi(this);
    ui->adminUsername->setText(adminName);
}

adminFelulet::~adminFelulet()
{
    delete ui;
}

void adminFelulet::on_pushButton_clicked()
{
    QString firstName = ui->knev->text();
    QString lastName = ui->vnev->text();
    QString groupName = ui->gnev->text();
    qDebug() << firstName << " " << lastName << " " << groupName;

    if(db->getDb().open())
    {
        QSqlQuery query(db->getDb());
        query.prepare(QString("INSERT INTO Gyakorlas (Lastname,Firstname,GroupName) VALUES (:fname,:lname,:gname)"));
        query.bindValue(":fname",firstName);
        query.bindValue(":lname",lastName);
        query.bindValue(":gname",groupName);
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
