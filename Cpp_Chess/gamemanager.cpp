#include "gamemanager.h"

bool GameManager::AbleToAttack(int X, int Y)
{
    for (ChessPiece* I :vect){
        if((I->GetPosX() == X )&&(I->GetPosY() == Y)&&(I->GetColor() != TurnTracker)){return true;}
    }
    return false;
}

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

void GameManager::InitializingGame()
{
    for (int I = 0; I < 2; ++I) {
        int Y = 1;
        int YPawn = 2;
        if(I == 1 ){Y = 8 ; YPawn = 7;}
        vect.push_back(new Rook(a,Y,I));
        vect.push_back(new Rook(h,Y,I));
        vect.push_back(new Knight(b,Y,I));
        vect.push_back(new Knight(g,Y,I));
        vect.push_back(new Bishop(c,Y,I));
        vect.push_back(new Bishop(f,Y,I));
        vect.push_back(new King(e,Y,I));
        vect.push_back(new Queen(d,Y,I));
        for (int var = 0; var < 8; ++var) {
            vect.push_back(new Pawn(var,YPawn,I));
        }
    }
}

void GameManager::PrintGamePiecePosistion()
{
    for (ChessPiece* I : vect) {
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

void GameManager::PlayerInput()
{
    if(TurnTracker){cout<<"Blacks turn"<<endl<<"Please enter pawn that you want to move :";}
    else{cout<<"Whites turn"<<endl<<"Please enter pawn that you want to move :";}
    char charXBeginPosition = 0;
    int  XBeginPosition = 0;
    int  YBeginPosition = 0;
    cin>>charXBeginPosition>>YBeginPosition;
    XBeginPosition = CharToInt(charXBeginPosition);
    bool FoundPiece = false;
    for (ChessPiece* I :vect)
    {
        if((I->GetPosX() == XBeginPosition )&&(I->GetPosY() == YBeginPosition)&&(I->GetColor() == TurnTracker)){
            char charXEndPosition = 0;
            int  XEndPosition = 0;
            int  YEndPosition = 0;
            cout<<"To ?:";
            cin>>charXEndPosition>>YEndPosition;
            XEndPosition = CharToInt(charXEndPosition);
            I->Move(XEndPosition,YEndPosition);
            FoundPiece = true;
            break;
        }
    }
    if(!FoundPiece){cout<<"Selected invalid piece"<<endl;}
    TurnTracker = !TurnTracker;
}


