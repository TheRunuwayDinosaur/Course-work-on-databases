#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <QDebug>
#include <QSqlDatabase>
#include <QMessageBox>
#include <QSqlError>

namespace Ui {
class login;
}

class login : public QWidget
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = nullptr);
    ~login();
private slots:
    void on_connect_clicked();
private:
    Ui::login *ui;
    bool was_db_connected;
    QSqlDatabase db;
};


#endif // LOGIN_H
