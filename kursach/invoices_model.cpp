#include "invoices_model.h"

invoices_model::invoices_model(){

}

int invoices_model::rowCount(const QModelIndex &) const{
    return invoices_data.size();
}

int invoices_model::columnCount(const QModelIndex &) const{
    return 15;
}

QVariant invoices_model::data(const QModelIndex &index, int role) const{
    if (!index.isValid() || role != Qt::DisplayRole) return QVariant();
    int row = index.row();
    switch (index.column()) {
        case 0: return invoices_data[row].get_invoice_id();
        case 1: return invoices_data[row].get_invoice_type();
        case 2: return invoices_data[row].get_invoice_document_number();
        case 3: return invoices_data[row].get_invoice_date_of_compilation();
        case 4: return invoices_data[row].get_invoice_product_id();
        case 5: return invoices_data[row].get_invoice_product_name();
        case 6: return invoices_data[row].get_invoice_department_id();
        case 7: return invoices_data[row].get_invoice_department_name();
        case 8: return invoices_data[row].get_invoice_accepted_id();
        case 9: return invoices_data[row].get_invoice_accepted();
        case 10: return invoices_data[row].get_invoice_passed_id();
        case 11: return invoices_data[row].get_invoice_passed();
        case 12: return invoices_data[row].get_invoice_product_amount();
        case 13: return invoices_data[row].get_invoice_product_price_per_piece();
        case 14: return invoices_data[row].get_invoice_product_total_sum();
    }
    return QVariant();
}


QVariant invoices_model::headerData(int section, Qt::Orientation orientation, int role) const{
    if (role != Qt::DisplayRole) return QVariant();
    if (orientation == Qt::Horizontal){
        switch (section) {
            case 0: return "id накладной";
            case 1: return "Тип накладной";
            case 2: return "Номер накладной";
            case 3: return "Дата составления";
            case 4: return "id товара";
            case 5: return "Наименование товара";
            case 6: return "id отдела";
            case 7: return "Наименование отдела";
            case 8: return "id принял";
            case 9: return "Принял";
            case 10: return "id сдал";
            case 11: return "Сдал";
            case 12: return "Количество товара";
            case 13: return "Цена за штуку (руб.)";
            case 14: return "Итоговая цена";
        }
    }
    else{
        return section + 1;
    }
    return QVariant();
}

void invoices_model::add_data(invoices_storage &data){
    beginInsertRows(QModelIndex(),invoices_data.size(),invoices_data.size());
    invoices_data.append(data);
    endInsertRows();
}

void invoices_model::delete_data(int &row){
    beginRemoveRows(QModelIndex(),row,row);
    invoices_data.removeAt(row);
    endRemoveRows();
}

int invoices_model::size(){
    return invoices_data.size();
}

invoices_storage *invoices_model::get_data_from_current_row(int &row){
    invoices_storage *data;
    data = &invoices_data[row];
    return data;
}

