#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->db_connection_status->setStyleSheet("QLabel {background-color : white; color : red; }");
    ui->lop_row_lb->hide(); ui->lop_row_le->hide();
    ui->dep_row_lb->hide(); ui->dep_row_le->hide();
    ui->loe_row_lb->hide(); ui->loe_row_le->hide();
    ui->inv_row_lb->hide(); ui->inv_row_le->hide();
    was_db_connected = false;
    setWindowTitle("Главное окно приложения");
}

MainWindow::~MainWindow(){
    delete ui;
    delete inv_model_;
    delete dep_model_;
    delete loe_model_;
    delete inv_model_;
    delete add_data;
    delete query;
    delete selects;
}

void MainWindow::update_connection(){
    query = new QSqlQuery();
    if (query->exec("select [employee_id (PK)] from list_of_employees")){
        was_db_connected = true;
    }
}

void MainWindow::constract_lop_model(){
    lop_model_ = new lop_model();
    query->exec("select * from list_of_products");
    while(query->next()){
        int product_id = query->value(0).toInt();
        QString product_name = query->value(1).toString();
        int product_amount = query->value(2).toInt();
        bool product_present_in_stock = query->value(3).toBool();
        lop_storage *data = new lop_storage();
        data->add_data(product_id,product_name,product_amount,product_present_in_stock);
        lop_model_->add_data(*data);
    }
    ui->table_of_products->setModel(lop_model_);
    ui->table_of_products->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    ui->table_of_products->setStyleSheet("QHeaderView::section { background-color: yellow }");
    ui->table_of_products->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->table_of_products->hideColumn(0);
}

void MainWindow::constract_dep_model(){
    dep_model_ = new departments_model;
    query = new QSqlQuery();
    query->exec("select * from information_about_departments");
    while(query->next()){
        int department_id = query->value(0).toInt();
        QString department_name = query->value(1).toString();
        QString department_address = query->value(2).toString();
        bool department_disbanded = query->value(3).toBool();
        departments_storage *data = new departments_storage();
        //qDebug() << id << ' ' << department_name << ' ' << department_address << ' ' << department_disbanded;
        data->add_data(department_id,department_name,department_address,department_disbanded);
        dep_model_->add_data(*data);
    }
    ui->table_of_deps->setModel(dep_model_);
    ui->table_of_deps->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    ui->table_of_deps->setStyleSheet("QHeaderView::section { background-color: yellow }");
    ui->table_of_deps->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->table_of_deps->hideColumn(0);
}

void MainWindow::constract_loe_model(){
    loe_model_ = new loe_model();
    query = new QSqlQuery();
    query->exec("select * from list_of_employees");
    while(query->next()){
        int employee_id = query->value(0).toInt();
        QString employee_FIO = query->value(1).toString();
        QString employee_post = query->value(2).toString();
        double employee_salary = query->value(3).toDouble();
        int employee_department_id = query->value(4).toInt();
        QSqlQuery *query_2 = new QSqlQuery();
        query_2->exec(QString("select department_name from information_about_departments where [department_id (PK)] = %1").arg(employee_department_id));
        QString employee_department_name = "";
        while(query_2->next()){
            employee_department_name = query_2->value(0).toString();
        }
        delete query_2;
        bool employee_dismissed = query->value(5).toBool();
        loe_storage *data = new loe_storage();
        data->add_data(employee_id,employee_FIO,employee_post,employee_department_id,employee_department_name,employee_salary,employee_dismissed);
        loe_model_->add_data(*data);
        //qDebug() << employee_id << ' ' << employee_FIO << ' ' << employee_post << ' ' << employee_department_id << ' ' << employee_department_name << ' ' << employee_salary << ' ' << employee_dismissed;
    }
    ui->table_of_employees->setModel(loe_model_);
    ui->table_of_employees->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    ui->table_of_employees->setStyleSheet("QHeaderView::section { background-color: yellow }");
    ui->table_of_employees->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->table_of_employees->hideColumn(0); ui->table_of_employees->hideColumn(4);
}

