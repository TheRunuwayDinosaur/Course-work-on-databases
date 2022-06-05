#ifndef THE_MAXIMUM_PRICE_OF_THE_GOODS_IN_THE_INVOICE_MODEL_H
#define THE_MAXIMUM_PRICE_OF_THE_GOODS_IN_THE_INVOICE_MODEL_H

#include <QAbstractTableModel>
#include <QList>
#include <the_maximum_price_of_the_goods_in_the_invoice_storage.h>

class the_maximum_price_of_the_goods_in_the_invoice_model : public QAbstractTableModel
{
    Q_OBJECT
public:
    the_maximum_price_of_the_goods_in_the_invoice_model();
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    QVariant headerData(int section, Qt::Orientation orientation,
                                    int role = Qt::DisplayRole) const;
    void add_data(the_maximum_price_of_the_goods_in_the_invoice_storage &data);
private:
    QList <the_maximum_price_of_the_goods_in_the_invoice_storage> datas;
};

#endif // THE_MAXIMUM_PRICE_OF_THE_GOODS_IN_THE_INVOICE_MODEL_H
