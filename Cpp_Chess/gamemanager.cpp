#include "gamemanager.h"
using namespace chess;
int GameManager::CharToInt(char Input)
{
    switch (Input) {
    case 'a':
    case 'A':
        return  0;
        break;
    case 'b':
    case 'B':
        return  1;
        break;
    case 'c':
    case 'C':
        return  2;
        break;
    case 'd':
    case 'D':
        return  3;
        break;
    case 'e':
    case 'E':
        return  4;
        break;
    case 'f':
    case 'F':
        return  5;
        break;
    case 'g':
    case 'G':
        return  6;
        break;
    case 'h':
    case 'H':
        return  7;
        break;
    }
    return -1;
}

bool GameManager::OutOfBounds(int X, int Y)
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

GameManager::coordinates GameManager::ScanInput()
{
    bool CordinatesAquired = false;
    char charXinput= 0;
    coordinates Input;
    while (!CordinatesAquired) { // bug dat cin geen tweede keer word gevraagt
        cin>>charXinput>>Input.Y;
        Input.X = CharToInt(charXinput);
        if(!OutOfBounds(Input.X,Input.Y)){CordinatesAquired = true;}
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

bool GameManager::RemoveGamePiece(int X,int Y,vector<ChessPiece*>& list)
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
    coordinates King;
    for (ChessPiece* I :list)
    {
        if((I->GetColor() == gamefield.GetTurn())&&I->IsKing())
        {
            King.X = I->GetPosX();
            King.Y = I->GetPosY();
            cout<<"debug King:"<<I->GetPosX()<<I->GetPosY()<<endl;
            break;
        }
    }
    for (ChessPiece* I :list)
    {
        if((I->GetColor() !=gamefield.GetTurn()) && I->CheckingValidMove(King.X,King.Y))
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
        coordinates EndPosition;
        coordinates BeginPosition;

        PrintGamePiecePosistion(list);
        //begin postion
        if(gamefield.GetTurn()){cout<<"Blacks turn"<<endl<<"Please enter pawn that you want to move :";}
        else{cout<<"Whites turn"<<endl<<"Please enter pawn that you want to move :";}
        BeginPosition = ScanInput();

        for (ChessPiece* I :list)
        {
        if((I->GetPosX() == BeginPosition.X )&&(I->GetPosY() == BeginPosition.Y)&&(I->GetColor() == gamefield.GetTurn())){
                FoundPiece = true;

                //end position

                cout<<"To ?:";
                EndPosition = ScanInput();
                if(!((BeginPosition.X == EndPosition.X)&&(BeginPosition.Y == EndPosition.Y)))
                {
                    ValidMove = I->CheckingValidMove(EndPosition.X,EndPosition.Y,true);
                    // is het intersant om bv if(Move()){valid = true}else{break}? om niet nodeloos functies te callen als het toch al invalid is
                    RemovingPiece = RemoveGamePiece(EndPosition.X,EndPosition.Y,list);
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
                gamefield.RemovePiece(EndPosition.X,EndPosition.Y,!gamefield.GetTurn());
            }
        }
        else
        {
            for (ChessPiece* I :list){
                if((I->GetPosX() == EndPosition.X )&&(I->GetPosY() == EndPosition.Y)&&(I->GetColor() == gamefield.GetTurn()))
                {
                    I->ResetMove(BeginPosition.X,BeginPosition.Y);
                }
            }

        }
    }
    gamefield.EndTurn();
}




