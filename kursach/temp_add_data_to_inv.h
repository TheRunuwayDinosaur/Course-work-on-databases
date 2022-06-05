#ifndef TEMP_ADD_DATA_TO_INV_H
#define TEMP_ADD_DATA_TO_INV_H

#include <QWidget>
#include <
namespace Ui {
class temp_add_data_to_inv;
}

class temp_add_data_to_inv : public QWidget
{
    Q_OBJECT

public:
    explicit temp_add_data_to_inv(QWidget *parent = nullptr);
    ~temp_add_data_to_inv();

private:
    Ui::temp_add_data_to_inv *ui;
};

#endif // TEMP_ADD_DATA_TO_INV_H
