#include "list_of_disbanded_departments.h"
#include "ui_list_of_disbanded_departments.h"

list_of_disbanded_departments::list_of_disbanded_departments(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::list_of_disbanded_departments)
{
    ui->setupUi(this);
    setWindowTitle("Расформированные отделы");
}

list_of_disbanded_departments::~list_of_disbanded_departments(){
    delete ui;
    delete model;
    delete query;
}

void list_of_disbanded_departments::set_model(){
    model = new list_of_disbanded_departments_model();
    query = new QSqlQuery();
    if (query->exec("select department_name from information_about_departments where departmet_disbanded = 1")){
        while(query->next()){
            QString product_name = query->value(0).toString();
            model->add_data(product_name);
        }
        ui->listView->setModel(model);
    }
    else{
        QMessageBox::critical(this,"Статус","Ошибка - " + query->lastError().text());
    }
}
