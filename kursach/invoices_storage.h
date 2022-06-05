#ifndef INVOICES_STORAGE_H
#define INVOICES_STORAGE_H
#include <QString>
#include <QDebug>
class invoices_storage
{
public:
    invoices_storage(int invoice_id_ = -1,
                    QString invoice_type_ = "",
                    QString invoice_document_number_ = "",
                    QString invoice_date_of_compilation_ = "",
                    int invoice_product_id_ = -1,
                    QString invoice_product_name_ = "",
                    int invoice_department_id_ = -1,
                    QString invoice_department_name_ = "",
                    int invoice_accepted_id_ = -1,
                    QString invoice_accepted_ = "",
                    int invoice_passed_id_ = -1,
                    QString invoice_passed_ = "",
                    int invoice_product_amount_ = 0,
                    double invoice_product_price_per_piece_ = 0.,
                    double invoice_product_total_sum_ = 0.){
        invoice_id = invoice_id_,invoice_type = invoice_type_,invoice_document_number = invoice_document_number_,
        invoice_date_of_compilation = invoice_date_of_compilation_,invoice_product_id = invoice_product_id_,invoice_product_name = invoice_product_name_,
        invoice_department_id = invoice_department_id_,invoice_department_name = invoice_department_name_,
        invoice_accepted_id = invoice_accepted_id_,invoice_accepted = invoice_accepted_,invoice_passed_id = invoice_passed_id_,invoice_passed = invoice_passed_,
        invoice_product_amount = invoice_product_amount_,
        invoice_product_price_per_piece = invoice_product_price_per_piece_,
        invoice_product_total_sum = invoice_product_total_sum_;
    };
    int get_invoice_id() const;
    QString get_invoice_type() const;
    QString get_invoice_document_number() const;
    QString get_invoice_date_of_compilation() const;
    int get_invoice_product_id() const;
    QString get_invoice_product_name() const;
    int get_invoice_department_id() const;
    QString get_invoice_department_name() const;
    int get_invoice_accepted_id() const;
    QString get_invoice_accepted() const;
    int get_invoice_passed_id() const;
    QString get_invoice_passed() const;
    int get_invoice_product_amount() const;
    double get_invoice_product_price_per_piece() const;
    double get_invoice_product_total_sum() const;
    void add_data(int &invoice_id_,QString &invoice_type_,QString &invoice_document_number_,QString &invoice_date_of_compilation_,int &invoice_product_id_,QString &invoice_product_name_,int &invoice_department_id_,QString &invoice_department_name_,int &invoice_accepted_id_,QString &invoice_accepted_,int &invoice_passed_id_,QString &invoice_passed_,int &invoice_product_amount_,double &invoice_product_price_per_piece_,double &invoice_product_total_sum_);
    void show_data();
private:
    int invoice_id;
    QString invoice_type;
    QString invoice_document_number;
    QString invoice_date_of_compilation;
    int invoice_product_id;
    QString invoice_product_name;
    int invoice_department_id;
    QString invoice_department_name;
    int invoice_accepted_id;
    QString invoice_accepted;
    int invoice_passed_id;
    QString invoice_passed;
    int invoice_product_amount;
    double invoice_product_price_per_piece;
    double invoice_product_total_sum;
};

#endif // INVOICES_STORAGE_H
