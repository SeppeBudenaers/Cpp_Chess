#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H
#include <iostream>
#include <vector>
#include "rook.h"
#include "knight.h"
#include "bishop.h"
#include "king.h"
#include "queen.h"
#include "pawn.h"
using namespace std;
class GameManager
{
public:
    GameManager();
    void InitializingGame();
    void PrintGamePiecePosistion();
    vector<ChessPiece*> vect;
private:
    enum Xcordinantes
    {
        a,
        b,
        c,
        d,
        e,
        f,
        g,
        h
    };

};
#endif // GAMEMANAGER_H
