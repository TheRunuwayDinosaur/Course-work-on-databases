#ifndef ADD_DATA_TO_LOE_H
#define ADD_DATA_TO_LOE_H

#include <QWidget>
#include <QSqlQuery>
#include <QDebug>
#include <QMessageBox>
#include <QSqlError>
#include <loe_model.h>

namespace Ui {
class add_data_to_loe;
}

class add_data_to_loe : public QWidget
{
    Q_OBJECT

public:
    explicit add_data_to_loe(QWidget *parent = nullptr);
    ~add_data_to_loe();
    void read_deparments();
    void set_model(loe_model &loe);
private slots:
    void on_pushButton_clicked();

private:
    QSqlQuery *query;
    Ui::add_data_to_loe *ui;
    loe_model *loe_model_;
};

#endif // ADD_DATA_TO_LOE_H