void MainWindow::constract_inv_model(){
    inv_model_ = new invoices_model();
    query = new QSqlQuery();
    query->exec("select * from invoices");
    while(query->next()){
        int invoice_id = query->value(0).toInt();
        QString invoice_type = query->value(1).toString();
        QString invoice_document_number = query->value(2).toString();
        QString invoice_date_of_compilation = query->value(3).toString();
        int invoice_product_amount = query->value(4).toInt();
        double invoice_product_price_per_piece = query->value(5).toDouble();
        double invoice_product_total_sum = query->value(6).toDouble();
        int invoice_department_id = query->value(7).toInt();
        QSqlQuery *query_2 = new QSqlQuery();
        query_2->exec(QString("select department_name from information_about_departments where [department_id (PK)] = %1").arg(invoice_department_id));
        QString invoice_department_name = "";
        while(query_2->next()){
            invoice_department_name = query_2->value(0).toString();
        }
        int invoice_product_id = query->value(8).toInt();
        QSqlQuery *query_3 = new QSqlQuery();
        query_3->exec(QString("select product_name from list_of_products where [product_id (PK)] = %1").arg(invoice_product_id));
        QString invoice_product_name = "";
        while(query_3->next()){
            invoice_product_name = query_3->value(0).toString();
        }
        int invoice_has_accepted_id = query->value(9).toInt();
        QSqlQuery *query_4 = new QSqlQuery();
        query_4->exec(QString("select employee_FIO from list_of_employees where [employee_id (PK)] = %1").arg(invoice_has_accepted_id));
        QString invoice_has_accepted_name = "";
        while(query_4->next()){
            invoice_has_accepted_name = query_4->value(0).toString();
        }
        int invoice_has_passed_id = query->value(10).toInt();
        QSqlQuery *query_5 = new QSqlQuery();
        query_5->exec(QString("select employee_FIO from list_of_employees where [employee_id (PK)] = %1").arg(invoice_has_passed_id));
        QString invoice_has_passed_name = "";
        while(query_5->next()){
            invoice_has_passed_name = query_5->value(0).toString();
        }
        delete query_2;
        delete query_3;
        delete query_4;
        delete query_5;
        invoices_storage *data = new invoices_storage();
        data->add_data(invoice_id,invoice_type,invoice_document_number,invoice_date_of_compilation,invoice_product_id,invoice_product_name,invoice_department_id,invoice_department_name,invoice_has_accepted_id,invoice_has_accepted_name,invoice_has_passed_id,invoice_has_passed_name,invoice_product_amount,invoice_product_price_per_piece,invoice_product_total_sum);
        inv_model_->add_data(*data);
        //qDebug() << invoice_id << ' ' << invoice_type << ' ' << invoice_document_number << ' ' << invoice_date_of_compilation << ' ' << invoice_product_amount << ' ' << invoice_product_price_per_piece << ' ' << invoice_product_total_sum << ' ' << invoice_department_id << ' ' << invoice_department_name << ' ' << invoice_product_id << ' ' << invoice_product_name << ' ' << invoice_has_accepted_id << ' ' << invoice_has_accepted_name << ' ' << invoice_has_passed_id << ' ' << invoice_has_passed_name;
    }
    ui->table_of_invoices->setModel(inv_model_);
    ui->table_of_invoices->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    ui->table_of_invoices->setStyleSheet("QHeaderView::section { background-color: yellow }");
    ui->table_of_invoices->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->table_of_invoices->hideColumn(0); ui->table_of_invoices->hideColumn(4);
    ui->table_of_invoices->hideColumn(6); ui->table_of_invoices->hideColumn(8);
    ui->table_of_invoices->hideColumn(10);
}


void MainWindow::on_connect_to_DB_triggered(){
    log = new login();
    log->show();
}


void MainWindow::on_add_data_to_DB_triggered(){
    add_data = new add_data_to_DB();
    add_data->set_models(*lop_model_,*dep_model_,*loe_model_,*inv_model_);
    add_data->show();
//    ui->table_of_deps->reset();
//    ui->table_of_employees->reset();
//    ui->table_of_invoices->reset();
//    ui->table_of_products->reset();
}



void MainWindow::on_update_connect_clicked(){
    update_connection();
    if (was_db_connected){
        QMessageBox::information(this,"Статус","Успешно!");
        ui->db_connection_status->setText("Соединение установлено :)");
        ui->db_connection_status->setStyleSheet("QLabel {background-color : white; color : green; }");
        constract_lop_model();
        constract_dep_model();
        constract_loe_model();
        constract_inv_model();
    }
    else QMessageBox::critical(this,"Статус","Ошибка - " + query->lastError().text());
}


