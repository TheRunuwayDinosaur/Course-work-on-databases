#include "add_data_in_lop.h"
#include "ui_add_data_in_lop.h"

add_data_in_lop::add_data_in_lop(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::add_data_in_lop)
{
    ui->setupUi(this);
}

add_data_in_lop::~add_data_in_lop(){
    delete ui;
    delete query;
    delete lop_model_;
}

void add_data_in_lop::set_model(lop_model &lop){
    lop_model_ = new lop_model();
    lop_model_ = &lop;
}

void add_data_in_lop::on_add_datas_clicked(){
    close();
    QString product_name = ui->product_name->text();
    int product_count = ui->product_count->text().toInt();
    bool was_digit = false;
    for (const auto& ch : product_name){
        if (ch >= '0' && ch <= '9') was_digit = true;
    }
    if (product_count <= 0 || was_digit){
        QMessageBox::critical(this,"Статус","Неправильный формат ввода данных!!!");
        return;
    }
    //QMessageBox::information(this,"Статус","Успешно!");
    query = new QSqlQuery();
    if (!query->exec(QString("add_values_in_list_of_products '%1',%2,%3").arg(product_name).arg(product_count).arg(0))){
        QMessageBox::critical(this,"Статус","Ошибка добавления данных - " + query->lastError().text());
    }
    else{
        QMessageBox::information(this,"Статус","Успешно!");
        QSqlQuery *query_2 = new QSqlQuery();
        query_2->exec(QString("select [product_id (PK)] from list_of_products where product_name = %1").arg(product_name));
        int product_id = -1;
        while(query_2->next()){
            product_id = query_2->value(0).toInt();
        }
        lop_storage *data = new lop_storage(product_id,product_name,product_count,0);
        lop_model_->add_data(*data);
        //qDebug() << product_id << ' ' << product_name << ' ' << product_count;
        delete query_2;
        delete data;
    }
    //query->exec(QString("add_values_in_list_of_products '%1',%2,%3").arg(product_name).arg(product_count).arg(0));
}

