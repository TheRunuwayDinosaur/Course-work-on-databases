#ifndef ALL_SELECTS_H
#define ALL_SELECTS_H

#include <QWidget>
#include <profit_for_a_certain_product.h>
#include <list_of_dismissed_employees.h>
#include <list_of_disbanded_departments.h>
#include <get_all_the_goods_from_the_invoice.h>
#include <QDebug>
#include <the_maximum_price_of_the_goods_in_the_invoice.h>

namespace Ui {
class all_selects;
}

class all_selects : public QWidget
{
    Q_OBJECT

public:
    explicit all_selects(QWidget *parent = nullptr);
    ~all_selects();

private slots:
    void on_profit_for_a_certain_product_clicked();

    void on_list_of_dismissed_emloyees_clicked();

    void on_list_of_disbanded_departments_clicked();

    void on_get_all_the_goods_from_the_invoice_clicked();

    void on_the_maximum_price_of_the_goods_in_the_invoice_clicked();

    void on_all_profit_clicked();

private:
    Ui::all_selects *ui;
    profit_for_a_certain_product *prf;
    list_of_dismissed_employees *lode;
    list_of_disbanded_departments *lodd;
    get_all_the_goods_from_the_invoice *gath;
    the_maximum_price_of_the_goods_in_the_invoice *tmr;
};

#endif // ALL_SELECTS_H
