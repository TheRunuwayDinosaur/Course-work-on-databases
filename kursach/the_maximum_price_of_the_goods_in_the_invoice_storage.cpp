#include "the_maximum_price_of_the_goods_in_the_invoice_storage.h"

void the_maximum_price_of_the_goods_in_the_invoice_storage::add_data(QString &invoice_document_number_, QString &product_name_, double &product_total_sum_){
    invoice_document_number = invoice_document_number_;
    product_name = product_name_;
    product_total_sum = product_total_sum_;
}

QString the_maximum_price_of_the_goods_in_the_invoice_storage::get_invoice_document_number() const{
    return invoice_document_number;
}

QString the_maximum_price_of_the_goods_in_the_invoice_storage::get_product_name() const{
    return product_name;
}

double the_maximum_price_of_the_goods_in_the_invoice_storage::get_product_total_sum() const{
    return product_total_sum;
}
