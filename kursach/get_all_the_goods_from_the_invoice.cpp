#include "get_all_the_goods_from_the_invoice.h"
#include "ui_get_all_the_goods_from_the_invoice.h"

get_all_the_goods_from_the_invoice::get_all_the_goods_from_the_invoice(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::get_all_the_goods_from_the_invoice)
{
    ui->setupUi(this);
    setWindowTitle("Товары в определённой накладной");
}

get_all_the_goods_from_the_invoice::~get_all_the_goods_from_the_invoice(){
    delete ui;
    delete query;
    delete model;
}

void get_all_the_goods_from_the_invoice::set_model(){
    query = new QSqlQuery();
    if (query->exec("select [invoice_id (PK)],invoice_document_number from invoices")){
        std::set <QString> used;
        while(query->next()){
            int invoice_id = query->value(0).toInt();
            QString document_number = query->value(1).toString();
            if (!used.count(document_number)){
                ui->invoice_document_number->addItem(document_number,invoice_id);
                used.insert(document_number);
            }
        }
    }
    else{
        QMessageBox::critical(this,"Статус","Ошибка - " + query->lastError().text());
    }
}

void get_all_the_goods_from_the_invoice::on_show_clicked(){
    int invoice_id = ui->invoice_document_number->currentData().toInt();
    QString invoice_document_number = "";
    query = new QSqlQuery();
    model = new get_all_the_goods_from_the_invoice_model();
    if (query->exec(QString("select invoice_document_number from invoices where [invoice_id (PK)] = %1").arg(invoice_id))){
        while(query->next()){
            invoice_document_number = query->value(0).toString();
        }
        QSqlQuery *query_2 = new QSqlQuery();
        QList <int> product_ids;
        if (query_2->exec(QString("select bridge_product_id from bridge_invoice_product where bridge_invoice_document_number = '%1'").arg(invoice_document_number))){
            while(query_2->next()){
                int product_id = query_2->value(0).toInt();
                product_ids.append(product_id);
            }
            for (const auto& cur : product_ids){
                QSqlQuery *query_3 = new QSqlQuery();
                query_3->exec(QString("select product_name from list_of_products where [product_id (PK)] = %1").arg(cur));
                while(query_3->next()){
                    QString product_name = query_3->value(0).toString();
                    model->add_data(product_name);
                }
                delete query_3;
            }
            //qDebug() << "тык";
            ui->listView->setModel(model);
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

