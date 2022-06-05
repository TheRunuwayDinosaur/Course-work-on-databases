#include "add_data_in_dep.h"
#include "ui_add_data_in_dep.h"

add_data_in_dep::add_data_in_dep(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::add_data_in_dep)
{
    ui->setupUi(this);
}

add_data_in_dep::~add_data_in_dep(){
    delete ui;
    delete query;
    delete dep_model_;
}

void add_data_in_dep::set_model(departments_model &dep){
    dep_model_ = new departments_model();
    dep_model_ = &dep;
}

void add_data_in_dep::on_add_datas_clicked(){
    close();
    QString department_name = ui->department_name->text();
    QString department_address = ui->department_address->text();
    if (department_name.isEmpty() || department_address.isEmpty()){
        QMessageBox::critical(this,"Статус","Некоторые из полей пустые!!!");
        return;
    }
    //QMessageBox::information(this,"Статус","Успешно!");
    query = new QSqlQuery();
    if (!query->exec(QString("add_values_in_information_about_departments '%1','%2',%3").arg(department_name).arg(department_address).arg(0))){
        QMessageBox::critical(this,"Статус","Ошибка добавления данных - " + query->lastError().text());
    }
    else{
        QMessageBox::information(this,"Статус","Успешно!");
        QSqlQuery *query_2 = new QSqlQuery();
        query_2->exec(QString("select [department_id (PK)] from information_about_departments where department_name = '%1'").arg(department_name));
        int department_id = -1;
        while(query_2->next()){
            department_id = query_2->value(0).toInt();
        }
        bool departmet_disbanded = false;
        departments_storage *data = new departments_storage(department_id,department_name,department_address,departmet_disbanded);
        dep_model_->add_data(*data);
    }
    //query->exec(QString("add_values_in_information_about_departments '%1','%2',%3").arg(department_name).arg(department_address).arg(0));
}

