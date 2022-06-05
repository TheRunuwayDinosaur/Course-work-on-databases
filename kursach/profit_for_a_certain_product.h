#ifndef PROFIT_FOR_A_CERTAIN_PRODUCT_H
#define PROFIT_FOR_A_CERTAIN_PRODUCT_H

#include <QWidget>
#include <QSqlQuery>
#include <profit_for_a_certain_product_model.h>
#include <QMessageBox>
#include <QSqlError>
#include <QDebug>
#include <profit_for_a_certain_product_storage.h>

namespace Ui {
class profit_for_a_certain_product;
}

class profit_for_a_certain_product : public QWidget
{
    Q_OBJECT

public:
    explicit profit_for_a_certain_product(QWidget *parent = nullptr);
    ~profit_for_a_certain_product();
    void add_products();
private slots:
    void on_show_in_table_clicked();

private:
    Ui::profit_for_a_certain_product *ui;
    QSqlQuery *query;
    profit_for_a_certain_product_model *model;
};

#endif // PROFIT_FOR_A_CERTAIN_PRODUCT_H
