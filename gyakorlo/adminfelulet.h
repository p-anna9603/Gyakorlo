#ifndef ADMINFELULET_H
#define ADMINFELULET_H

#include <QMainWindow>
#include "databaseconnection.h"

namespace Ui {
class adminFelulet;
}

class adminFelulet : public QMainWindow
{
    Q_OBJECT

public:
    explicit adminFelulet(const QString& adminName="Unknown",DatabaseConnection *db = nullptr, QWidget *parent = nullptr);
    ~adminFelulet();

private slots:
    void on_pushButton_clicked();

private:
    Ui::adminFelulet *ui;
    DatabaseConnection *db;
};

#endif // ADMINFELULET_H
