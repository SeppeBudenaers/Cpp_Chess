#include "chesspiece.h"
#include "gameboard.h"
//ChessPiece::ChessPiece()
//{

//}

bool ChessPiece::SamePiece(const Coordinates<uint8_t,uint8_t>& Input,const vector<ChessPiece*> & list)
{
    for (ChessPiece* I :list)
    {
        if((I->GetPosX() == Input.GetX() )&&(I->GetPosY() == Input.GetY())&&(I->GetColor() == GetGameField()->GetTurn()))
        {
            if(I == this){return true;}
            else{return false;}
        }
    }
    return false;
}
