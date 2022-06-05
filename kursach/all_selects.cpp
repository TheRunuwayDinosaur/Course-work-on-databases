#include "all_selects.h"
#include "ui_all_selects.h"

all_selects::all_selects(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::all_selects)
{
    ui->setupUi(this);
    setWindowTitle("Меню запросов");
}

all_selects::~all_selects(){
    delete ui;
    delete prf;
    delete lode;
    delete lodd;
    delete gath;
    delete tmr;
}

void all_selects::on_profit_for_a_certain_product_clicked(){
    prf = new profit_for_a_certain_product();
    prf->add_products();
    prf->show();
}


void all_selects::on_list_of_dismissed_emloyees_clicked(){
    lode = new list_of_dismissed_employees();
    lode->set_model();
    lode->show();
}


void all_selects::on_list_of_disbanded_departments_clicked(){
    lodd = new list_of_disbanded_departments();
    lodd->set_model();
    lodd->show();
}


void all_selects::on_get_all_the_goods_from_the_invoice_clicked(){
    gath = new get_all_the_goods_from_the_invoice();
    gath->set_model();
    gath->show();
}


void all_selects::on_the_maximum_price_of_the_goods_in_the_invoice_clicked(){
    tmr = new the_maximum_price_of_the_goods_in_the_invoice();
    tmr->add_invoices();
    tmr->show();
}


void all_selects::on_all_profit_clicked(){
    QSqlQuery *query = new QSqlQuery();
    if (query->exec("select [dbo].[profit_for_all_products]() as all_profit")){
        double all_profit = 0.;
        while(query->next()){
            all_profit = query->value(0).toDouble();
        }
        QMessageBox::information(this,"Прибыль","Текущая прибыль - " + QVariant(all_profit).toString() + " руб.");
    }
    else QMessageBox::critical(this,"Статус","Ошибка - " + query->lastError().text());
    delete query;
}

