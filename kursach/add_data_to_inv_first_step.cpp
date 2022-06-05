#include "add_data_to_inv_first_step.h"
#include "ui_add_data_to_inv_first_step.h"

add_data_to_inv_first_step::add_data_to_inv_first_step(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::add_data_to_inv_first_step)
{
    ui->setupUi(this);
}

add_data_to_inv_first_step::~add_data_to_inv_first_step(){
    delete ui;
    delete second_step;
    delete inv_model_;
    delete lop_model_;
}

void add_data_to_inv_first_step::set_models(invoices_model &inv, lop_model &lop){
    inv_model_ = new invoices_model();
    lop_model_ = new lop_model();
    inv_model_ = &inv;
    lop_model_ = &lop;
}

void add_data_to_inv_first_step::on_next_step_clicked(){
    close();
    second_step = new add_data_to_inv_second_step();
    int id = ui->invoice_type->currentIndex();
    second_step->set_invoice_type(id);
    second_step->read_departments();
    second_step->read_products();
    second_step->set_models(*inv_model_,*lop_model_);
    second_step->show();
}

