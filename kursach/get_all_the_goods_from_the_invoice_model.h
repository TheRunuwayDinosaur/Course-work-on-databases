#ifndef GET_ALL_THE_GOODS_FROM_THE_INVOICE_MODEL_H
#define GET_ALL_THE_GOODS_FROM_THE_INVOICE_MODEL_H
#include <QAbstractListModel>
#include <QList>

class get_all_the_goods_from_the_invoice_model : public QAbstractListModel
{
    Q_OBJECT
public:
    get_all_the_goods_from_the_invoice_model();
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    void add_data(QString &data);
private:
    QList <QString> datas;
};

#endif // GET_ALL_THE_GOODS_FROM_THE_INVOICE_MODEL_H
