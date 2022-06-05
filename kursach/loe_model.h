#ifndef LOE_MODEL_H
#define LOE_MODEL_H
#include <QAbstractTableModel>
#include <QList>
#include <loe_storage.h>
#include <QMap>
#include <departments_model.h>

class loe_model : public QAbstractTableModel
{
    Q_OBJECT
public:
    loe_model();
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    QVariant headerData(int section, Qt::Orientation orientation,
                                int role = Qt::DisplayRole) const;
    void add_data(loe_storage &data);
    void replace(int &row,loe_storage &data);
    int size();
    loe_storage *get_data_from_current_row(int &row);
private:
    QList <loe_storage> employees_data;
};

#endif // LOE_MODEL_H
