#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <ui_login.h>
#include <ui_add_data_in_database.h>
#include <QSqlQueryModel>
#include <QSqlTableModel>
#include <QMap>
#include <lop_model.h>
#include <departments_model.h>
#include <loe_model.h>
#include <invoices_model.h>
#include <QSqlDatabase>
#include <login.h>
#include <add_data_to_db.h>
#include <all_selects.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void update_connection();
    void constract_lop_model();
    void constract_dep_model();
    void constract_loe_model();
    void constract_inv_model();
private slots:

    void on_connect_to_DB_triggered();

    void on_add_data_to_DB_triggered();

    void on_update_connect_clicked();

    void on_table_of_deps_clicked(const QModelIndex &index);

    void on_table_of_employees_clicked(const QModelIndex &index);

    void on_table_of_products_clicked(const QModelIndex &index);

    void on_change_data_in_lop_clicked();

    void on_delete_data_from_lop_clicked();

    void on_table_of_invoices_clicked(const QModelIndex &index);

    void on_delete_data_from_inv_clicked();

    void on_delete_data_in_dep_clicked();

    void on_delete_data_in_loe_clicked();

    void on_change_data_in_dep_clicked();

    void on_change_data_loe_clicked();

    void on_querys_triggered();

private:
    QSqlDatabase db;
    Ui::MainWindow *ui;
    QSqlQuery *query;
    departments_model *dep_model_;
    loe_model *loe_model_;
    lop_model *lop_model_;
    invoices_model *inv_model_;
    login *log;
    add_data_to_DB *add_data;
    bool was_db_connected;
    all_selects *selects;
};
#endif // MAINWINDOW_H
