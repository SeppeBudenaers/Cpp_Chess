#include "chesspiece.h"
#include "customerror.h"
#include "gameboard.h"

void ChessPiece::SamePiece(const Coordinates<uint8_t,uint8_t>& Input,const vector<ChessPiece*> & list)
{
    for (ChessPiece* I :list)
    {
        if((I->GetPosX() == Input.GetX() )&&(I->GetPosY() == Input.GetY())&&(I->GetColor() == GetGameField()->GetTurn()))
        {
            if(I == this){throw samepiece();}
        }
    };
}
