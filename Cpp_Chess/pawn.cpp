#include "pawn.h"
#include "gamemanager.h"

bool Pawn::Move(int X, int Y)
{
//    GetGameManager()->AbleToAttack();
//    if((-1<X)&&(X<8)&&(-1<Y)&&(Y<8)) //checking if the move is out of bounds
//    {
//        if(GetColor())  //black
//        {
//            switch (GetPosY()-Y) {
//            case 2:
//                if((GetPosX() == X)&&FirstMove&&/*not something obstucting*/){
//                    FirstMove = false;
//                    SetPosX(X);
//                    SetPosY(Y);
//                    return true;}
//                break;
//            case 1:
//                if(((GetPosX() == X)&&/*not something obstucting*/)||(((GetPosX()-X == -1)||(GetPosX()-X == 1))&&/*something to attac*/)){
//                    FirstMove = false;
//                    SetPosX(X);
//                    SetPosY(Y);
//                    return true;}
//                break;
//            default:
//                break;
//            }
//        }
//        else            //white
//        {
//            switch (Y-GetPosY()) {
//            case 2:
//                if((GetPosX() == X)&&FirstMove&&/*not something obstucting*/){
//                    FirstMove = false;
//                    SetPosX(X);
//                    SetPosY(Y);
//                    return true;}
//                break;
//            case 1:
//                if(((GetPosX() == X)&&/*not something obstucting*/)||(((GetPosX()-X == -1)||(GetPosX()-X == 1))&&/*something to attac*/)){
//                    FirstMove = false;
//                    SetPosX(X);
//                    SetPosY(Y);
//                    return true;}
//                break;
//            default:
//                break;
//            }
//        }
//    }
    return false;
}
