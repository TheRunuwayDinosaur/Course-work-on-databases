#ifndef DEPARTMENTS_STORAGE_H
#define DEPARTMENTS_STORAGE_H
#include <QString>
#include <QDebug>

class departments_storage{
public:
    departments_storage(int department_id_ = -1,QString department_name_ = "",QString department_address_ = "",bool department_disbanded_ = false){
        department_id = department_id_,department_name = department_name_,department_address = department_address_,
        department_disbanded = department_disbanded_;
    };
    int get_department_id() const;
    QString get_department_name() const;
    QString get_department_address() const;
    bool get_department_disbanded() const;
    void set_department_disbanded(bool &department_disbanded_);
    void set_department_name(QString &new_department_name);
    void set_department_address(QString &new_department_address);
    void add_data(int &department_id_,QString &department_name_,QString &department_address_,bool &department_disbanded_);
    void show_data();
private:
    int department_id;
    QString department_name;
    QString department_address;
    bool department_disbanded;
};


#endif // DEPARTMENTS_STORAGE_H
