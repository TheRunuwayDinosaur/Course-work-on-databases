#ifndef PROFIT_FOR_A_CERTAIN_PRODUCT_STORAGE_H
#define PROFIT_FOR_A_CERTAIN_PRODUCT_STORAGE_H
#include <QString>
class profit_for_a_certain_product_storage{
public:
    profit_for_a_certain_product_storage(QString product_name_ = "",double product_total_sum_ = 0.){
        product_name = product_name_,product_total_sum = product_total_sum_;
    };
    void add_data(QString &product_name_,double &product_total_sum_);
    QString get_product_name() const;
    double get_product_total_sum() const;
private:
    QString product_name;
    double product_total_sum;
};

#endif // PROFIT_FOR_A_CERTAIN_PRODUCT_STORAGE_H
