QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    mainwindow.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    AppResources.qrc

DISTFILES += \
    Images/copy.svg \
    Images/cutting.png \
    Images/diskette.png \
    Images/folder.png \
    Images/info-circle.svg \
    Images/paste.png \
    Images/saveAs.png \
    Images/undo-circular-arrow.png \
    Resources/copy.svg \
    Resources/cutting.png \
    Resources/diskette.png \
    Resources/folder.png \
    Resources/info-circle.svg \
    Resources/paste.png \
    Resources/saveAs.png \
    Resources/undo-circular-arrow.png \
    copy.svg \
    cutting.png \
    diskette.png \
    folder.png \
    info-circle.svg \
    paste.png \
    saveAs.png \
    undo-circular-arrow.png
