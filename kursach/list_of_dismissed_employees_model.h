#ifndef LIST_OF_DISMISSED_EMPLOYEES_MODEL_H
#define LIST_OF_DISMISSED_EMPLOYEES_MODEL_H
#include <QAbstractListModel>

class list_of_dismissed_employees_model : public QAbstractListModel
{
    Q_OBJECT
public:
    list_of_dismissed_employees_model();
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    void add_data(QString &data);
private:
    QList <QString> datas;
};

#endif // LIST_OF_DISMISSED_EMPLOYEES_MODEL_H
