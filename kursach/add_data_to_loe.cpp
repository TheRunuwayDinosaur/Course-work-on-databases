#include "add_data_to_loe.h"
#include "ui_add_data_to_loe.h"

add_data_to_loe::add_data_to_loe(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::add_data_to_loe)
{
    ui->setupUi(this);
}

add_data_to_loe::~add_data_to_loe(){
    delete ui;
    delete query;
}

void add_data_to_loe::read_deparments(){
    query = new QSqlQuery();
    query->exec("select [department_id (PK)],department_name from information_about_departments where departmet_disbanded = 0");
    while(query->next()){
        int department_id = query->value(0).toInt();
        QString department_name = query->value(1).toString();
        ui->employee_departments->addItem(department_name,department_id);
        //qDebug() << department_id << ' ' << department_name;
    }
}

void add_data_to_loe::set_model(loe_model &loe){
    loe_model_ = new loe_model();
    loe_model_ = &loe;
}

void add_data_to_loe::on_pushButton_clicked(){
    close();
    QString employee_FIO = ui->employee_FIO->text();
    QString employee_post = ui->employee_post->text();
    double employee_salary = ui->employee_salary->text().toDouble();
    int employee_deparment_id = ui->employee_departments->currentData().toInt();
    if (employee_FIO.isEmpty() || employee_post.isEmpty() || employee_salary <= 0){
        QMessageBox::critical(this,"Статус","Ошибка, заполнены не все поля или данные введены неккоректно!!!");
        return;
    }
    //QMessageBox::information(this,"Статус","Успешно!");
    query = new QSqlQuery();
    //query->exec("add_values_in_list_of_employees 'Прохорова Камилла Алановна','Бухгалтер',8914796513,6,1");
    if (!query->exec(QString("add_values_in_list_of_employees '%1','%2',%3,%4,%5").arg(employee_FIO).arg(employee_post).arg(employee_salary).arg(employee_deparment_id).arg(0))){
        QMessageBox::critical(this,"Статус","Ошибка добавления данных - " + query->lastError().text());
    }
    else{
        QMessageBox::information(this,"Статус","Успешно!");
        QSqlQuery *query_2 = new QSqlQuery();
        query_2->exec(QString("select department_name from information_about_departments where [department_id (PK)] = %1").arg(employee_deparment_id));
        QString employee_department_name = "";
        while(query_2->next()){
            employee_department_name = query_2->value(0).toString();
        }
        QSqlQuery *query_3 = new QSqlQuery();
        query_3->exec(QString("select [employee_id (PK)] from list_of_employees where employee_FIO = '%1'").arg(employee_FIO));
        int employee_id = -1;
        while(query_3->next()){
            employee_id = query_3->value(0).toInt();
        }
        bool employee_dismissed = false;
        delete query_2;
        delete query_3;
        loe_storage *data = new loe_storage();
        data->add_data(employee_id,employee_FIO,employee_post,employee_deparment_id,employee_department_name,employee_salary,employee_dismissed);

        loe_model_->add_data(*data);
        //qDebug() << employee_id << ' ' << employee_FIO << ' ' << employee_post << ' ' << employee_salary << ' ' << employee_deparment_id << ' ' << employee_department_name << ' ' << employee_dismissed;
    }
    //query->exec(QString("add_values_in_list_of_employees '%1','%2',%3,%4,%5").arg(employee_FIO).arg(employee_post).arg(employee_salary).arg(employee_deparment).arg(0));
}