void MainWindow::on_table_of_deps_clicked(const QModelIndex &index){
    int row = index.row();
    departments_storage *data;
    data = dep_model_->get_data_from_current_row(row);
    ui->dep_row_le->setText(QVariant(row).toString());
    ui->department_name_le->setText(data->get_department_name());
    ui->department_address_le->setText(data->get_department_address());
    //data->show_data();
    delete data;
}


void MainWindow::on_table_of_employees_clicked(const QModelIndex &index){
    int row = index.row();
    loe_storage *data;
    data = loe_model_->get_data_from_current_row(row);
    double employee_salary = data->get_employee_salary();
    QString employee_post = data->get_employee_post();
    QString employee_department_name = data->get_employee_department_name();
    QString employee_FIO = data->get_employee_FIO();
    ui->loe_row_le->setText(QVariant(row).toString());
    ui->employee_FIO_le->setText(employee_FIO);
    ui->employee_salary_le->setText(QVariant(employee_salary).toString());
    ui->employe_post_le->setText(employee_post);
    delete data;
}


void MainWindow::on_table_of_products_clicked(const QModelIndex &index){
    int row = index.row();
    lop_storage *data;
    data = lop_model_->get_data_from_current_row(row);
    QString product_name = data->get_product_name();
    int product_amount = data->get_product_amount();
    ui->lop_row_le->setText(QVariant(row).toString());
    ui->product_name_le->setText(product_name);
    ui->product_amount_le->setText(QVariant(product_amount).toString());
    delete data;
}




void MainWindow::on_change_data_in_lop_clicked(){
    int row = ui->lop_row_le->text().toInt();
    int new_amount = ui->product_amount_le->text().toInt();
    QString product_name = ui->product_name_le->text();
    if (new_amount < 0){
        QMessageBox::critical(this,"Статус","Недопустимое количество товара!!!");
        return;
    }
    bool product_is_out_of_stock = false;
    if (new_amount == 0) product_is_out_of_stock = true;
    query = new QSqlQuery();
    if (query->exec(QString("update_product_amount_in_list_of_products '%1',%2,%3").arg(product_name).arg(new_amount).arg(product_is_out_of_stock))){
        QMessageBox::information(this,"Статус","Успешно!");
    }
    else{
        QMessageBox::critical(this,"Статус","Не удалось изменить количество товара - " + query->lastError().text());
        return;
    }
    lop_model_->set_product_amount_and_present(row,new_amount,product_is_out_of_stock);
    ui->table_of_products->reset();
    ui->product_amount_le->setText("");
    ui->product_name_le->setText("");
}


void MainWindow::on_delete_data_from_lop_clicked(){
    int row = ui->lop_row_le->text().toInt();
    QString product_name = ui->product_name_le->text();
    lop_storage *data;
    data = lop_model_->get_data_from_current_row(row);
    bool product_is_out_of_stock_in_table = data->get_product_is_out_of_stock();
    if (product_is_out_of_stock_in_table){
        QMessageBox::critical(this,"Статус","Невозможно убрать товар со склада, т.к. его там уже нет!!!");
        return;
    }
    query = new QSqlQuery();
    query->exec(QString("select [product_id (PK)] from list_of_products where product_name = '%1'").arg(product_name));
    //query->bindValue(":1",product_name);
    int product_id = -1;
    while(query->next()){
        product_id = query->value(0).toInt();
    }
    //qDebug() << product_id;
    //return;
    int new_amount = 0;
    bool product_is_out_of_stock = true;
    QSqlQuery *query_2 = new QSqlQuery();
    if (query_2->exec(QString("delete_values_in_list_of_products %1").arg(product_id))){
        QMessageBox::information(this,"Статус","Успешно!");
    }
    else{
        QMessageBox::critical(this,"Статус","Ошибка удаления данных - " + query_2->lastError().text());
        return;
    }
    lop_model_->set_product_amount_and_present(row,new_amount,product_is_out_of_stock);
    ui->table_of_products->reset();
    ui->product_amount_le->setText("");
    ui->product_name_le->setText("");
    delete query_2;
}



