#ifndef DATABASECONNECTION_H
#define DATABASECONNECTION_H

#include <QMainWindow>
#include <QtSql>
#include <QSqlDatabase>
#include <QMessageBox>
#include <QSqlDriverPlugin>

class DatabaseConnection
{
    QSqlDatabase db;
public:
    DatabaseConnection();
    QSqlDatabase getDb() const;
};

#endif // DATABASECONNECTION_H
