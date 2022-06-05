#include "departments_storage.h"

int departments_storage::get_department_id() const{
    return department_id;
}

QString departments_storage::get_department_name() const{
    return department_name;
}

QString departments_storage::get_department_address() const{
    return department_address;
}

bool departments_storage::get_department_disbanded() const{
    return department_disbanded;
}

void departments_storage::set_department_disbanded(bool &department_disbanded_){
    department_disbanded = department_disbanded_;
}

void departments_storage::set_department_name(QString &new_department_name){
    department_name = new_department_name;
}

void departments_storage::set_department_address(QString &new_department_address){
    department_address = new_department_address;
}

void departments_storage::add_data(int &department_id_,QString &department_name_, QString &department_address_, bool &department_disbanded_){
    department_id = department_id_;
    department_name = department_name_;
    department_address = department_address_;
    department_disbanded = department_disbanded_;
}

void departments_storage::show_data(){
    qDebug() << department_id << ' ' << department_name << ' ' << department_address << ' ' << department_disbanded;
}
