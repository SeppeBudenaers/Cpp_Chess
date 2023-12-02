#ifndef CHESSPIECE_H
#define CHESSPIECE_H
class GameField;

class ChessPiece
{
public:
    ChessPiece(int X, int Y, bool Color,GameField*gamefield)    : Xcoordinate(X), Ycoordinate(Y),Color(Color),field(gamefield) {}

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

    void ResetMove(int X, int Y){SetPosX(X);SetPosY(Y);}
    virtual bool Move(int X, int Y)	= 0;
    virtual bool CheckingValidMove(int X, int Y)	= 0;

    virtual ~ChessPiece(void){}
protected:
    void SetPosX(int X) {Xcoordinate = X;}
    void SetPosY(int Y) {Ycoordinate = Y;}

private:
    int Xcoordinate = 0;
    int Ycoordinate = 0;
    const bool Color = false; //white = false
    const GameField* field;

};

#endif // CHESSPIECE_H
