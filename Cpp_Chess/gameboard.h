#ifndef GAMEBOARD_H
#define GAMEBOARD_H
#include <iostream>
#include <vector>
#include "coordinates.h"
#include"chesspiece.h"

using namespace std;
class GameField
{
public:
    GameField(void);

    std::vector<ChessPiece*> GetVector (void) const   {return CurrentState ;}
    bool GetTurn (void) const                         {return TurnTracker;}


    void RemovePiece(const Coordinates<uint8_t,uint8_t>& Input, const bool Color);

    bool AbleToAttack(const Coordinates<uint8_t,uint8_t>& Input,const bool Color) const;
    bool IsBlocked(const Coordinates<uint8_t,uint8_t>& Input, const bool Color) const;

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
