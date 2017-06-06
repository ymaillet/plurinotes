QT += widgets

QMAKE_CXXFLAGS = -std=c++11
QMAKE_LFLAGS = -std=c++11

HEADERS += \
    notes.h \
    noteediteur.h \
    histonotes.h \
    mainwindow.h \
    relation.h \
    fenetrecreerarticle.h \
    fenetrecreernotes.h \
    fenprincipale.h


SOURCES += \
    notes.cpp \
    main.cpp \
    noteediteur.cpp \
    histonotes.cpp \
    mainwindow.cpp \
    relation.cpp \
    fenetrecreerarticle.cpp \
    fenetrecreernotes.cpp \
    fenprincipale.cpp

FORMS += \
    mainwindow.ui
