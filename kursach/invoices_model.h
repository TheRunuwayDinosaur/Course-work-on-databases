#ifndef INVOICES_MODEL_H
#define INVOICES_MODEL_H
#include <invoices_storage.h>
#include <QAbstractTableModel>
#include <QMap>
#include <invoices_storage.h>

class invoices_model : public QAbstractTableModel
{
    Q_OBJECT
public:
    invoices_model();
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    QVariant headerData(int section, Qt::Orientation orientation,
                                int role = Qt::DisplayRole) const;
    void add_data(invoices_storage &data);
    void delete_data(int &row);
    int size();
    invoices_storage *get_data_from_current_row(int &row);
private:
    QList <invoices_storage> invoices_data;
};

#endif // INVOICES_MODEL_H
