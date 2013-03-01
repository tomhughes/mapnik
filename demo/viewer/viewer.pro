######################################################################
# Mapnik viewer - Copyright (C) 2007 Artem Pavlenko
######################################################################
TEMPLATE = app
QT += core gui widgets
QMAKE_CXX = $$system(../../utils/mapnik-config/mapnik-config --cxx)
QMAKE_LINK = $$system(../../utils/mapnik-config/mapnik-config --cxx)
QMAKE_CXXFLAGS += $$system(../../utils/mapnik-config/mapnik-config --cxxflags)
QMAKE_CXXFLAGS += -I../../include -I../../deps/mapbox/variant/include -I../../deps/agg/include
QMAKE_CXXFLAGS += $$system(../../utils/mapnik-config/mapnik-config --dep-includes --defines)
QMAKE_LFLAGS += -L../../src -lmapnik
QMAKE_LFLAGS += $$system(../../utils/mapnik-config/mapnik-config --ldflags --dep-libs)
# Input

CONFIG += qt debug_and_release
FORMS += forms/about.ui \
         forms/info.ui \
         forms/layer_info.ui

HEADERS += mainwindow.hpp \
           mapwidget.hpp \
           layerwidget.hpp \
           layerlistmodel.hpp \
           layerdelegate.hpp \
           styles_model.hpp

HEADERS += about_dialog.hpp \
           info_dialog.hpp \
           layer_info_dialog.hpp

SOURCES += main.cpp \
           mainwindow.cpp \
           mapwidget.cpp \
           layerwidget.cpp \
           layerlistmodel.cpp \
           layerdelegate.cpp \
           styles_model.cpp

SOURCES += about_dialog.cpp \
           info_dialog.cpp \
           layer_info_dialog.cpp

RESOURCES += mapnik_viewer.qrc
