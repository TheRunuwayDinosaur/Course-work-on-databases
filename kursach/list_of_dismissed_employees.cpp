#include "list_of_dismissed_employees.h"
#include "ui_list_of_dismissed_employees.h"

list_of_dismissed_employees::list_of_dismissed_employees(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::list_of_dismissed_employees)
{
    ui->setupUi(this);
    setWindowTitle("Уволенные работники");
}

list_of_dismissed_employees::~list_of_dismissed_employees(){
    delete ui;
    delete model;
    delete query;
}

void list_of_dismissed_employees::set_model(){
    model = new list_of_dismissed_employees_model();
    query = new QSqlQuery();
    if (query->exec("select employee_FIO from list_of_employees where employee_dismissed = 1")){
        while(query->next()){
            QString employee_FIO = query->value(0).toString();
            model->add_data(employee_FIO);
        }
        ui->listView->setModel(model);
    }
    else{
        QMessageBox::critical(this,"Статус","Ошибка - " + query->lastError().text());
    }
}
