#ifndef LIST_OF_DISMISSED_EMPLOYEES_H
#define LIST_OF_DISMISSED_EMPLOYEES_H

#include <QWidget>
#include <list_of_dismissed_employees_model.h>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>

namespace Ui {
class list_of_dismissed_employees;
}

class list_of_dismissed_employees : public QWidget
{
    Q_OBJECT

public:
    explicit list_of_dismissed_employees(QWidget *parent = nullptr);
    ~list_of_dismissed_employees();
    void set_model();
private:
    Ui::list_of_dismissed_employees *ui;
    list_of_dismissed_employees_model *model;
    QSqlQuery *query;
};

#endif // LIST_OF_DISMISSED_EMPLOYEES_H
