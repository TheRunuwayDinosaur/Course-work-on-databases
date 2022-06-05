#include "lop_model.h"

lop_model::lop_model(){

}

int lop_model::rowCount(const QModelIndex &) const{
    return products_data.size();
}

int lop_model::columnCount(const QModelIndex &) const{
    return 4;
}

QVariant lop_model::data(const QModelIndex &index, int role) const{
    if (!index.isValid() || role != Qt::DisplayRole) return QVariant();
    int row = index.row();
    switch(index.column()){
        case 0: return products_data[row].get_product_id();
        case 1: return products_data[row].get_product_name();
        case 2: return products_data[row].get_product_amount();
        case 3:
            if (products_data[row].get_product_is_out_of_stock()) return "Да";
            else return "Нет";
    }
    return QVariant();
}

QVariant lop_model::headerData(int section, Qt::Orientation orientation, int role) const{
    if (role != Qt::DisplayRole) return QVariant();
    if (orientation == Qt::Horizontal){
        switch (section) {
            case 1: return "Наименование товара";
            case 2: return "Количество на складе";
            case 3: return "Отсутсвует на складе (Да / Нет)";
        }
    }
    else{
        return section + 1;
    }
    return QVariant();
}

void lop_model::set_product_amount_and_present(int &row, int &amount, bool &product_is_out_of_stock){
    lop_storage *data;
    data = get_data_from_current_row(row);
    data->set_product_amount(amount);
    data->set_product_is_out_of_stock(product_is_out_of_stock);
    products_data.replace(row,*data);
    delete data;
}

void lop_model::add_data(lop_storage &data){
    beginInsertRows(QModelIndex(),products_data.size(),products_data.size());
    products_data.append(data);
    endInsertRows();
}

void lop_model::clear(){
    products_data.clear();
}

lop_storage *lop_model::get_data_from_current_row(int &row){
    lop_storage *data = new lop_storage();
    int product_id = products_data[row].get_product_id();
    QString product_name = products_data[row].get_product_name();
    int product_amount = products_data[row].get_product_amount();
    bool product_present_in_stock = products_data[row].get_product_is_out_of_stock();
    data->add_data(product_id,product_name,product_amount,product_present_in_stock);
    return data;
}

int lop_model::size(){
    return products_data.size();
}

