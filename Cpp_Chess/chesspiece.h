#ifndef CHESSPIECE_H
#define CHESSPIECE_H
class GameManager;

class ChessPiece
{
    friend class GameManager;
public:
    ChessPiece(int X, int Y, bool Color,GameManager*GameManager)    : Xcoordinate(X), Ycoordinate(Y),Color(Color),Manager(GameManager) {}
    int GetPosX() {return Xcoordinate;}
    int GetPosY() {return Ycoordinate;}
    bool GetColor() {return Color;}
    const GameManager* GetGameManager() const {return Manager;}
    virtual bool Move(int X, int Y)	= 0;
protected:
    void SetPosX(int X) {Xcoordinate = X;}
    void SetPosY(int Y) {Ycoordinate = Y;}

private:
    int Xcoordinate = 0;
    int Ycoordinate = 0;
    bool Color = false; //white = false
    const GameManager* Manager;

};

#endif // CHESSPIECE_H
