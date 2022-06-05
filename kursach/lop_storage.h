#ifndef LOP_STORAGE_H
#define LOP_STORAGE_H
#include <QString>
#include <QDebug>
class lop_storage{
public:
    lop_storage(int product_id_ = -1,QString name_ = "",int amount_ = -1,bool present = false){
        product_id = product_id_,product_name = name_,
        product_amount = amount_, product_is_out_of_stock = present;
    };
    int get_product_id() const;
    QString get_product_name() const;
    int get_product_amount() const;
    bool get_product_is_out_of_stock() const;
    void set_product_amount(int &new_amount);
    void set_product_is_out_of_stock(bool &product_is_out_of_stock_);
    void add_data(int &id,QString &name,int &product_amount_,bool &present);
    void show_data();
private:
    int product_id;
    QString product_name;
    int product_amount;
    bool product_is_out_of_stock;
};

#endif // LOP_STORAGE_H
