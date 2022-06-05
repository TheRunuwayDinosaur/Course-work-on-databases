#include "add_data_to_db.h"
#include "ui_add_data_to_db.h"
//#include <mainwindow.h>

add_data_to_DB::add_data_to_DB(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::add_data_to_DB)
{
    ui->setupUi(this);
    setWindowTitle("Добавление данных");
}

add_data_to_DB::~add_data_to_DB(){
    delete ui;
    delete add_lop;
    delete add_dep;
    delete add_loe;
    delete add_inv_first;
    delete lop_model_;
    delete loe_model_;
    delete dep_model_;
    delete inv_model_;
}

void add_data_to_DB::set_models(lop_model &lop, departments_model &dep, loe_model &loe, invoices_model &inv){
    lop_model_ = new lop_model();
    dep_model_ = new departments_model();
    loe_model_ = new loe_model();
    inv_model_ = new invoices_model();
    lop_model_ = &lop,dep_model_ = &dep,loe_model_ = &loe,inv_model_ = &inv;
}

void add_data_to_DB::on_add_to_lop_clicked(){
    add_lop = new add_data_in_lop();
    add_lop->set_model(*lop_model_);
    add_lop->show();
}


void add_data_to_DB::on_add_to_dep_clicked(){
    add_dep = new add_data_in_dep();
    add_dep->set_model(*dep_model_);
    add_dep->show();
}


void add_data_to_DB::on_add_to_loe_clicked(){
    add_loe = new add_data_to_loe();
    add_loe->read_deparments();
    add_loe->set_model(*loe_model_);
    add_loe->show();
}


void add_data_to_DB::on_add_to_inv_clicked(){
    add_inv_first = new add_data_to_inv_first_step();
    add_inv_first->set_models(*inv_model_,*lop_model_);
    add_inv_first->show();
}

