QT       += core gui
QT       += serialport
QT       +=network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    environment.cpp \
    main.cpp \
    mainwindow.cpp \
    otto.cpp \
    paasivu.cpp \
    rfidreader.cpp \
    saldo.cpp \
    tapahtumat.cpp \
    tilinvalinta.cpp \
    muusumma.cpp

HEADERS += \
    AccountManager.h \
    environment.h \
    mainwindow.h \
    otto.h \
    paasivu.h \
    rfidreader.h \
    saldo.h \
    tapahtumat.h \
    tilinvalinta.h \
    muusumma.h


FORMS += \
    mainwindow.ui \
    otto.ui \
    paasivu.ui \
    saldo.ui \
    tapahtumat.ui \
    tilinvalinta.ui \
    muusumma.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target



win32: LIBS += -L$$PWD/PinDLL/build/debug/ -lPinDLL

INCLUDEPATH += $$PWD/PinDLL
DEPENDPATH += $$PWD/PinDLL
