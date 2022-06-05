#ifndef DEPARTMENTS_MODEL_H
#define DEPARTMENTS_MODEL_H
#include <departments_storage.h>
#include <QList>
#include <QMap>
#include <QAbstractTableModel>

class departments_model : public QAbstractTableModel
{
    Q_OBJECT
public:
    departments_model();
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    QVariant headerData(int section, Qt::Orientation orientation,
                                int role = Qt::DisplayRole) const;
    void add_data(departments_storage &data);
    void replace(int &row,departments_storage &data);
    departments_storage *get_data_from_current_row(int &row);
private:
    QList <departments_storage> departments_data;
};

#endif // DEPARTMENTS_MODEL_H
