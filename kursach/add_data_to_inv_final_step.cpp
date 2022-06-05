#include "add_data_to_inv_final_step.h"
#include "ui_add_data_to_inv_final_step.h"

add_data_to_inv_final_step::add_data_to_inv_final_step(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::add_data_to_inv_final_step)
{
    ui->setupUi(this);
    invoice_type = false;
    product_id = -1;
    department_id = -1;
}

add_data_to_inv_final_step::~add_data_to_inv_final_step(){
    delete ui;
    delete query;
    delete inv_model_;
    delete lop_model_;
}

void add_data_to_inv_final_step::set_invoice_type(bool &type){
    invoice_type = type;
    query = new QSqlQuery();
    query->exec(QString("select product_amount from list_of_products where [product_id (PK)] = %1").arg(product_id));
    while(query->next()){
        int product_amount = query->value(0).toInt();
        if (!invoice_type) ui->cur_product_count->setText(QString("0 < amount <= %1").arg(product_amount));
    }
}

void add_data_to_inv_final_step::set_product_and_department_id(int &pr_id, int &dp_id){
    department_id = dp_id;
    product_id = pr_id;
}

void add_data_to_inv_final_step::read_employees(){
    query = new QSqlQuery();
    query->exec(QString("select [employee_id (PK)],employee_FIO from list_of_employees where [employee_department_id (FK1)] = %1 and employee_dismissed = 0").arg(department_id));
    while(query->next()){
        int employee_id = query->value(0).toInt();
        QString employee_FIO = query->value(1).toString();
        ui->invoice_accepted->addItem(employee_FIO,employee_id);
        ui->invoice_passed->addItem(employee_FIO,employee_id);
    }
}

void add_data_to_inv_final_step::set_models(invoices_model &inv, lop_model &lop){
    inv_model_ = new invoices_model();
    lop_model_ = new lop_model();
    inv_model_ = &inv;
    lop_model_ = &lop;
}

