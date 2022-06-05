#include "temp_add_data_to_inv.h"
#include "ui_temp_add_data_to_inv.h"

temp_add_data_to_inv::temp_add_data_to_inv(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::temp_add_data_to_inv)
{
    ui->setupUi(this);
}

temp_add_data_to_inv::~temp_add_data_to_inv()
{
    delete ui;
}
