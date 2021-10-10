QT -= gui
QT += concurrent

CONFIG += c++17 console
CONFIG -= app_bundle

SOURCES += \
        CodeBeautifier.cpp \
        ProjectIterator.cpp \
        QmlStandarizerApplication.cpp \
        main.cpp

!isEmpty(target.path): INSTALLS += target

HEADERS += \
    CodeBeautifier.h \
    ProjectIterator.h \
    QmlStandarizerApplication.h \
    globals.h