void add_data_to_inv_final_step::on_add_data_clicked(){
    close();
    QString invoice_type_ = "";
    if (invoice_type) invoice_type_ = "Приходная";
    else invoice_type_ = "Расходная";
    QString invoice_document_number = ui->invoice_document_number->text();
    QString invoice_date_of_compilation = ui->invoice_date_of_compilation->text();
    int invoice_product_amount = ui->invoice_product_amount->text().toInt();
    double invoice_price_per_piece = ui->invoice_price_per_piece->text().toDouble();
    double invoice_total_sum = invoice_price_per_piece * invoice_product_amount;
    int invoice_accepted = ui->invoice_accepted->currentData().toInt();
    int invoice_passed = ui->invoice_passed->currentData().toInt();
    int product_amount_in_DB = 0;
    query->exec(QString("select product_amount from list_of_products where [product_id (PK)] = %1").arg(product_id));
    while(query->next()){
        product_amount_in_DB = query->value(0).toInt();
    }
    if (invoice_document_number.isEmpty() || invoice_date_of_compilation.isEmpty() || invoice_product_amount <= 0 || invoice_price_per_piece <= 0){
        QMessageBox::critical(this,"Статус","Заполнены не все поля или данные введены неккоректно!!!");
        return;
    }
    if (!invoice_type && invoice_product_amount > product_amount_in_DB){
        QMessageBox::critical(this,"Статус","Заполнены не все поля или данные введены неккоректно!!!");
        return;
    }
    //QMessageBox::information(this,"Статус","Успешно!");
    //qDebug() << invoice_type_ << ' ' << product_id << ' ' << department_id << ' ' << invoice_document_number << ' ' << invoice_date_of_compilation << ' ' << invoice_product_amount << ' ' << invoice_price_per_piece << ' ' << invoice_total_sum << ' ' << invoice_accepted << ' ' << invoice_passed;
    if (!query->exec(QString("add_values_in_invoices '%1','%2','%3',%4,%5,%6,%7,%8,%9,%10").arg(invoice_type_).arg(invoice_document_number).arg(invoice_date_of_compilation).arg(invoice_product_amount).arg(invoice_price_per_piece).arg(invoice_total_sum).arg(department_id).arg(product_id).arg(invoice_accepted).arg(invoice_passed))){
        QMessageBox::critical(this,"Статус","Ошибка добавления данных - " + query->lastError().text());
    }
    else{
        QMessageBox::information(this,"Статус","Успешно!");
        QSqlQuery *query_2 = new QSqlQuery();
        query_2->exec(QString("select * from invoices where invoice_document_number = '%1' and [invoice_department_id (FK1)] = %2 and [invoice_product_id (FK2)] = %3").arg(invoice_document_number).arg(department_id).arg(product_id));
        while(query_2->next()){
            int query_invoice_id = query_2->value(0).toInt();
            QString query_invoice_type = query_2->value(1).toString();
            QString query_invoice_document_number = query_2->value(2).toString();
            QString query_invoice_date_of_compilation = query_2->value(3).toString();
            int query_invoice_product_amount = query_2->value(4).toInt();
            double query_invoice_product_price_per_piece = query_2->value(5).toDouble();
            double query_invoice_product_total_sum = query_2->value(6).toDouble();
            int query_invoice_department_id = query_2->value(7).toInt();
            QString query_invoice_department_name = "";
            QSqlQuery *query_3 = new QSqlQuery();
            query_3->exec(QString("select department_name from information_about_departments where [department_id (PK)] = %1").arg(query_invoice_department_id));
            while(query_3->next()){
                query_invoice_department_name = query_3->value(0).toString();
            }
            int query_invoice_product_id = query_2->value(8).toInt();
            QString query_invoice_product_name = "";
            QSqlQuery *query_4 = new QSqlQuery();
            query_4->exec(QString("select product_name from list_of_products where [product_id (PK)] = %1").arg(product_id));
            while(query_4->next()){
                query_invoice_product_name = query_4->value(0).toString();
            }
            int query_invoice_accepted_id = query_2->value(9).toInt();
            QString query_invoice_accepted_FIO = "";
            QSqlQuery *query_5 = new QSqlQuery();
            query_5->exec(QString("select employee_FIO from list_of_employees where [employee_id (PK)] = %1").arg(query_invoice_accepted_id));
            while(query_5->next()){
                query_invoice_accepted_FIO = query_5->value(0).toString();
            }
            int query_invoice_passed_id = query_2->value(10).toInt();
            QString query_invoice_passed_FIO = "";
            QSqlQuery *query_6 = new QSqlQuery();
            query_6->exec(QString("select employee_FIO from list_of_employees where [employee_id (PK)] = %1").arg(query_invoice_passed_id));
            while(query_6->next()){
                query_invoice_passed_FIO = query_6->value(0).toString();
            }
            invoices_storage *data = new invoices_storage();
            data->add_data(query_invoice_id,query_invoice_type,query_invoice_document_number,query_invoice_date_of_compilation,query_invoice_product_id,query_invoice_product_name,query_invoice_department_id,query_invoice_department_name,query_invoice_accepted_id,query_invoice_accepted_FIO,query_invoice_passed_id,query_invoice_passed_FIO,query_invoice_product_amount,query_invoice_product_price_per_piece,query_invoice_product_total_sum);
            inv_model_->add_data(*data);
            for (int i = 0;i < lop_model_->size();i++){
                lop_storage *data;
                data = lop_model_->get_data_from_current_row(i);
                QString product_name_in_table = data->get_product_name();
                int product_amount_in_table = data->get_product_amount();
                if (product_name_in_table == query_invoice_product_name){
                    int sign = 1;
                    if (query_invoice_type == "Расходная") sign = -1;
                    int new_amount = product_amount_in_table + (sign * invoice_product_amount);
                    bool product_is_out_of_stock = false;
                    if (new_amount == 0) product_is_out_of_stock = true;
                    lop_model_->set_product_amount_and_present(i,new_amount,product_is_out_of_stock);
                    break;
                }
            }
            delete query_3;
            delete query_4;
            delete query_5;
            delete query_6;
            //delete data;
        }
        delete query_2;
    }
    //query->exec(QString("add_values_in_invoices '%1','%2','%3',%4,%5,%6,%7,%8,%9,%10").arg(invoice_type_).arg(invoice_document_number).arg(invoice_date_of_compilation).arg(invoice_product_amount).arg(invoice_price_per_piece).arg(invoice_total_sum).arg(department_id).arg(product_id).arg(invoice_accepted).arg(invoice_passed));
}

