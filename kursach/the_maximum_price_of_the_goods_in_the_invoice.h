#ifndef THE_MAXIMUM_PRICE_OF_THE_GOODS_IN_THE_INVOICE_H
#define THE_MAXIMUM_PRICE_OF_THE_GOODS_IN_THE_INVOICE_H

#include <QWidget>
#include <the_maximum_price_of_the_goods_in_the_invoice_model.h>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include <set>
#include <QDebug>

namespace Ui {
class the_maximum_price_of_the_goods_in_the_invoice;
}

class the_maximum_price_of_the_goods_in_the_invoice : public QWidget
{
    Q_OBJECT

public:
    explicit the_maximum_price_of_the_goods_in_the_invoice(QWidget *parent = nullptr);
    ~the_maximum_price_of_the_goods_in_the_invoice();
    void add_invoices();
private slots:
    void on_show_clicked();

private:
    Ui::the_maximum_price_of_the_goods_in_the_invoice *ui;
    QSqlQuery *query;
    the_maximum_price_of_the_goods_in_the_invoice_model *model;
};

#endif // THE_MAXIMUM_PRICE_OF_THE_GOODS_IN_THE_INVOICE_H
