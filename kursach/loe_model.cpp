#include "loe_model.h"

loe_model::loe_model(){

}

int loe_model::rowCount(const QModelIndex &) const{
    return employees_data.size();
}

int loe_model::columnCount(const QModelIndex &) const{
    return 7;
}

QVariant loe_model::data(const QModelIndex &index, int role) const{
    if (!index.isValid() || role != Qt::DisplayRole) return QVariant();
    int row = index.row();
    switch (index.column()) {
        case 0: return employees_data[row].get_employee_id();
        case 1: return employees_data[row].get_employee_FIO();
        case 2: return employees_data[row].get_employee_post();
        case 3: return employees_data[row].get_employee_salary();
        case 4: return employees_data[row].get_employee_department_id();
        case 5: return employees_data[row].get_employee_department_name();
        case 6:
            if (employees_data[row].get_employee_dismissed()) return "Да";
            else return "Нет";
    }
    return QVariant();
}


QVariant loe_model::headerData(int section, Qt::Orientation orientation, int role) const{
    if (role != Qt::DisplayRole) return QVariant();
    if (orientation == Qt::Horizontal){
        switch (section) {
            case 0: return "id работника";
            case 1: return "ФИО работника";
            case 2: return "Должность работника";
            case 3: return "Оклад";
            case 4: return "Номер отдела";
            case 5: return "Наименование отдела";
            case 6: return "Уволен (Да / нет)";
        }
    }
    else{
        return section + 1;
    }
    return QVariant();
}

void loe_model::add_data(loe_storage &data){
    beginInsertRows(QModelIndex(),employees_data.size(),employees_data.size());
    employees_data.append(data);
    endInsertRows();
}

void loe_model::replace(int &row, loe_storage &data){
    employees_data.replace(row,data);
}

int loe_model::size(){
    return employees_data.size();
}

loe_storage *loe_model::get_data_from_current_row(int &row){
    loe_storage *data = new loe_storage();
    int employee_id = employees_data[row].get_employee_id();
    QString employee_FIO = employees_data[row].get_employee_FIO();
    QString employee_post = employees_data[row].get_employee_post();
    double employee_salary = employees_data[row].get_employee_salary();
    int employee_department_id = employees_data[row].get_employee_department_id();
    QString employee_department_name = employees_data[row].get_employee_department_name();
    bool employee_dismissed = employees_data[row].get_employee_dismissed();
    data->add_data(employee_id,employee_FIO,employee_post,employee_department_id,employee_department_name,employee_salary,employee_dismissed);
    return data;
}

