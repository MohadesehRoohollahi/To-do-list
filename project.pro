QT       += core gui

QT += printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ad2window.cpp \
    adwindow.cpp \
    date.cpp \
    dutieswindow.cpp \
    functions.cpp \
    list.cpp \
    listswindow.cpp \
    main.cpp \
    mainwindow.cpp \
    signupwindow.cpp \
    starwindow.cpp \
    task.cpp \
    taskswindow.cpp \
    twindow.cpp \
    user.cpp

HEADERS += \
    ad2window.h \
    adwindow.h \
    date.h \
    dutieswindow.h \
    functions.h \
    linklist.h \
    list.h \
    listswindow.h \
    mainwindow.h \
    signupwindow.h \
    starwindow.h \
    task.h \
    taskswindow.h \
    twindow.h \
    user.h

FORMS += \
    ad2window.ui \
    adwindow.ui \
    dutieswindow.ui \
    listswindow.ui \
    mainwindow.ui \
    signupwindow.ui \
    starwindow.ui \
    taskswindow.ui \
    twindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    images.qrc
