QT -= gui
QT += concurrent core

CONFIG += c++17 console
CONFIG -= app_bundle

!isEmpty(target.path): INSTALLS += target

SOURCES += src/main.cpp

include(QmlStandarizerConsole.pri)
