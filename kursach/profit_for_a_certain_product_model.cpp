#include "profit_for_a_certain_product_model.h"

profit_for_a_certain_product_model::profit_for_a_certain_product_model(){

}

int profit_for_a_certain_product_model::rowCount(const QModelIndex &) const{
    return datas.size();
}

int profit_for_a_certain_product_model::columnCount(const QModelIndex &) const{
    return 2;
}

QVariant profit_for_a_certain_product_model::data(const QModelIndex &index, int role) const{
    if (!index.isValid() || role != Qt::DisplayRole) return QVariant();
    int row = index.row();
    switch (index.column()) {
        case 0: return datas[row].get_product_name();
        case 1: return datas[row].get_product_total_sum();
    }
    return QVariant();
}

QVariant profit_for_a_certain_product_model::headerData(int section, Qt::Orientation orientation, int role) const{
    if (role != Qt::DisplayRole) return QVariant();
    if (orientation == Qt::Horizontal){
        switch (section) {
            case 0: return "Наименование товара";
            case 1: return "Прибыль за товар";
        }
    }
    else{
        return section + 1;
    }
    return QVariant();
}

void profit_for_a_certain_product_model::add_data(profit_for_a_certain_product_storage &data_){
    datas.append(data_);
}
