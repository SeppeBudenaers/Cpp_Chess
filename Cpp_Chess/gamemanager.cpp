#include "gamemanager.h"
#include "coordinates.h"
#include <cstdint>

using namespace chess;
uint8_t GameManager::CharToUint8_T(const char Input)
{
    uint8_t thefuck;
    switch (Input) {
    case 'a':
    case 'A':
        cout<<"debug setting temp to 70"<<endl;
        thefuck =  0;
        cout<<"debug temp"<<+thefuck<<endl;
        break;
    case 'b':
    case 'B':
        thefuck =  1;
        break;
    case 'c':
    case 'C':
        thefuck =  2;
        break;
    case 'd':
    case 'D':
        thefuck =  3;
        break;
    case 'e':
    case 'E':
        thefuck = 4;
        break;
    case 'f':
    case 'F':
        thefuck =  5;
        break;
    case 'g':
    case 'G':
        thefuck =  6;
        break;
    case 'h':
    case 'H':
        thefuck =  7;
        break;
    }
    cout<<"debug temp"<<thefuck<<endl;
    return thefuck;
}

bool GameManager::OutOfBounds(const uint8_t X,const uint8_t Y)
{
    if((-1<X)&&(X<8)&&(0<Y)&&(Y<9))
    {
        return false;
    }
    else
    {
        return true;
    }
}

Coordinates<uint8_t,uint8_t> GameManager::ScanInput()
{
    bool CordinatesAquired = false;
    char charXinput= 0;
    uint8_t Xinput = 0;
    uint8_t Yinput = 0;
    Coordinates<uint8_t,uint8_t> Input;

    while (!CordinatesAquired) { // bug dat cin geen tweede keer word gevraagt
        cin>>charXinput>>Yinput;
        Xinput = CharToUint8_T(charXinput);
        cout<<"Debug"<<+Xinput<<endl;
        Input.setX(Xinput);
        Input.setY(Yinput);
        cout<<"Debug"<<Input.GetX()<<Input.GetY()<<endl;
        if(!OutOfBounds(Input.GetX(),Input.GetY())){CordinatesAquired = true;}
        else{cout<<"Cordinates are out of bounds."<<endl;}
    }
    return  Input;
}

void GameManager::PrintGamePiecePosistion(const vector<ChessPiece*>& list)
{
    for (ChessPiece* I : list) {
        cout<<"Co ords of game piece is : ";
        switch (I->GetPosX()) {
        case 0:
            cout<<"a"<<I->GetPosY();
            break;
        case 1:
            cout<<"b"<<I->GetPosY();
            break;
        case 2:
            cout<<"c"<<I->GetPosY();
            break;
        case 3:
            cout<<"d"<<I->GetPosY();
            break;
        case 4:
            cout<<"e"<<I->GetPosY();
            break;
        case 5:
            cout<<"f"<<I->GetPosY();
            break;
        case 6:
            cout<<"g"<<I->GetPosY();
            break;
        case 7:
            cout<<"h"<<I->GetPosY();
            break;
        }
        if(I->GetColor() == 0){cout<<" And the color is : White"<<endl;}
        else {cout<<" And the color is : Black"<<endl;}
    }
}

bool GameManager::RemoveGamePiece(const int X,const int Y,vector<ChessPiece*>& list)
{
    bool RemovingPiece = false;
    int pos = 0;
    for (ChessPiece* I :list)
    {
        if((I->GetPosX() == X )&&(I->GetPosY() == Y)&&(I->GetColor() != gamefield.GetTurn()))
        {
            RemovingPiece = true;
            break;
        }
        pos++;
    }
    if(RemovingPiece){list.erase(list.begin()+pos);}
    return RemovingPiece;
}

bool GameManager::CheckingForCheck(const vector<ChessPiece*>& list)
{
    bool Check = false;
    Coordinates<uint8_t,uint8_t> King;
    for (ChessPiece* I :list)
    {
        if((I->GetColor() == gamefield.GetTurn())&&I->IsKing())
        {
            King.setX(I->GetPosX());
            King.setY(I->GetPosY());
            break;
        }
    }
    for (ChessPiece* I :list)
    {
        if((I->GetColor() !=gamefield.GetTurn()) && I->CheckingValidMove(King.GetX(),King.GetY()))
        {
            cout<<"debug check:"<<I->GetPosX()<<I->GetPosY()<<endl;

            Check = true;
        }
    }
    return Check;
}

void GameManager::Turn()
{
    bool TurnCompleted = false;

    while(!TurnCompleted)
    {

        //flags
        bool SamePiece = false;
        bool FoundPiece = false;
        bool ValidMove = false;
        bool RemovingPiece = false;
        bool Check = false;

        vector<ChessPiece*> list = gamefield.GetVector();
        Coordinates<uint8_t,uint8_t> EndPosition;
        Coordinates<uint8_t,uint8_t> BeginPosition;

        PrintGamePiecePosistion(list);
        //begin postion
        if(gamefield.GetTurn()){cout<<"Blacks turn"<<endl<<"Please enter pawn that you want to move :";}
        else{cout<<"Whites turn"<<endl<<"Please enter pawn that you want to move :";}
        BeginPosition = ScanInput();

        for (ChessPiece* I :list)
        {
        if((I->GetPosX() == BeginPosition.GetX() )&&(I->GetPosY() == BeginPosition.GetY())&&(I->GetColor() == gamefield.GetTurn())){
                FoundPiece = true;

                //end position

                cout<<"To ?:";
                EndPosition = ScanInput();
                if(!((BeginPosition.GetX() == EndPosition.GetX())&&(BeginPosition.GetY() == EndPosition.GetY())))
                {
                    ValidMove = I->CheckingValidMove(EndPosition.GetX(),EndPosition.GetY(),true);
                    // is het intersant om bv if(Move()){valid = true}else{break}? om niet nodeloos functies te callen als het toch al invalid is
                    RemovingPiece = RemoveGamePiece(EndPosition.GetX(),EndPosition.GetY(),list);
                    //same comment
                    Check = CheckingForCheck(list);
                    //same comment
                }
                else{SamePiece = true;}
            }
        }

        //returning errors
        if(!FoundPiece){cout<<"Selected invalid piece"<<endl;}

        if(!ValidMove){cout<<"invalid Move"<<endl;}

        if(SamePiece){cout<<"Selected Same coordiantes"<<endl;}

        if(Check){cout<<"Standing check"<<endl;}

        if(FoundPiece && ValidMove && !SamePiece && !Check)
        {
            cout<<"Valid"<<endl;
            TurnCompleted = true;
            if(RemovingPiece)
            {
                gamefield.RemovePiece(EndPosition.GetX(),EndPosition.GetY(),!gamefield.GetTurn());
            }
        }
        else
        {
            for (ChessPiece* I :list){
                if((I->GetPosX() == EndPosition.GetX())&&(I->GetPosY() == EndPosition.GetY())&&(I->GetColor() == gamefield.GetTurn()))
                {
                    I->ResetMove(BeginPosition.GetX(),BeginPosition.GetY());
                }
            }

        }
    }
    gamefield.EndTurn();
}




