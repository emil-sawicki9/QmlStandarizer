QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

# Uncomment to enable single main to run all tests
#DEFINES += SINGLE_MAIN

SOURCES += tst_linecompleter.cpp \
    main.cpp

include(../QmlStandarizerConsole/QmlStandarizerConsole.pri)

HEADERS += \
    tst_linecompleter.h
