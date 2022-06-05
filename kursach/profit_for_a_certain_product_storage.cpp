#include "profit_for_a_certain_product_storage.h"

void profit_for_a_certain_product_storage::add_data(QString &product_name_, double &product_total_sum_){
    product_name = product_name_,product_total_sum = product_total_sum_;
}

QString profit_for_a_certain_product_storage::get_product_name() const{
    return product_name;
}

double profit_for_a_certain_product_storage::get_product_total_sum() const{
    return product_total_sum;
}
