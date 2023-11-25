#ifndef GAMEBOARD_H
#define GAMEBOARD_H
#include <iostream>
#include <vector>
#include "rook.h"
#include "knight.h"
#include "bishop.h"
#include "king.h"
#include "queen.h"
#include "pawn.h"
using namespace std;
class GameField
{
public:
    GameField(){InitializingGame();}
    std::vector<ChessPiece*> GetVector ()   {return vect;}
    bool GetTurn ()                         {return TurnTracker;}
    void SetTurn (bool Turn)                {TurnTracker = Turn;} // kan ik deze beter beveiligen
    bool AbleToAttack(int X, int Y) const;
    bool IsBlocked(int X, int Y) const;
    void InitializingGame();
private:
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
    std::vector<ChessPiece*> vect;
    bool TurnTracker = false;
};

#endif // GAMEBOARD_H