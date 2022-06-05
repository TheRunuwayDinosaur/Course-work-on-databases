QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    add_data_in_dep.cpp \
    add_data_in_lop.cpp \
    add_data_to_db.cpp \
    add_data_to_inv_final_step.cpp \
    add_data_to_inv_first_step.cpp \
    add_data_to_inv_second_step.cpp \
    add_data_to_loe.cpp \
    all_selects.cpp \
    departments_model.cpp \
    departments_storage.cpp \
    get_all_the_goods_from_the_invoice.cpp \
    get_all_the_goods_from_the_invoice_model.cpp \
    invoices_model.cpp \
    invoices_storage.cpp \
    list_of_disbanded_departments.cpp \
    list_of_disbanded_departments_model.cpp \
    list_of_dismissed_employees.cpp \
    list_of_dismissed_employees_model.cpp \
    loe_model.cpp \
    loe_storage.cpp \
    login.cpp \
    lop_model.cpp \
    lop_storage.cpp \
    main.cpp \
    mainwindow.cpp \
    profit_for_a_certain_product.cpp \
    profit_for_a_certain_product_model.cpp \
    profit_for_a_certain_product_storage.cpp \
    the_maximum_price_of_the_goods_in_the_invoice.cpp \
    the_maximum_price_of_the_goods_in_the_invoice_model.cpp \
    the_maximum_price_of_the_goods_in_the_invoice_storage.cpp

HEADERS += \
    add_data_in_dep.h \
    add_data_in_lop.h \
    add_data_to_db.h \
    add_data_to_inv_final_step.h \
    add_data_to_inv_first_step.h \
    add_data_to_inv_second_step.h \
    add_data_to_loe.h \
    all_selects.h \
    departments_model.h \
    departments_storage.h \
    get_all_the_goods_from_the_invoice.h \
    get_all_the_goods_from_the_invoice_model.h \
    invoices_model.h \
    invoices_storage.h \
    list_of_disbanded_departments.h \
    list_of_disbanded_departments_model.h \
    list_of_dismissed_employees.h \
    list_of_dismissed_employees_model.h \
    loe_model.h \
    loe_storage.h \
    login.h \
    lop_model.h \
    lop_storage.h \
    mainwindow.h \
    profit_for_a_certain_product.h \
    profit_for_a_certain_product_model.h \
    profit_for_a_certain_product_storage.h \
    the_maximum_price_of_the_goods_in_the_invoice.h \
    the_maximum_price_of_the_goods_in_the_invoice_model.h \
    the_maximum_price_of_the_goods_in_the_invoice_storage.h

FORMS += \
    add_data_in_dep.ui \
    add_data_in_lop.ui \
    add_data_to_db.ui \
    add_data_to_inv_final_step.ui \
    add_data_to_inv_first_step.ui \
    add_data_to_inv_second_step.ui \
    add_data_to_loe.ui \
    all_selects.ui \
    get_all_the_goods_from_the_invoice.ui \
    list_of_disbanded_departments.ui \
    list_of_dismissed_employees.ui \
    login.ui \
    mainwindow.ui \
    profit_for_a_certain_product.ui \
    the_maximum_price_of_the_goods_in_the_invoice.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
