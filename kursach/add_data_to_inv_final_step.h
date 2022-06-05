#ifndef ADD_DATA_TO_INV_FINAL_STEP_H
#define ADD_DATA_TO_INV_FINAL_STEP_H

#include <QWidget>
#include <QSqlQuery>
#include <QMessageBox>
#include <QDebug>
#include <QSqlError>
#include <invoices_model.h>
#include <lop_model.h>
#include <invoices_storage.h>
#include <lop_storage.h>

namespace Ui {
class add_data_to_inv_final_step;
}

class add_data_to_inv_final_step : public QWidget
{
    Q_OBJECT

public:
    explicit add_data_to_inv_final_step(QWidget *parent = nullptr);
    ~add_data_to_inv_final_step();
    void set_invoice_type(bool &type);
    void set_product_and_department_id(int &pr_id,int &dp_id);
    void read_employees();
    void set_models(invoices_model &inv,lop_model &lop);
private slots:
    void on_add_data_clicked();

private:
    Ui::add_data_to_inv_final_step *ui;
    QSqlQuery *query;
    bool invoice_type;
    int department_id;
    int product_id;
    invoices_model *inv_model_;
    lop_model *lop_model_;
};

#endif // ADD_DATA_TO_INV_FINAL_STEP_H
