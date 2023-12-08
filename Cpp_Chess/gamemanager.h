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
    void ScanInput(Coordinates<uint8_t,uint8_t>& Input);
    bool RemoveGamePiece(const Coordinates<uint8_t,uint8_t>& Input,vector<ChessPiece*> & list);
    bool CheckingForCheck(const vector<ChessPiece*> & list);
    void LoggingMove(Coordinates<uint8_t,uint8_t>& Begin, Coordinates<uint8_t,uint8_t>& End);

    //Special moves
    bool Castle(Coordinates<uint8_t,uint8_t>& Begin, Coordinates<uint8_t,uint8_t>& End);
    void PromotingPawn(ChessPiece*& Piece);


    //help function of turn
    uint8_t CharToUint8_T(const char input);
    bool OutOfBounds(const Coordinates<uint8_t,uint8_t>& Input);
};
#endif // GAMEMANAGER_H
}
