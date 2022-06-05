#include "lop_storage.h"


int lop_storage::get_product_id() const{
    return product_id;
}

QString lop_storage::get_product_name() const{
    return product_name;
}

int lop_storage::get_product_amount() const{
    return product_amount;
}

bool lop_storage::get_product_is_out_of_stock() const{
    return product_is_out_of_stock;
}

void lop_storage::set_product_amount(int &new_amount){
    product_amount = new_amount;
}

void lop_storage::set_product_is_out_of_stock(bool &product_is_out_of_stock_){
    product_is_out_of_stock = product_is_out_of_stock_;
}

void lop_storage::add_data(int &id,QString &name, int &product_amount_, bool &present){
    product_id = id,product_name = name, product_amount = product_amount_,product_is_out_of_stock = present;
}

void lop_storage::show_data(){
    qDebug() << product_id << ' ' << product_name << ' ' << product_amount << ' ' << product_is_out_of_stock;
}

