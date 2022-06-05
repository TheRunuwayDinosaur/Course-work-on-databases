#include "departments_model.h"

departments_model::departments_model(){

}

int departments_model::rowCount(const QModelIndex &) const{
    return departments_data.size();
}

int departments_model::columnCount(const QModelIndex &) const{
    return 4;
}

QVariant departments_model::data(const QModelIndex &index, int role) const{
    if (!index.isValid() || role != Qt::DisplayRole) return QVariant();
    int row = index.row();
    switch(index.column()){
        case 0: return departments_data[row].get_department_id();
        case 1: return departments_data[row].get_department_name();
        case 2: return departments_data[row].get_department_address();
        case 3:
            if (departments_data[row].get_department_disbanded()) return "Да";
            else return "Нет";
    }
    return QVariant();
}

QVariant departments_model::headerData(int section, Qt::Orientation orientation, int role) const{
    if (role != Qt::DisplayRole) return QVariant();
    if (orientation == Qt::Horizontal){
        switch (section) {
            case 0: return "id Отдела";
            case 1: return "Наименование отдела";
            case 2: return "Адрес отдела";
            case 3: return "Расформирован (Да / Нет)";
        }
    }
    else{
        return section + 1;
    }
    return QVariant();
}

void departments_model::add_data(departments_storage &data){
    beginInsertRows(QModelIndex(),departments_data.size(),departments_data.size());
    departments_data.append(data);
    endInsertRows();
}

void departments_model::replace(int &row, departments_storage &data){
    departments_data.replace(row,data);
}

departments_storage *departments_model::get_data_from_current_row(int &row){
    departments_storage *data = new departments_storage();
    int department_id = departments_data[row].get_department_id();
    QString department_name = departments_data[row].get_department_name();
    QString department_address = departments_data[row].get_department_address();
    bool department_disbanded = departments_data[row].get_department_disbanded();
    data->add_data(department_id,department_name,department_address,department_disbanded);
    return data;
}



