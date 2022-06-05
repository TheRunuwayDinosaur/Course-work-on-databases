#include "login.h"
#include "ui_login.h"

login::login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
    ui->address->setText("DESKTOP-2NQ0KTF");
    ui->name->setText("kursach");
    ui->user_password->setEchoMode(QLineEdit::Password);
    ui->user_password->setText("sarmat");
    setWindowTitle("Соединение с БД");
}

login::~login(){
    delete ui;
}



void login::on_connect_clicked(){
    was_db_connected = false;
    QString address = ui->address->text();
    QString name = ui->name->text();
    int index = ui->user_login->currentIndex();
    QString login = "";
    if (index == 0) login = "user1";
    else login = "user3";
    QString password = ui->user_password->text();
    db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("DRIVER={SQL Server};SERVER="+address+";DATABASE="+name+";");
    db.setUserName(login);
    db.setPassword(password);
    if (db.open()){
        was_db_connected = true;
        QMessageBox::information(this,"Статус","Успешно!");
    }
    else{
        //qDebug() << db.lastError().text();
        QMessageBox::critical(this,"Статус",QString("%1").arg(db.lastError().text()));
    }
}
