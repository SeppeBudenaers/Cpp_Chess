#include "gamemanager.h"

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
    while (!CordinatesAquired) {
        cin>>charXinput>>Input.Y;
        Input.X = CharToInt(charXinput);
        if(!OutOfBounds(Input.X,Input.Y)){CordinatesAquired = true;}
        else{cout<<"Cordinates are out of bounds."<<endl;}
    }
    return  Input;
}

void GameManager::PrintGamePiecePosistion()
{
    for (ChessPiece* I : gamefield.GetVector()) {
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

        //begin postion
        if(gamefield.GetTurn()){cout<<"Blacks turn"<<endl<<"Please enter pawn that you want to move :";}
        else{cout<<"Whites turn"<<endl<<"Please enter pawn that you want to move :";}
        coordinates BeginPosition;
        BeginPosition = ScanInput();

        for (ChessPiece* I :list)
        {
        if((I->GetPosX() == BeginPosition.X )&&(I->GetPosY() == BeginPosition.Y)&&(I->GetColor() == gamefield.GetTurn())){
                FoundPiece = true;

                //end position
                coordinates EndPosition;
                cout<<"To ?:";
                EndPosition = ScanInput();
                if(!((BeginPosition.X == EndPosition.X)&&(BeginPosition.Y == EndPosition.Y)))
                {
                    ValidMove = I->Move(EndPosition.X,EndPosition.Y);

                    //if attack happend removing chess piece out of temp list
                    int pos = 0;
                    for (ChessPiece* I :list)
                    {
                        if((I->GetPosX() == EndPosition.X )&&(I->GetPosY() == EndPosition.Y)&&(I->GetColor() != gamefield.GetTurn()))
                        {
                            RemovingPiece = true;
                            break;
                        }
                        pos++;
                    }
                    if(RemovingPiece){list.erase(list.begin()+pos);}

                    //looking if you are standing check
                    int KingPosX = 0;
                    int KingPosY = 0;
                    for (ChessPiece* I :list)
                    {
                        if((I->GetColor() == gamefield.GetTurn())&&I->IsKing())
                        {
                            KingPosX = I->GetPosX();
                            KingPosY = I->GetPosY();
                            cout<<"debug King:"<<I->GetPosX()<<I->GetPosY()<<endl;
                            break;
                        }
                    }
                    for (ChessPiece* I :list)
                    {
                        if((I->GetColor() !=gamefield.GetTurn()) && I->CheckingValidMove(KingPosX,KingPosY))
                        {
                            cout<<"debug check:"<<I->GetPosX()<<I->GetPosY()<<endl;
                            Check = true;
                        }
                    }
                    break;
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
        }
    }
    cout<<"out of while"<<endl;
    // actualy remove the attacked item if there is one
    gamefield.SetTurn(!gamefield.GetTurn());
}




