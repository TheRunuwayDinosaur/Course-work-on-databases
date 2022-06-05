#ifndef ADD_DATA_TO_INV_SECOND_STEP_H
#define ADD_DATA_TO_INV_SECOND_STEP_H

#include <QWidget>
#include <QSqlQuery>
#include <QDebug>
#include <add_data_to_inv_final_step.h>
#include <invoices_model.h>
#include <lop_model.h>

namespace Ui {
class add_data_to_inv_second_step;
}

class add_data_to_inv_second_step : public QWidget
{
    Q_OBJECT

public:
    explicit add_data_to_inv_second_step(QWidget *parent = nullptr);
    ~add_data_to_inv_second_step();
    void set_invoice_type(int &id);
    void read_departments();
    void read_products();
    void set_models(invoices_model &inv,lop_model &lop);
private slots:
    void on_next_step_clicked();

private:
    Ui::add_data_to_inv_second_step *ui;
    bool invoice_type;
    QSqlQuery *query;
    add_data_to_inv_final_step *final_step;
    invoices_model *inv_model_;
    lop_model *lop_model_;
};

#endif // ADD_DATA_TO_INV_SECOND_STEP_H
