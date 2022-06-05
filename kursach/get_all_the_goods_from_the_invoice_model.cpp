#include "get_all_the_goods_from_the_invoice_model.h"

get_all_the_goods_from_the_invoice_model::get_all_the_goods_from_the_invoice_model(){

}

int get_all_the_goods_from_the_invoice_model::rowCount(const QModelIndex &) const{
    return datas.size();
}

QVariant get_all_the_goods_from_the_invoice_model::data(const QModelIndex &index, int role) const{
    if (!index.isValid() || role != Qt::DisplayRole) return QVariant();
    int row = index.row();
    return datas[row];
}

void get_all_the_goods_from_the_invoice_model::add_data(QString &data){
    datas.append(data);
}
