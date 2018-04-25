QT -= gui
QT += network

CONFIG += c++11 console
CONFIG -= app_bundle


SOURCES += main.cpp \
    mserver.cpp \
    mthread.cpp

HEADERS += \
    mserver.h \
    mthread.h
