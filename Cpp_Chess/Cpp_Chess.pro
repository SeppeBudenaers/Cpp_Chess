TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        bishop.cpp \
        chesspiece.cpp \
        gameboard.cpp \
        gamemanager.cpp \
        king.cpp \
        knight.cpp \
        main.cpp \
        pawn.cpp \
        queen.cpp \
        rook.cpp

HEADERS += \
    bishop.h \
    chesspiece.h \
    coordinates.h \
    customerror.h \
    gameboard.h \
    gamemanager.h \
    king.h \
    knight.h \
    pawn.h \
    queen.h \
    rook.h
