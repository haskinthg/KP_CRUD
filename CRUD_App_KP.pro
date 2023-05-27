QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CRUD_APP

CONFIG += c++20

PRECOMPILED_HEADER += inc/stable.h

SOURCES += \
    src/view/querydialog.cpp \
    src/model/base.cpp \
    src/model/computer.cpp \
    src/model/license.cpp \
    src/model/licensor.cpp \
    src/model/program.cpp \
    src/view/commonwindow.cpp \
    src/DbManager.cpp \
    src/database.cpp \
    src/main.cpp \
    src/view/addnewdialog.cpp \
    src/view/mainwindow.cpp \
    src/model/user.cpp

HEADERS += \
    inc/model/base.h \
    inc/model/computer.h \
    inc/model/license.h \
    inc/model/licensor.h \
    inc/model/program.h \
    inc/view/commonwindow.h \
    inc/DbManager.h \
    inc/Singleton.h \
    inc/database.h \
    inc/stable.h \
    inc/view/addnewdialog.h \
    inc/view/mainwindow.h \
    inc/model/user.h \
    inc/view/querydialog.h

FORMS += \
    forms/commonwindow.ui \
    forms/addnew.ui \
    forms/mainwindow.ui \
    forms/querydialog.ui

INCLUDEPATH +=\
    inc \
    inc/model \
    inc/view \

qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

#copydata.commands = $(COPY_DIR) $$PWD/database.conf $$OUT_PWD
#first.depends = $(first) copydata
#export(first.depends)
#export(copydata.commands)
#QMAKE_EXTRA_TARGETS += first copydata

DISTFILES += \
    database.ini
