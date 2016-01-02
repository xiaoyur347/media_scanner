QT += core widgets network
SOURCES += ..\lib\pugixml.cpp
HEADERS += ..\lib\pugixml.hpp ..\lib\pugiconfig.hpp

SOURCES += qt_main.cpp \
           main_widget.cpp \
           report.cpp

HEADERS += main_widget.h \
           report.h
