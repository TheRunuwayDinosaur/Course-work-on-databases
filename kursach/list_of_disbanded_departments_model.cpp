#include "list_of_disbanded_departments_model.h"

list_of_disbanded_departments_model::list_of_disbanded_departments_model(){

}

int list_of_disbanded_departments_model::rowCount(const QModelIndex &) const{
    return datas.size();
}

QVariant list_of_disbanded_departments_model::data(const QModelIndex &index, int role) const{
    if (!index.isValid() || role != Qt::DisplayRole) return QVariant();
    int row = index.row();
    return datas[row];
}

void list_of_disbanded_departments_model::add_data(QString &data){
    datas.append(data);
}
