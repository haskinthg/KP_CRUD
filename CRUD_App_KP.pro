QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CRUD_APP

CONFIG += c++20

PRECOMPILED_HEADER += inc/stable.h

SOURCES += \
    src/model/base.cpp \
    src/view/commonwindow.cpp \
    src/DbManager.cpp \
    src/database.cpp \
    src/main.cpp \
    src/view/addnewdialog.cpp \
    src/view/mainwindow.cpp \
    src/model/user.cpp

HEADERS += \
    inc/model/base.h \
    inc/view/commonwindow.h \
    inc/DbManager.h \
    inc/Singleton.h \
    inc/database.h \
    inc/stable.h \
    inc/view/addnewdialog.h \
    inc/view/mainwindow.h \
    inc/model/user.h

FORMS += \
    forms/commonwindow.ui \
    forms/addnew.ui \
    forms/mainwindow.ui

INCLUDEPATH +=\
    inc \
    inc/model \
    inc/view \

qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

copydata.commands = $(COPY_DIR) $$PWD/database.conf $$OUT_PWD
first.depends = $(first) copydata
export(first.depends)
export(copydata.commands)
QMAKE_EXTRA_TARGETS += first copydata

DISTFILES += \
    database.conf
