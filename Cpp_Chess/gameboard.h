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
    GameField(void);

    std::vector<ChessPiece*> GetVector (void) const   {return CurrentState ;}
    bool GetTurn (void) const                         {return TurnTracker;}


    void RemovePiece(int X, int Y,bool Color);

    bool AbleToAttack(int X, int Y,bool Color) const;
    bool IsBlocked(int X, int Y,bool Color) const;

    void EndTurn (void) {TurnTracker = !TurnTracker;} // kan ik deze beter beveiligen

    ~GameField(void);
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

    std::vector<ChessPiece*> CurrentState;
    bool TurnTracker = false;
};

#endif // GAMEBOARD_H
