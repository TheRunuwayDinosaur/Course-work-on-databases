#include "add_data_to_inv_second_step.h"
#include "ui_add_data_to_inv_second_step.h"

add_data_to_inv_second_step::add_data_to_inv_second_step(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::add_data_to_inv_second_step)
{
    ui->setupUi(this);
    invoice_type = false;
}

add_data_to_inv_second_step::~add_data_to_inv_second_step(){
    delete ui;
    delete query;
    delete final_step;
    delete inv_model_;
    delete lop_model_;
}

void add_data_to_inv_second_step::set_invoice_type(int &id){
    if (id == 0) invoice_type = true;
}

void add_data_to_inv_second_step::read_departments(){
    query = new QSqlQuery();
    query->exec("select [department_id (PK)],department_name from information_about_departments where departmet_disbanded = 0");
    while(query->next()){
        int department_id = query->value(0).toInt();
        QString department_name = query->value(1).toString();
        QSqlQuery *query_2 = new QSqlQuery();
        query_2->exec(QString("select [employee_id (PK)] from list_of_employees where [employee_department_id (FK1)] = %1 and employee_dismissed = 0").arg(department_id));
        int count_employees = 0;
        while(query_2->next()){
            count_employees++;
        }
        if (count_employees > 0) ui->invoice_department_name->addItem(department_name,department_id);
    }
}

void add_data_to_inv_second_step::read_products(){
    query = new QSqlQuery();
    if (!invoice_type) query->exec("select [product_id (PK)],product_name from list_of_products where product_is_out_of_stock = 0");
    else query->exec("select [product_id (PK)],product_name from list_of_products");
    while(query->next()){
        int product_id = query->value(0).toInt();
        QString product_name =  query->value(1).toString();
        ui->invoice_product_name->addItem(product_name,product_id);
    }
}

void add_data_to_inv_second_step::set_models(invoices_model &inv, lop_model &lop){
    inv_model_ = new invoices_model();
    lop_model_ = new lop_model();
    inv_model_ = &inv;
    lop_model_ = &lop;
}


void add_data_to_inv_second_step::on_next_step_clicked(){
    close();
    int product_id = ui->invoice_product_name->currentData().toInt();
    int department_id = ui->invoice_department_name->currentData().toInt();
    final_step = new add_data_to_inv_final_step();
    final_step->set_product_and_department_id(product_id,department_id);
    final_step->set_invoice_type(invoice_type);
    final_step->read_employees();
    final_step->set_models(*inv_model_,*lop_model_);
    final_step->show();
}

