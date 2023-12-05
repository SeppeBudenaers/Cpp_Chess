#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H
#include <iostream>
#include <vector>
#include"gameboard.h"
#include"coordinates.h"
#include <cstdint>

using namespace std;
namespace chess{
class GameManager
{
public:
    GameManager(void) {}


    void Turn(void);

    ~GameManager(void) {}
private:

    GameField gamefield;

    //help function of turn
    void PrintGamePiecePosistion(const vector<ChessPiece*> & list);
    Coordinates<uint8_t,uint8_t> ScanInput(void);
    bool RemoveGamePiece(const int X,const int Y,vector<ChessPiece*> & list);
    bool CheckingForCheck(const vector<ChessPiece*> & list);


    uint8_t CharToUint8_T(const char input);
    bool OutOfBounds(const uint8_t X, const uint8_t Y);
};
#endif // GAMEMANAGER_H
}
