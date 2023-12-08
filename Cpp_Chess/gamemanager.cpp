#include "gamemanager.h"
#include "coordinates.h"
#include <cstdint>
#include <fstream>

using namespace chess;
uint8_t GameManager::CharToUint8_T(const char Input)
{
    if (isdigit(Input))
    {
        return static_cast<uint8_t>(Input - '0');
    }
    else if (isalpha(Input))
    {
        return static_cast<uint8_t>(tolower(Input) - 'a');
    }
    return 0;
}

bool GameManager::OutOfBounds(const Coordinates<uint8_t, uint8_t> &Input)
{
    if((Input.GetX()<8)&&(0<Input.GetY())&&(Input.GetY()<9))
    {
        return false;
    }
    else
    {
        return true;
    }
}

void GameManager::ScanInput(Coordinates<uint8_t,uint8_t>& Input)
{
    bool CordinatesAquired = false;
    uint8_t Xinput = 0;
    uint8_t Yinput = 0;

    while (!CordinatesAquired) { // bug dat cin geen tweede keer word gevraagt
        cin>>Xinput>>Yinput;
        Xinput = CharToUint8_T(Xinput);
        Yinput = CharToUint8_T(Yinput);
        Input.setX(Xinput);
        Input.setY(Yinput);
        if(!OutOfBounds(Input)){CordinatesAquired = true;}
        else{cout<<"Cordinates are out of bounds."<<endl;}
    }

}

void GameManager::PrintGamePiecePosistion(const vector<ChessPiece*>& list)
{
    for (ChessPiece* I : list) {
        cout<<"Co ords of game piece is : "<<uint8_t(I->GetPosX()+'a')<<(+I->GetPosY());

        if(I->GetColor() == 0){cout<<" And the color is : White"<<endl;}
        else {cout<<" And the color is : Black"<<endl;}
    }
}

bool GameManager::RemoveGamePiece(const Coordinates<uint8_t,uint8_t>& Input,vector<ChessPiece*>& list)
{
    bool RemovingPiece = false;
    int pos = 0;
    for (ChessPiece* I :list)
    {
        if((I->GetPosX() == Input.GetX() )&&(I->GetPosY() == Input.GetY())&&(I->GetColor() != gamefield.GetTurn()))
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
    ChessPiece* King = NULL;
    for (ChessPiece* I :list)
    {
        if((I->GetColor() == gamefield.GetTurn())&&I->IsKing())
        {
            King = I;
            break;
        }
    }
    if(King != NULL)
    {
        for (ChessPiece* I :list)
        {
            if((I->GetColor() !=gamefield.GetTurn()) && I->CheckingValidMove(King->GetPos()))
            {
                cout<<"debug check:"<<I->GetPosX()<<I->GetPosY()<<endl;
                Check = true;
            }
        }
    }
    else
    {
        cout<<"Error no king"<<endl;
        Check = true;
    }
    return Check;
}

void GameManager::LoggingMove(Coordinates<uint8_t, uint8_t> &Begin, Coordinates<uint8_t, uint8_t> &End)
{
    ofstream myfile;
    myfile.open ("xample.txt",ios::app);
    if(gamefield.GetTurn())
    {
        myfile <<"black "<<uint8_t(Begin.GetX()+'a')<<(+Begin.GetY())<<" TO "<<uint8_t(End.GetX()+'a')<<(+End.GetY())<<endl;
    }
    else
    {
        myfile <<"white "<<uint8_t(Begin.GetX()+'a')<<(+Begin.GetY())<<" TO "<<uint8_t(End.GetX()+'a')<<(+End.GetY())<<endl;
    }
    myfile.close();
}

void GameManager::PromotingPawn(ChessPiece* & Piece)
{

    if(Piece->IsPawn() && ((!Piece->GetColor() && (Piece->GetPosY() == 8)) || (Piece->GetColor() && (Piece->GetPosY() == 1))) )
    {

        Coordinates<uint8_t, uint8_t> Position(Piece->GetPosX(),Piece->GetPosY());
        bool Color = Piece->GetColor();
        char Piece;

        bool NewPiece = false;
        while(!NewPiece){
            cout<<"Promoting pawn :" <<endl;
            cout<<"Knight = k" <<endl;
            cout<<"Bishop = b" <<endl;
            cout<<"Rook   = r" <<endl;
            cout<<"Queen  = q" <<endl;
            cout<<"please select a piece for position "<< uint8_t(Position.GetX() + 'a')<<(+Position.GetY()) << " :";
            cin>>Piece;
            Piece = tolower(Piece);
            if((Piece = 'k')||(Piece = 'b')||(Piece = 'r')||(Piece = 'q'))
            {
                NewPiece = true;
            }
            else{cout<<"Invalid action"<<endl;}
        }
        gamefield.RemovePiece(Position,Color);
        gamefield.AddPiece(Position,Color,Piece);
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
        ChessPiece* SelectedPiece = NULL;
        Coordinates<uint8_t,uint8_t> EndPosition;
        Coordinates<uint8_t,uint8_t> BeginPosition;

        PrintGamePiecePosistion(list);
        //begin postion
        if(gamefield.GetTurn()){cout<<"Blacks turn"<<endl<<"Please enter pawn that you want to move :";}
        else{cout<<"Whites turn"<<endl<<"Please enter pawn that you want to move :";}
        ScanInput(BeginPosition);
        for (ChessPiece* I :list)
        {
        if((I->GetPosX() == BeginPosition.GetX() )&&(I->GetPosY() == BeginPosition.GetY())&&(I->GetColor() == gamefield.GetTurn()))
            {
                SelectedPiece = I;
                FoundPiece = true;
            }
        }


        if(FoundPiece)
        {
            //end position
            cout<<"To ?:";
            ScanInput(EndPosition);
            SamePiece = SelectedPiece->SamePiece(EndPosition,list);
            if(!SamePiece)
            {
            ValidMove = SelectedPiece->CheckingValidMove(EndPosition,true);
            // is het intersant om bv if(Move()){valid = true}else{break}? om niet nodeloos functies te callen als het toch al invalid is
            RemovingPiece = RemoveGamePiece(EndPosition,list);
            //same comment
            Check = CheckingForCheck(list);
            //same comment
            }

            //special moves
            PromotingPawn(SelectedPiece);
        }
        //returning errors
        if(!FoundPiece){cout<<"Selected invalid piece"<<endl;}

        if(!ValidMove){cout<<"invalid Move"<<endl;}

        if(SamePiece){cout<<"Selected Same coordiantes"<<endl;}

        if(Check){cout<<"Standing check"<<endl;}

        if(FoundPiece && ValidMove && !SamePiece && !Check)
        {
            if(RemovingPiece)
            {
                gamefield.RemovePiece(EndPosition,!gamefield.GetTurn());
            }
            cout<<"Valid"<<endl;
            LoggingMove(BeginPosition,EndPosition);
            TurnCompleted = true;
        }
        else if(FoundPiece)
        {
            SelectedPiece->ResetMove(BeginPosition);
        }
    }
    gamefield.EndTurn();
}




