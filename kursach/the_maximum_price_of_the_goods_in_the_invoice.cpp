#include "the_maximum_price_of_the_goods_in_the_invoice.h"
#include "ui_the_maximum_price_of_the_goods_in_the_invoice.h"

the_maximum_price_of_the_goods_in_the_invoice::the_maximum_price_of_the_goods_in_the_invoice(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::the_maximum_price_of_the_goods_in_the_invoice)
{
    ui->setupUi(this);
    ui->table_of_invoices->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    ui->table_of_invoices->setStyleSheet("QHeaderView::section { background-color: cyan }");
    setWindowTitle("Цена всех товаров в накладной");
}

the_maximum_price_of_the_goods_in_the_invoice::~the_maximum_price_of_the_goods_in_the_invoice(){
    delete ui;
    delete query;
    delete model;
}

void the_maximum_price_of_the_goods_in_the_invoice::add_invoices(){
    query = new QSqlQuery();
    if (query->exec("select [invoice_id (PK)],invoice_document_number from invoices")){
        std::set <QString> used;
        while(query->next()){
            int invoice_id = query->value(0).toInt();
            QString invoice_document_number = query->value(1).toString();
            if (!used.count(invoice_document_number)){
                ui->invoice_document_number->addItem(invoice_document_number,invoice_id);
                used.insert(invoice_document_number);
            }
        }
    }
    else{
        QMessageBox::critical(this,"Статус","Ошибка - " + query->lastError().text());
    }
}

void the_maximum_price_of_the_goods_in_the_invoice::on_show_clicked(){
    int invoice_id = ui->invoice_document_number->currentData().toInt();
    query = new QSqlQuery();
    QString invoice_document_number = "";
    model = new the_maximum_price_of_the_goods_in_the_invoice_model();
    if (query->exec(QString("select invoice_document_number from invoices where [invoice_id (PK)] = %1").arg(invoice_id))){
        while(query->next()){
            invoice_document_number = query->value(0).toString();
        }
        //qDebug() << invoice_document_number;
        QSqlQuery *query_2 = new QSqlQuery();
        if (query_2->exec(QString("select [invoice_product_id (FK2)],max(invoice_product_total_sum) as total_sum from invoices where invoice_document_number = '%1' group by [invoice_product_id (FK2)]").arg(invoice_document_number))){
            while(query_2->next()){
                int product_id = query_2->value(0).toInt();
                double total_sum = query_2->value(1).toDouble();
                QSqlQuery *query_3 = new QSqlQuery();
                QString product_name = "";
                query_3->exec(QString("select product_name from list_of_products where [product_id (PK)] = %1").arg(product_id));
                while(query_3->next()){
                    product_name = query_3->value(0).toString();
                }
                the_maximum_price_of_the_goods_in_the_invoice_storage *data = new the_maximum_price_of_the_goods_in_the_invoice_storage();
                data->add_data(invoice_document_number,product_name,total_sum);
                //qDebug() << data->get_product_name();
                model->add_data(*data);
                delete query_3;
            }
            ui->table_of_invoices->setModel(model);
            ui->table_of_invoices->hideColumn(0);
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

