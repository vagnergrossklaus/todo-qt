#-------------------------------------------------
#
# Project created by QtCreator 2019-03-10T10:19:18
#
#-------------------------------------------------

QT       -= gui

TARGET = todo
TEMPLATE = lib

DEFINES += TODOLIB_LIBRARY

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    controller/taskcontroller.cpp \
    controller/tasklocalcontroller.cpp \
    controller/taskremotecontroller.cpp \
    model/taskmodel.cpp \
    repository/tasklocalrepository.cpp \
    repository/taskremoterepository.cpp \
    service/taskservice.cpp

HEADERS += \
        todo-lib_global.h \
    controller/taskcontroller.h \
    controller/tasklocalcontroller.h \
    controller/taskremotecontroller.h \
    model/taskmodel.h \
    repository/repository.h \
    repository/tasklocalrepository.h \
    repository/taskremoterepository.h \
    service/taskservice.h \
    todo-lib_global.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

CONFIG(debug, debug|release) {
    DESTDIR = build/debug
}

CONFIG(release, debug|release) {
    DESTDIR = build/release
}

OBJECTS_DIR = $$DESTDIR/.obj
MOC_DIR = $$DESTDIR/.moc
RCC_DIR = $$DESTDIR/.qrc
UI_DIR = $$DESTDIR/.u
