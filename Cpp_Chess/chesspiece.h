#ifndef CHESSPIECE_H
#define CHESSPIECE_H
#include <cstdint>
class GameField;

class ChessPiece
{
public:
    ChessPiece(int X, int Y, bool Color,const GameField*gamefield)    : Xcoordinate(X), Ycoordinate(Y),Color(Color),field(gamefield) {}

    int GetPosX(void) const {return Xcoordinate;}
    int GetPosY(void) const {return Ycoordinate;}
    bool GetColor(void) const {return Color;}

    virtual bool IsBishop(void) const {return false;}
    virtual bool IsKing(void) const {return false;}
    virtual bool IsKnight(void) const {return false;}
    virtual bool IsPawn(void) const {return false;}
    virtual bool IsQueen(void) const {return false;}
    virtual bool IsRook(void) const {return false;}

    const GameField* GetGameField(void) const {return field;}

    void ResetMove(const int X,const int Y){SetPosX(X);SetPosY(Y);}
    virtual bool CheckingValidMove(const int X,const int Y,const bool MovePiece = false)	= 0;

    virtual ~ChessPiece(void){}
protected:
    void SetPosX(const int X) {Xcoordinate = X;}
    void SetPosY(const int Y) {Ycoordinate = Y;}

private:
    uint8_t Xcoordinate = 0;
    uint8_t  Ycoordinate = 0;
    const bool Color = false; //white = false
    const GameField* field;

};
#endif // CHESSPIECE_H

