QT       += sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
QT       += core gui sql network multimedia multimediawidgets charts printsupport widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
QMAKE_CXXFLAGS+= -std=gnu++14

SOURCES += \
    QrCode.cpp \
    abonnement.cpp \
    connection.cpp \
    dialog_stats.cpp \
    evenement.cpp \
    fidelite.cpp \
    gestion_client.cpp \
    gestion_evenement.cpp \
    gestion_materiel.cpp \
    gestion_personnel.cpp \
    gestion_reservation.cpp \
    login.cpp \
    main.cpp \
    mainwindow_client.cpp \
    materiel.cpp \
    menu.cpp \
    personnel.cpp \
    piechart.cpp \
    qcustomplot.cpp \
    reservation.cpp

HEADERS += \
    QrCode.hpp \
    abonnement.h \
    connection.h \
    dialog_stats.h \
    evenement.h \
    fidelite.h \
    gestion_client.h \
    gestion_evenement.h \
    gestion_materiel.h \
    gestion_personnel.h \
    gestion_reservation.h \
    login.h \
    mainwindow_client.h \
    materiel.h \
    menu.h \
    personnel.h \
    qcustomplot.h \
    reservation.h

FORMS += \
    dialog_stats.ui \
    evenement.ui \
    login.ui \
    mainwindow_client.ui \
    materiel.ui \
    menu.ui \
    personnel.ui \
    reservation.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
