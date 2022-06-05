#ifndef LIST_OF_DISBANDED_DEPARTMENTS_MODEL_H
#define LIST_OF_DISBANDED_DEPARTMENTS_MODEL_H
#include <QAbstractListModel>
#include <QList>
class list_of_disbanded_departments_model : public QAbstractListModel
{
    Q_OBJECT
public:
    list_of_disbanded_departments_model();
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    void add_data(QString &data);
private:
    QList <QString> datas;
};

#endif // LIST_OF_DISBANDED_DEPARTMENTS_MODEL_H