void MainWindow::on_table_of_invoices_clicked(const QModelIndex &index){
    int row = index.row();
    invoices_storage *data;
    data = inv_model_->get_data_from_current_row(row);
    QString invoice_document_number = data->get_invoice_document_number();
    ui->invoice_document_number_le->setText(invoice_document_number);
    ui->inv_row_le->setText(QVariant(row).toString());
    //delete data;
}


void MainWindow::on_delete_data_from_inv_clicked(){
    QString invoice_document_number = ui->invoice_document_number_le->text();
    QList <int> rows;
    for (int i = 0;i < inv_model_->size();i++){
        invoices_storage *data;
        data = inv_model_->get_data_from_current_row(i);
        QString document_number = data->get_invoice_document_number();
        if (invoice_document_number == document_number){
            rows.append(i);
        }
        //delete data;
    }
    int cnt_deletable = 0;
    QSqlQuery *temp_query = new QSqlQuery();
    if (!temp_query->exec("delete_values_in_invoices '124545421425444'")){
        QMessageBox::critical(this,"Статус","Ошибка удаления данных - " + temp_query->lastError().text());
        delete temp_query;
        return;
    }
    for (auto& cur : rows){
        //qDebug() << cur;
        cur -= cnt_deletable;
        inv_model_->delete_data(cur);
        cnt_deletable++;
    }
    query = new QSqlQuery();
    if (query->exec(QString("delete_values_in_invoices '%1'").arg(invoice_document_number))){
        QMessageBox::information(this,"Статус","Успешно!");
    }
    else{
        QMessageBox::critical(this,"Статус","Ошибка удаления данных - " + query->lastError().text());
    }
    ui->inv_row_le->setText("");
    ui->invoice_document_number_le->setText("");
    delete temp_query;
}


void MainWindow::on_delete_data_in_dep_clicked(){
    int row = ui->dep_row_le->text().toInt();
    departments_storage *data;
    data = dep_model_->get_data_from_current_row(row);
    bool department_disbanded = true;
    bool deprtment_disbanded_in_table = data->get_department_disbanded();
    data->set_department_disbanded(department_disbanded);
    QString department_name = data->get_department_name();
    if (deprtment_disbanded_in_table){
        QMessageBox::critical(this,"Статус","Невозможно расформировать отдел, т.к. он уже расформирован!!!");
        return;
    }
    query = new QSqlQuery();
    for (int i = 0;i < loe_model_->size();i++){
        loe_storage *data_2;
        data_2 = loe_model_->get_data_from_current_row(i);
        QString employee_department_name = data_2->get_employee_department_name();
        if (employee_department_name == department_name){
            bool employee_dismissed = true;
            data_2->set_employee_dismissed(employee_dismissed);
            loe_model_->replace(i,*data_2);
        }
        delete data_2;
    }
    ui->table_of_employees->reset();
    int department_id = data->get_department_id();
    if (query->exec(QString("delete_values_in_list_of_departments %1").arg(department_id))){
        QMessageBox::information(this,"Статус","Успешно!");
        ui->dep_row_le->setText("");
    }
    else{
        QMessageBox::critical(this,"Статус","Ошибка удаления данных - " + query->lastError().text());
        return;
    }
    dep_model_->replace(row,*data);
    ui->table_of_deps->reset();
    ui->department_name_le->setText("");
    ui->department_address_le->setText("");
    delete data;
}


void MainWindow::on_delete_data_in_loe_clicked(){
    int row = ui->loe_row_le->text().toInt();
    loe_storage *data;
    data = loe_model_->get_data_from_current_row(row);
    bool employee_dissmised_in_table = data->get_employee_dismissed();
    bool employee_dismissed = true;
    data->set_employee_dismissed(employee_dismissed);
    if (employee_dissmised_in_table){
        QMessageBox::critical(this,"Статус","Невозможно уволить работника, т.к. он уже уволен!!!");
        return;
    }
    query = new QSqlQuery();
    int employee_id = data->get_employee_id();
    if (query->exec(QString("delete_values_in_list_of_employees %1").arg(employee_id))){
        QMessageBox::information(this,"Статус","Успешно!");
        loe_model_->replace(row,*data);
        ui->table_of_employees->reset();
    }
    else{
        QMessageBox::critical(this,"Статус","Ошибка удаления данных - " + query->lastError().text());
        return;
    }
    ui->loe_row_le->setText("");
    ui->employe_post_le->setText("");
    ui->employee_FIO_le->setText("");
    ui->employee_salary_le->setText("");
    delete data;
}


