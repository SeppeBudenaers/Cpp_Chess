TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        bishop.cpp \
        chesspiece.cpp \
        king.cpp \
        knight.cpp \
        main.cpp \
        pawn.cpp \
        queen.cpp \
        rook.cpp

HEADERS += \
    bishop.h \
    chesspiece.h \
    king.h \
    knight.h \
    pawn.h \
    queen.h \
    rook.h
