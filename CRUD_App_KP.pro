QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CRUD_APP

CONFIG += c++20

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

PRECOMPILED_HEADER += inc/stable.h

SOURCES += \
    src/DbManager.cpp \
    src/database.cpp \
    src/main.cpp \
    src/view/mainwindow.cpp \
    src/model/user.cpp

HEADERS += \
    inc/DbManager.h \
    inc/Singleton.h \
    inc/database.h \
    inc/stable.h \
    inc/view/mainwindow.h \
    inc/model/user.h

FORMS += \
    forms/mainwindow.ui

INCLUDEPATH +=\
    inc \


# Default rules for deployment.
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

RESOURCES +=
