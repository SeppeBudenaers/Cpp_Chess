#include "gamemanager.h"

bool GameManager::AbleToAttack(int X, int Y) const
{
    for (ChessPiece* I :vect){
        if((I->GetPosX() == X )&&(I->GetPosY() == Y)&&(I->GetColor() != TurnTracker)){return true;}
    }
    return false;
}

bool GameManager::IsBlocked(int X, int Y) const
{
    for (ChessPiece* I :vect){
        if((I->GetPosX() == X )&&(I->GetPosY() == Y)&&(I->GetColor() == TurnTracker)){return true;}
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

bool GameManager::OutOfBounds(int X, int Y)
{
    if((-1<X)&&(X<8)&&(-1<Y)&&(Y<8))
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
    while (!CordinatesAquired) {
        cin>>charXinput>>Input.Y;
        Input.X = CharToInt(charXinput);
        if(!OutOfBounds(Input.X,Input.Y)){CordinatesAquired = true;}
        else{cout<<"Cordinates are out of bounds."<<endl;}
    }
    return  Input;
}

void GameManager::InitializingGame()
{
    for (int I = 0; I < 2; ++I) {
        int Y = 1;
        int YPawn = 2;
        if(I == 1 ){Y = 8 ; YPawn = 7;}
        vect.push_back(new Rook(a,Y,I,this));
        vect.push_back(new Rook(h,Y,I,this));
        vect.push_back(new Knight(b,Y,I,this));
        vect.push_back(new Knight(g,Y,I,this));
        vect.push_back(new Bishop(c,Y,I,this));
        vect.push_back(new Bishop(f,Y,I,this));
        vect.push_back(new King(e,Y,I,this));
        vect.push_back(new Queen(d,Y,I,this));
        for (int var = 0; var < 8; ++var) {
            vect.push_back(new Pawn(var,YPawn,I,this));
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

void GameManager::Turn()
{
    //flags
    bool TurnCompleted = false;
    bool FoundPiece = false;
    bool ValidMove = false;
    while(!TurnCompleted)
    {
        if(TurnTracker){cout<<"Blacks turn"<<endl<<"Please enter pawn that you want to move :";}
        else{cout<<"Whites turn"<<endl<<"Please enter pawn that you want to move :";}

        coordinates BeginPosition;
        BeginPosition = ScanInput();
        for (ChessPiece* I :vect)
        {
        if((I->GetPosX() == BeginPosition.X )&&(I->GetPosY() == BeginPosition.Y)&&(I->GetColor() == TurnTracker)){
                FoundPiece = true;
                coordinates EndPosition;
                cout<<"To ?:";
                EndPosition = ScanInput();
                ValidMove = I->Move(EndPosition.X,EndPosition.Y);
                //removing if attack happend.
                //looking if this keeps you in check
                //reset gamefield if move is invalid
                break;
            }
        }

        //returning errors
        if(!FoundPiece){cout<<"Selected invalid piece"<<endl;}

        if(!ValidMove){cout<<"invalid Move"<<endl;}

        if(FoundPiece && ValidMove)
        {
            cout<<"Valid"<<endl;
            TurnCompleted = true;
        }
    }
    cout<<"out of while"<<endl;
    TurnTracker = !TurnTracker;
}




