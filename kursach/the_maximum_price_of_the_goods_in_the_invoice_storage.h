#ifndef THE_MAXIMUM_PRICE_OF_THE_GOODS_IN_THE_INVOICE_STORAGE_H
#define THE_MAXIMUM_PRICE_OF_THE_GOODS_IN_THE_INVOICE_STORAGE_H
#include <QString>

class the_maximum_price_of_the_goods_in_the_invoice_storage
{
public:
    the_maximum_price_of_the_goods_in_the_invoice_storage(QString invoice_document_number_ = "",QString product_name_ = "",double product_total_sum_ = 0.){
        invoice_document_number = invoice_document_number_,product_name = product_name_,product_total_sum = product_total_sum_;
    };
    void add_data(QString &invoice_document_number_,QString &product_name_,double &product_total_sum_);
    QString get_invoice_document_number() const;
    QString get_product_name() const;
    double get_product_total_sum() const;
private:
    QString invoice_document_number;
    QString product_name;
    double product_total_sum;
};

#endif // THE_MAXIMUM_PRICE_OF_THE_GOODS_IN_THE_INVOICE_STORAGE_H
