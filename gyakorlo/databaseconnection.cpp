#include "databaseconnection.h"
QSqlDatabase DatabaseConnection::getDb() const
{
    return db;
}

DatabaseConnection::DatabaseConnection()
{
    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("remotemysql.com");
    db.setUserName("xVBlT3op7n");
    db.setPassword("sg5PI9nIBT");
    db.setDatabaseName("xVBlT3op7n");
    if(db.open())
    {
         qDebug()<<"Connection, Database connected successfully";
    }
    else
    {
        qDebug()<<"Not connected, Database not connected";
    }
}
