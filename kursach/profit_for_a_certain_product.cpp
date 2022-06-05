#include "profit_for_a_certain_product.h"
#include "ui_profit_for_a_certain_product.h"

profit_for_a_certain_product::profit_for_a_certain_product(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::profit_for_a_certain_product)
{
    setWindowTitle("");
    ui->setupUi(this);
    ui->table_of_products->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    ui->table_of_products->setStyleSheet("QHeaderView::section { background-color: cyan }");
    setWindowTitle("Прибыль за товар");
}

profit_for_a_certain_product::~profit_for_a_certain_product(){
    delete ui;
    delete query;
    delete model;
}

void profit_for_a_certain_product::add_products(){
    query = new QSqlQuery();
    if (query->exec("select [product_id (PK)],product_name from list_of_products")){
        while(query->next()){
            int product_id = query->value(0).toInt();
            QString product_name = query->value(1).toString();
            ui->changed_product->addItem(product_name,product_id);
        }
        ui->changed_product->addItem("Все товары",1e9);
    }
    else{
        QMessageBox::critical(this,"Статус","Ошибка - " + query->lastError().text());
    }
}

void profit_for_a_certain_product::on_show_in_table_clicked(){
    int product_id = ui->changed_product->currentData().toInt();
    QString product_name = "";
    if (product_id == 1e9){
        product_name = "*";
        QSqlQuery *query_2 = new QSqlQuery();
        if (query_2->exec("select product_name,case when [dbo].profit_for_the_product([product_id (PK)]) > 0 then [dbo].profit_for_the_product([product_id (PK)]) else 0 end as product_total_sum from list_of_products")){
            model = new profit_for_a_certain_product_model();
            while(query_2->next()){
                QString product_name = query_2->value(0).toString();
                double product_total_sum = query_2->value(1).toDouble();
                profit_for_a_certain_product_storage *data = new profit_for_a_certain_product_storage();
                data->add_data(product_name,product_total_sum);
                model->add_data(*data);
                delete data;
            }
            ui->table_of_products->setModel(model);
        }
        else{
            QMessageBox::critical(this,"Статус","Ошибка - " + query_2->lastError().text());
        }
        delete query_2;
    }
    else{
        query = new QSqlQuery();
        if (query->exec(QString("select product_name from list_of_products where [product_id (PK)] = %1").arg(product_id))){
            while(query->next()){
                product_name = query->value(0).toString();
            }
            QSqlQuery *query_2 = new QSqlQuery();
            if (query_2->exec(QString("select case when [dbo].profit_for_the_product([product_id (PK)]) > 0 then [dbo].profit_for_the_product([product_id (PK)]) else 0 end as product_total_sum from list_of_products where product_name = '%1'").arg(product_name))){
                double product_total_sum = 0.;
                while(query_2->next()){
                    product_total_sum = query_2->value(0).toDouble();
                }
                profit_for_a_certain_product_storage *data = new profit_for_a_certain_product_storage();
                data->add_data(product_name,product_total_sum);
                model = new profit_for_a_certain_product_model();
                model->add_data(*data);
                ui->table_of_products->setModel(model);
            }
            else{
                QMessageBox::critical(this,"Статус","Ошибка - " + query_2->lastError().text());
            }
            delete query_2;
        }
        else{
            QMessageBox::critical(this,"Статус","Ошибка - " + query->lastError().text());
        }
    }
}

