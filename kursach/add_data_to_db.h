#ifndef ADD_DATA_TO_DB_H
#define ADD_DATA_TO_DB_H

#include <QWidget>
#include <add_data_in_lop.h>
#include <add_data_in_dep.h>
#include <add_data_to_loe.h>
#include <add_data_to_inv_first_step.h>
#include <lop_model.h>
#include <departments_model.h>
#include <loe_model.h>
#include <invoices_model.h>

namespace Ui {
class add_data_to_DB;
}

class add_data_to_DB : public QWidget
{
    Q_OBJECT

public:
    explicit add_data_to_DB(QWidget *parent = nullptr);
    ~add_data_to_DB();
    void set_models(lop_model &lop,departments_model &dep,loe_model &loe,invoices_model &inv);
private slots:
    void on_add_to_lop_clicked();

    void on_add_to_dep_clicked();

    void on_add_to_loe_clicked();

    void on_add_to_inv_clicked();

private:
    Ui::add_data_to_DB *ui;
    add_data_in_lop *add_lop;
    add_data_in_dep *add_dep;
    add_data_to_loe *add_loe;
    add_data_to_inv_first_step *add_inv_first;
    lop_model *lop_model_;
    departments_model *dep_model_;
    loe_model *loe_model_;
    invoices_model *inv_model_;
};

#endif // ADD_DATA_TO_DB_H
