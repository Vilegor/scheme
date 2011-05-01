#-------------------------------------------------
#
# Project created by QtCreator 2011-03-04T19:52:11
#
#-------------------------------------------------

QT       += core gui

TARGET = scheme
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    DialogWindows/changeparameter.cpp \
    Exceptions/OpenFileException.cpp \
    Exceptions/MatrixSizeException.cpp \
    Exceptions/MatrixSingularException.cpp \
    Exceptions/MatrixIndexException.cpp \
    Exceptions/AlgebraicOperationExeption.cpp \
    Elements/resistance.cpp \
    Elements/inductance.cpp \
    Elements/capacity.cpp \
    Elements/sourcecurrent.cpp \
    Elements/sourcedc.cpp \
    Elements/element.cpp \
    Scheme/branch.cpp \
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> 772125f35267f41c19e08e1a3478325ceef8d322
    propertiesdialog.cpp \
    Elements/node.cpp \
    Elements/elementfactory.cpp \
    Scheme/adjucencymatrix.cpp \
<<<<<<< HEAD
    Elements/startendpoint.cpp
=======
=======
    Elements/startendpoint.cpp \
>>>>>>> 772125f35267f41c19e08e1a3478325ceef8d322
    Scheme/node.cpp \
    Scheme/graph.cpp \
    Scheme/branch.cpp \
    Scheme/element.cpp
<<<<<<< HEAD
>>>>>>> 71c1e7a185b5a05120dddbe20a9377322de2ff29
=======
>>>>>>> 772125f35267f41c19e08e1a3478325ceef8d322

HEADERS  += mainwindow.h \
    changeparameter.h \
    DialogWindows/changeparameter.h \
    Countings/Matrix.h \
    Exceptions/OpenFileException.h \
    Exceptions/MatrixSizeException.h \
    Exceptions/MatrixSingularException.h \
    Exceptions/MatrixIndexException.h \
    Exceptions/MatrixException.h \
    Exceptions/FileExceptions.h \
    Exceptions/Exceptions.h \
    Exceptions/Exception.h \
    Exceptions/AlgebraicOperationExeption.h \
    Elements/resistance.h \
    Elements/inductance.h \
    Elements/capacity.h \
    Elements/sourcecurrent.h \
    Elements/sourcedc.h \
    Elements/element.h \
    Scheme/branch.h \
    SCHEME_H.h \
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> 772125f35267f41c19e08e1a3478325ceef8d322
    propertiesdialog.h \
    Elements/node.h \
    Elements/elementfactory.h \
    Scheme/adjucencymatrix.h \
<<<<<<< HEAD
    Elements/startendpoint.h
=======
=======
    Elements/startendpoint.h \
>>>>>>> 772125f35267f41c19e08e1a3478325ceef8d322
    Scheme/node.h \
    Scheme/graph.h \
    Scheme/compositescheme.h \
    Scheme/branch.h \
    Scheme/element.h
<<<<<<< HEAD
>>>>>>> 71c1e7a185b5a05120dddbe20a9377322de2ff29
=======
>>>>>>> 772125f35267f41c19e08e1a3478325ceef8d322

FORMS    += mainwindow.ui \
    propertiesdialog.ui
