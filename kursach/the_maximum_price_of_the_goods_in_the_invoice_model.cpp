#include "the_maximum_price_of_the_goods_in_the_invoice_model.h"

the_maximum_price_of_the_goods_in_the_invoice_model::the_maximum_price_of_the_goods_in_the_invoice_model(){

}

int the_maximum_price_of_the_goods_in_the_invoice_model::rowCount(const QModelIndex &) const{
    return datas.size();
}

int the_maximum_price_of_the_goods_in_the_invoice_model::columnCount(const QModelIndex &) const{
    return 3;
}

QVariant the_maximum_price_of_the_goods_in_the_invoice_model::data(const QModelIndex &index, int role) const{
    if (!index.isValid() || role != Qt::DisplayRole) return QVariant();
    int row = index.row();
    switch (index.column()) {
        case 0: return datas[row].get_invoice_document_number();
        case 1: return datas[row].get_product_name();
        case 2: return datas[row].get_product_total_sum();
    }
    return QVariant();
}

QVariant the_maximum_price_of_the_goods_in_the_invoice_model::headerData(int section, Qt::Orientation orientation, int role) const{
    if (role != Qt::DisplayRole) return QVariant();
    if (orientation == Qt::Horizontal){
        switch (section) {
            case 0: return "Номер накладной";
            case 1: return "Наименование товара";
            case 2: return "Итоговая сумма товара в накладной";
        }
    }
    else{
        return section + 1;
    }
return QVariant();
}

void the_maximum_price_of_the_goods_in_the_invoice_model::add_data(the_maximum_price_of_the_goods_in_the_invoice_storage &data){
    datas.append(data);
}
