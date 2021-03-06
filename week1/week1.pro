QT += core
QT -= gui
QT += core sql

TARGET = week1
CONFIG += console
CONFIG -= app_bundle
CONFIG += C++11

TEMPLATE = app

SOURCES += main.cpp \
    models/scientist.cpp \
    repositories/scientistrepository.cpp \
    services/scientistservice.cpp \
    ui/consoleui.cpp \
    utilities/utils.cpp \
    utilities/scientistcomparator.cpp \
    repositories/sql.cpp \
    services/computerservice.cpp \
    models/computer.cpp \
    services/service.cpp

HEADERS += \
    models/scientist.h \
    repositories/scientistrepository.h \
    utilities/utils.h \
    utilities/constants.h \
    services/scientistservice.h \
    ui/consoleui.h \
    utilities/scientistcomparator.h \
    repositories/sql.h \
    services/computerservice.h \
    models/computer.h \
    services/service.h

