QT -= gui
QT += concurrent

CONFIG += c++17 console
CONFIG -= app_bundle

SOURCES += \
        src/CodeBeautifier.cpp \
        src/ProjectIterator.cpp \
        src/QmlStandarizerApplication.cpp \
        src/main.cpp

!isEmpty(target.path): INSTALLS += target

HEADERS += \
    src/CodeBeautifier.h \
    src/ProjectIterator.h \
    src/QmlStandarizerApplication.h \
    src/globals.h
