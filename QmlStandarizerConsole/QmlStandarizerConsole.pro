QT -= gui
QT += concurrent

CONFIG += c++17 console
CONFIG -= app_bundle

!isEmpty(target.path): INSTALLS += target

include(QmlStandarizerConsole.pri)
