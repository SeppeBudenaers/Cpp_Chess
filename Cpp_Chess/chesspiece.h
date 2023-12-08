#ifndef CHESSPIECE_H
#define CHESSPIECE_H
#include "coordinates.h"
#include <vector>
#include <cstdint>
class GameField;
using namespace std;
class ChessPiece
{
public:
    ChessPiece(int X, int Y, bool Color,const GameField*gamefield)    : Color(Color),field(gamefield) {coordinates.setX(X);coordinates.setY(Y);}

    uint8_t GetPosX(void) const {return coordinates.GetX();}
    uint8_t GetPosY(void) const {return coordinates.GetY();}
    Coordinates<uint8_t,uint8_t> GetPos(void) const{return coordinates;}
    bool GetColor(void) const {return Color;}

    bool GetFirstMove(void) const {return FirstMove;}
    void SetFirstMove(void) {FirstMove = false;}

    virtual bool IsBishop(void) const {return false;}
    virtual bool IsKing(void) const {return false;}
    virtual bool IsKnight(void) const {return false;}
    virtual bool IsPawn(void) const {return false;}
    virtual bool IsQueen(void) const {return false;}
    virtual bool IsRook(void) const {return false;}



    const GameField* GetGameField(void) const {return field;}

    bool SamePiece(const Coordinates<uint8_t,uint8_t>& Input,const vector<ChessPiece*> & list);
    void ResetMove(const Coordinates<uint8_t,uint8_t>& Input){coordinates.setX(Input.GetX());coordinates.setY(Input.GetY());}
    virtual bool CheckingValidMove(const Coordinates<uint8_t,uint8_t>& Input,const bool MovePiece = false)	= 0;

    virtual ~ChessPiece(void){}
protected:
    void SetPos(const Coordinates<uint8_t,uint8_t>& Input) {coordinates.setX(Input.GetX());coordinates.setY(Input.GetY());}

private:
    Coordinates<uint8_t,uint8_t> coordinates;
    const bool Color = false; //white = false
    const GameField* field;
    bool FirstMove = true;

};
#endif // CHESSPIECE_H
