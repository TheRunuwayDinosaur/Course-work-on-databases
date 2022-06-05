#ifndef LIST_OF_DISBANDED_DEPARTMENTS_H
#define LIST_OF_DISBANDED_DEPARTMENTS_H

#include <QWidget>
#include <list_of_disbanded_departments_model.h>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>

namespace Ui {
class list_of_disbanded_departments;
}

class list_of_disbanded_departments : public QWidget
{
    Q_OBJECT

public:
    explicit list_of_disbanded_departments(QWidget *parent = nullptr);
    ~list_of_disbanded_departments();
    void set_model();
private:
    Ui::list_of_disbanded_departments *ui;
    list_of_disbanded_departments_model *model;
    QSqlQuery *query;
};

#endif // LIST_OF_DISBANDED_DEPARTMENTS_H
