#ifndef PROFIT_FOR_A_CERTAIN_PRODUCT_MODEL_H
#define PROFIT_FOR_A_CERTAIN_PRODUCT_MODEL_H
#include <QAbstractTableModel>
#include <QList>
#include <profit_for_a_certain_product_storage.h>

class profit_for_a_certain_product_model : public QAbstractTableModel
{
    Q_OBJECT
public:
    profit_for_a_certain_product_model();
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    QVariant headerData(int section, Qt::Orientation orientation,
                                    int role = Qt::DisplayRole) const;
    void add_data(profit_for_a_certain_product_storage &data_);
private:
    QList <profit_for_a_certain_product_storage> datas;
};

#endif // PROFIT_FOR_A_CERTAIN_PRODUCT_MODEL_H