void MainWindow::on_change_data_in_dep_clicked(){
    int row = ui->dep_row_le->text().toInt();
    QString new_department_name = ui->department_name_le->text();
    QString new_department_address = ui->department_address_le->text();
    departments_storage *data;
    data = dep_model_->get_data_from_current_row(row);
    QString old_department_name = data->get_department_name();
    QString old_department_address = data->get_department_address();
    bool department_disbanded = data->get_department_disbanded();
    if (department_disbanded){
        QMessageBox::critical(this,"Статус","Невозможно изменить данные, т.к. отдел расформирован!!!");
        return;
    }
    query = new QSqlQuery();
    if (old_department_name != new_department_name){
        if (query->exec(QString("update_department_name_in_information_about_departments '%1','%2'").arg(old_department_name).arg(new_department_name))){
            QMessageBox::information(this,"Статус","Имя отдела успешно изменено!");
            data->set_department_name(new_department_name);
            dep_model_->replace(row,*data);
            for (int i = 0;i < loe_model_->size();i++){
                loe_storage *data_2;
                data_2 = loe_model_->get_data_from_current_row(i);
                QString employee_department_name = data_2->get_employee_department_name();
                if (employee_department_name == old_department_name){
                    data_2->set_employee_department_name(new_department_name);
                    loe_model_->replace(i,*data_2);
                }
                delete data_2;
            }
        }
        else{
            QMessageBox::critical(this,"Статус","Не удалось изменить имя отдела - " + query->lastError().text());
        }
    }
    if (old_department_address != new_department_address){
        QSqlQuery *query_2 = new QSqlQuery();
        if (query_2->exec(QString("update_department_address_in_information_about_departments '%1','%2'").arg(old_department_address).arg(new_department_address))){
            QMessageBox::information(this,"Статус","Адресс отдела успешно изменён!");
            data->set_department_address(new_department_address);
            dep_model_->replace(row,*data);
        }
        else{
            QMessageBox::critical(this,"Статус","Не удалось изменить адрес отдела - " + query_2->lastError().text());
        }
        delete query_2;
    }
    ui->table_of_deps->reset();
    ui->table_of_employees->reset();
    delete data;
    ui->department_name_le->setText("");
    ui->department_address_le->setText("");
}


void MainWindow::on_change_data_loe_clicked(){
    int row = ui->loe_row_le->text().toInt();
    loe_storage *data;
    data = loe_model_->get_data_from_current_row(row);
    //data->show_data();
    double old_salary = data->get_employee_salary();
    QString old_post = data->get_employee_post();
    double new_salary = ui->employee_salary_le->text().toDouble();
    QString new_post = ui->employe_post_le->text();
    bool employee_dissmised = data->get_employee_dismissed();
    if (employee_dissmised){
        QMessageBox::critical(this,"Статус","Невозможно изменить данные, т.к. работник уволен!!!");
        return;
    }
    if (old_salary != new_salary){
        query = new QSqlQuery();
        int employee_id = data->get_employee_id();
        if (query->exec(QString("update_employee_salary_in_list_of_employees %1,%2").arg(employee_id).arg(new_salary))){
            QMessageBox::information(this,"Статус","Оклад успешно изменён!");
            data->set_employee_salary(new_salary);
            loe_model_->replace(row,*data);
        }
        else{
            QMessageBox::critical(this,"Статус","Не удалось изменить оклад работника - " + query->lastError().text());
        }
    }
    if (old_post != new_post){
        QSqlQuery *query_2 = new QSqlQuery();
        int employee_id = data->get_employee_id();
        if (query_2->exec(QString("update_employee_post_in_list_of_employees %1,'%2'").arg(employee_id).arg(new_post))){
            QMessageBox::information(this,"Статус","Должность работника успешно изменена!");
            data->set_employee_post(new_post);
            loe_model_->replace(row,*data);
        }
        else{
            QMessageBox::critical(this,"Статус","Не удалось изменить должность работника - " + query_2->lastError().text());
        }
        delete query_2;
    }
    ui->table_of_employees->reset();
    delete data;
    ui->employe_post_le->setText("");
    ui->employee_salary_le->setText("");
    ui->employee_FIO_le->setText("");
}


void MainWindow::on_querys_triggered(){
    selects = new all_selects();
    selects->show();
}

