#ifndef GET_ALL_THE_GOODS_FROM_THE_INVOICE_H
#define GET_ALL_THE_GOODS_FROM_THE_INVOICE_H

#include <QWidget>
#include <get_all_the_goods_from_the_invoice_model.h>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include <set>
#include <QDebug>
namespace Ui {
class get_all_the_goods_from_the_invoice;
}

class get_all_the_goods_from_the_invoice : public QWidget
{
    Q_OBJECT

public:
    explicit get_all_the_goods_from_the_invoice(QWidget *parent = nullptr);
    ~get_all_the_goods_from_the_invoice();
    void set_model();
private slots:
    void on_show_clicked();

private:
    Ui::get_all_the_goods_from_the_invoice *ui;
    QSqlQuery *query;
    get_all_the_goods_from_the_invoice_model *model;
};

#endif // GET_ALL_THE_GOODS_FROM_THE_INVOICE_H
