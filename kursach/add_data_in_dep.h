#ifndef ADD_DATA_IN_DEP_H
#define ADD_DATA_IN_DEP_H

#include <QWidget>
#include <QSqlQuery>
#include <QMessageBox>
#include <departments_storage.h>
#include <departments_model.h>
#include <QSqlError>
namespace Ui {
class add_data_in_dep;
}

class add_data_in_dep : public QWidget
{
    Q_OBJECT

public:
    explicit add_data_in_dep(QWidget *parent = nullptr);
    ~add_data_in_dep();
    void set_model(departments_model &dep);
private slots:
    void on_add_datas_clicked();

private:
    Ui::add_data_in_dep *ui;
    QSqlQuery *query;
    departments_model *dep_model_;
};

#endif // ADD_DATA_IN_DEP_H
