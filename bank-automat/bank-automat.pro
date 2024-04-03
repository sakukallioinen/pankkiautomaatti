QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    chooseaccount.cpp \
    main.cpp \
    mainwindow.cpp \
    paasivu.cpp \
    saldo.cpp \
    tilinvalinta.cpp

HEADERS += \
    chooseaccount.h \
    mainwindow.h \
    paasivu.h \
    saldo.h \
    tilinvalinta.h

FORMS += \
    chooseaccount.ui \
    mainwindow.ui \
    paasivu.ui \
    saldo.ui \
    tilinvalinta.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target


win32: LIBS += -L$$PWD/PinDLL/build/debug/ -lPinDLL

INCLUDEPATH += $$PWD/PinDLL
DEPENDPATH += $$PWD/PinDLL
