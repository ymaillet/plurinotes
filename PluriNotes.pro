QT += widgets

QMAKE_CXXFLAGS = -std=c++11
QMAKE_LFLAGS = -std=c++11

HEADERS += \
    notes.h \
    noteediteur.h \
    histonotes.h \
    mainwindow.h \
    relation.h

SOURCES += \
    notes.cpp \
    main.cpp \
    noteediteur.cpp \
    histonotes.cpp \
    mainwindow.cpp \
    relation.cpp

FORMS += \
    mainwindow.ui
