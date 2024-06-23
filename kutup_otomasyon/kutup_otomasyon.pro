QT       += core gui sql

# 21100011001 - Derya Nailiye Kımırtı

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    kitapal.cpp \
    kitaplar.cpp \
    kitapver.cpp \
    main.cpp \
    mainwindow.cpp \
    tum_2101.cpp \
    uyeler.cpp

HEADERS += \
    kitapal.h \
    kitaplar.h \
    kitapver.h \
    mainwindow.h \
    uyeler.h

FORMS += \
    kitapal.ui \
    kitaplar.ui \
    kitapver.ui \
    mainwindow.ui \
    uyeler.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    images.qrc
