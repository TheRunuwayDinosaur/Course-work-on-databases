#ifndef ADD_DATA_TO_INV_FIRST_STEP_H
#define ADD_DATA_TO_INV_FIRST_STEP_H

#include <QWidget>
#include <add_data_to_inv_second_step.h>
#include <invoices_model.h>
#include <lop_model.h>

namespace Ui {
class add_data_to_inv_first_step;
}

class add_data_to_inv_first_step : public QWidget
{
    Q_OBJECT

public:
    explicit add_data_to_inv_first_step(QWidget *parent = nullptr);
    ~add_data_to_inv_first_step();
    void set_models(invoices_model &inv,lop_model &lop);
private slots:
    void on_next_step_clicked();

private:
    Ui::add_data_to_inv_first_step *ui;
    add_data_to_inv_second_step *second_step;
    invoices_model *inv_model_;
    lop_model *lop_model_;
};

#endif // ADD_DATA_TO_INV_FIRST_STEP_H
