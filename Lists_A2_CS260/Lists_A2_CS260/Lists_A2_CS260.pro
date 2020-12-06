TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

CONFIG -= debug_and_release

SOURCES += main.cpp \
    Address.cpp \
    AddressLinkedList.cpp

QMAKE_CXXFLAGS += -pedantic
QMAKE_CXXFLAGS += -pedantic-errors

QMAKE_CXXFLAGS += -Wmissing-include-dirs
QMAKE_CXXFLAGS += -Wfloat-equal
QMAKE_CXXFLAGS += -Wredundant-decls
QMAKE_CXXFLAGS += -Winit-self
QMAKE_CXXFLAGS += -Wshadow
QMAKE_CXXFLAGS += -Wconversion

DISTFILES += \
    25000AddressesA.txt \
    25000AddressesB.txt

HEADERS += \
    Address.h \
    AddressArrayList.h \
    AddressLinkedList.h \
    ArrayList.h

