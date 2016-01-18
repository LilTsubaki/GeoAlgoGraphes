QT += core
QT += gui

TARGET = GeoAlgoGraphes

TEMPLATE = app
CONFIG += c++11
QMAKE_CXXFLAGS += -fopenmp
LIBS += -fopenmp

SOURCES += main.cpp \
    terrain.cpp \
    ray.cpp \
    terrainimage.cpp \
    mathutils.cpp \
    vector2d.cpp \
    vector3d.cpp \
    matrix3.cpp


HEADERS += terrainimage.h \
    terrain.h \
    ray.h \
    mathutils.h \
    vector2d.h \
    vector3d.h \
    matrix3.h

