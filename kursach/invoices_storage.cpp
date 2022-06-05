#include "invoices_storage.h"


int invoices_storage::get_invoice_id() const{
    return invoice_id;
}

QString invoices_storage::get_invoice_type() const{
    return invoice_type;
}

QString invoices_storage::get_invoice_document_number() const{
    return invoice_document_number;
}

QString invoices_storage::get_invoice_date_of_compilation() const{
    return invoice_date_of_compilation;
}

int invoices_storage::get_invoice_product_id() const{
    return invoice_product_id;
}

QString invoices_storage::get_invoice_product_name() const{
    return invoice_product_name;
}

int invoices_storage::get_invoice_department_id() const{
    return invoice_department_id;
}

QString invoices_storage::get_invoice_department_name() const{
    return invoice_department_name;
}

int invoices_storage::get_invoice_accepted_id() const{
    return invoice_accepted_id;
}

QString invoices_storage::get_invoice_accepted() const{
    return invoice_accepted;
}

int invoices_storage::get_invoice_passed_id() const{
    return invoice_passed_id;
}

QString invoices_storage::get_invoice_passed() const{
    return invoice_passed;
}

int invoices_storage::get_invoice_product_amount() const{
    return invoice_product_amount;
}

double invoices_storage::get_invoice_product_price_per_piece() const{
    return invoice_product_price_per_piece;
}

double invoices_storage::get_invoice_product_total_sum() const{
   return invoice_product_total_sum;
}

void invoices_storage::add_data(int &invoice_id_,QString &invoice_type_, QString &invoice_document_number_, QString &invoice_date_of_compilation_,int &invoice_product_id_,QString &invoice_product_name_,int &invoice_department_id_,QString &invoice_department_name_,int &invoice_accepted_id_,QString &invoice_accepted_,int &invoice_passed_id_,QString &invoice_passed_, int &invoice_product_amount_, double &invoice_product_price_per_piece_, double &invoice_product_total_sum_){
    invoice_id = invoice_id_,invoice_type = invoice_type_,invoice_document_number = invoice_document_number_,
    invoice_date_of_compilation = invoice_date_of_compilation_,invoice_product_id = invoice_product_id_,invoice_product_name = invoice_product_name_,
    invoice_department_id = invoice_department_id_,invoice_department_name = invoice_department_name_,invoice_accepted_id = invoice_accepted_id_,invoice_accepted = invoice_accepted_,
    invoice_passed_id = invoice_passed_id_,invoice_passed = invoice_passed_,invoice_product_amount = invoice_product_amount_,
    invoice_product_price_per_piece = invoice_product_price_per_piece_,invoice_product_total_sum = invoice_product_total_sum_;
}

void invoices_storage::show_data(){
    qDebug() << invoice_id << ' ' << invoice_type << ' ' << invoice_document_number << ' ' << invoice_date_of_compilation << ' ' << invoice_product_id << ' ' << invoice_product_name << ' ' << invoice_department_id << ' ' << invoice_department_name << ' ' << invoice_accepted_id << ' ' << invoice_accepted << ' ' << invoice_passed_id << ' ' << invoice_passed << ' ' << invoice_product_amount << ' ' << invoice_product_price_per_piece << ' ' << invoice_product_total_sum;
}
