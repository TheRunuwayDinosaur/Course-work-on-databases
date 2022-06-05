#ifndef LOP_MODEL_H
#define LOP_MODEL_H
#include <QAbstractTableModel>
#include <QList>
#include <lop_storage.h>
#include <QMap>
class lop_model : public QAbstractTableModel
{
    Q_OBJECT
public:
    lop_model();
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    QVariant headerData(int section, Qt::Orientation orientation,
                                int role = Qt::DisplayRole) const;
    void set_product_amount_and_present(int &row,int &amount,bool &product_is_out_of_stock);
    void add_data(lop_storage &data);
    void clear();
    lop_storage *get_data_from_current_row(int &row);
    int size();
private:
    QList <lop_storage> products_data;
};

#endif // LOP_MODEL_H
