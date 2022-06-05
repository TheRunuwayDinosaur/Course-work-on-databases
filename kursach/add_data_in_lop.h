#ifndef ADD_DATA_IN_LOP_H
#define ADD_DATA_IN_LOP_H

#include <QWidget>
#include <QSqlQuery>
#include <QDebug>
#include <QMessageBox>
#include <lop_model.h>
#include <lop_storage.h>
#include <QSqlError>

namespace Ui {
class add_data_in_lop;
}

class add_data_in_lop : public QWidget
{
    Q_OBJECT

public:
    explicit add_data_in_lop(QWidget *parent = nullptr);
    ~add_data_in_lop();
    void set_model(lop_model &lop);
private slots:
    void on_add_datas_clicked();
private:
    Ui::add_data_in_lop *ui;
    QSqlQuery *query;
    lop_model *lop_model_;
};

#endif // ADD_DATA_IN_LOP_H
