#ifndef LOE_STORAGE_H
#define LOE_STORAGE_H
#include <QString>
#include <QDebug>

class loe_storage
{
public:
    loe_storage(int employee_id_ = -1,QString employee_FIO_ = "",QString employee_post_ = "",
                int employee_department_id_ = -1,QString employee_department_name_ = "",
                double employee_salary_ = 0.,bool employee_dismissed_ = false){
        employee_id = employee_id_,employee_FIO = employee_FIO_, employee_post = employee_post_,
        employee_department_id = employee_department_id_,employee_department_name = employee_department_name_,
        employee_salary = employee_salary_, employee_dismissed = employee_dismissed_;
    };
    int get_employee_id() const;
    QString get_employee_FIO() const;
    QString get_employee_post() const;
    int get_employee_department_id() const;
    QString get_employee_department_name() const;
    double get_employee_salary() const;
    bool get_employee_dismissed() const;
    void set_employee_dismissed(bool &employee_dismissed_);
    void set_employee_department_name(QString &new_department_name);
    void set_employee_salary(double &new_salary);
    void set_employee_post(QString &new_post);
    void add_data(int &employee_id_,QString &employee_FIO_,QString &employee_post_,int &employee_department_id_,QString &employee_department_name,double &employee_salary_,bool &employee_dismissed_);
    void show_data();
private:
    int employee_id;
    QString employee_FIO;
    QString employee_post;
    int employee_department_id;
    QString employee_department_name;
    double employee_salary;
    bool employee_dismissed;
};


#endif // LOE_STORAGE_H
