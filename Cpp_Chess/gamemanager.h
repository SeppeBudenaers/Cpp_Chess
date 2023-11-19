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
    GameManager(){}
    bool AbleToAttack(int X, int Y) const;
    bool IsBlocked(int X, int Y) const;

    void InitializingGame();
    void PrintGamePiecePosistion();
    void Turn();
private:
    struct coordinates
    {
        int X;
        int Y;

    };

    enum Xcoordinantes
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
    vector<ChessPiece*> vect;

    coordinates ScanInput();
    int CharToInt(char input);
    bool OutOfBounds(int X,int Y);
    bool TurnTracker = false;
};
#endif // GAMEMANAGER_H
