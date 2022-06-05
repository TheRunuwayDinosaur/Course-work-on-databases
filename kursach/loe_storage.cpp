#include "loe_storage.h"

int loe_storage::get_employee_id() const{
    return employee_id;
}

QString loe_storage::get_employee_FIO() const{
    return employee_FIO;
}

QString loe_storage::get_employee_post() const{
    return employee_post;
}

int loe_storage::get_employee_department_id() const{
    return employee_department_id;
}

QString loe_storage::get_employee_department_name() const{
    return employee_department_name;
}

double loe_storage::get_employee_salary() const{
    return employee_salary;
}

bool loe_storage::get_employee_dismissed() const{
    return employee_dismissed;
}

void loe_storage::set_employee_dismissed(bool &employee_dismissed_){
    employee_dismissed = employee_dismissed_;
}

void loe_storage::set_employee_department_name(QString &new_department_name){
    employee_department_name = new_department_name;
}

void loe_storage::set_employee_salary(double &new_salary){
    employee_salary = new_salary;
}

void loe_storage::set_employee_post(QString &new_post){
    employee_post = new_post;
}

void loe_storage::add_data(int &employee_id_,QString &employee_FIO_, QString &employee_post_,int &employee_department_id_,QString &employee_department_name_,double &employee_salary_, bool &employee_dismissed_){
    employee_id = employee_id_;
    employee_FIO = employee_FIO_;
    employee_post = employee_post_;
    employee_department_id = employee_department_id_;
    employee_department_name = employee_department_name_;
    employee_salary = employee_salary_;
    employee_dismissed = employee_dismissed_;
}

void loe_storage::show_data(){
    qDebug() << employee_id << ' ' << employee_FIO << ' ' << employee_post << ' ' << ' ' << employee_department_id << ' ' << employee_department_name << ' ' << employee_salary << ' ' << employee_dismissed;
}
