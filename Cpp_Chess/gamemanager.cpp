#include "gamemanager.h"
#include "coordinates.h"
#include "math.h"
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

void GameManager::PrintBoard(const vector<ChessPiece *> &list)
{
    string BlackPiece = "\033[38;5;232m";
    string WhitePiece = "\033[38;5;255m";
    string BlackSquare = "\033[48;5;144m";
    string WhiteSquare = "\033[48;5;239m";
    string Reset = "\033[0m";

    cout<<"   a  b  c  d  e  f  g  h"<<endl;
    cout<<" +------------------------+"<<endl;
    for (int Y = 8; Y > 0; --Y) {
        string Buffer;
        Buffer.push_back(char(Y + '0'));
        Buffer.push_back(char('|'));
        for (int X = 0; X < 8; ++X) {
            bool FoundPiece = false;
            if((X+Y)%2 == 0){Buffer.append(WhiteSquare);}
            else{Buffer.append(BlackSquare);}
            for (ChessPiece* I :list)
            {
                if((I->GetPosX() == X)&&(I->GetPosY() == Y))
                {
                    if(!I->GetColor()){Buffer.append(WhitePiece);}
                    else{Buffer.append(BlackPiece);}
                    Buffer.push_back(' ');
                    Buffer.append("\033[1m");
                    Buffer.push_back(I->IsPiece());
                    Buffer.push_back(' ');
                    FoundPiece = true;
                    break;
                }
            }
            if(!FoundPiece)
            {
             Buffer.append("   ");
            }
           Buffer.append(Reset);
        }
        Buffer.push_back(char('|'));
        Buffer.push_back(char(Y + '0'));
        cout<<Buffer<<endl;
    }
    cout<<" +------------------------+"<<endl;
    cout<<"   a  b  c  d  e  f  g  h"<<endl;
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

bool GameManager::Castle(Coordinates<uint8_t, uint8_t> &Begin, Coordinates<uint8_t, uint8_t> &End)
{
    ChessPiece* King = NULL;
    ChessPiece* Rook = NULL;
    for (ChessPiece* I : gamefield.GetVector())
    {
        if(((I->GetPosX() == Begin.GetX())&&(I->GetPosY() == Begin.GetY()))||((I->GetPosX() == End.GetX())&&(I->GetPosY() == End.GetY())))
        {
            if(I->IsKing()){King = I;}
            else if(I->IsRook()){Rook = I;}
        }
    }

    if((King != NULL)&&(Rook != NULL)) //correct way to input to trigger castel
    {
        if(King->GetFirstMove() && Rook->GetFirstMove() && !CheckingForCheck(gamefield.GetVector()))
        {
            bool Check = false;
            int Direction = (Rook->GetPosX() - King->GetPosX());
            if(Direction > 0) //Rechts castlen
            {
                Coordinates<uint8_t, uint8_t> KingEndPos((Rook->GetPosX()-1),Rook->GetPosY());
                Coordinates<uint8_t, uint8_t> RookEndPos((Rook->GetPosX()-2),Rook->GetPosY());
                if(Rook->CheckingValidMove(KingEndPos)&&Rook->CheckingValidMove(RookEndPos))
                {
                    for (ChessPiece* I :gamefield.GetVector())
                    {
                        if((I->GetColor() !=gamefield.GetTurn()) && (I->CheckingValidMove(KingEndPos)||I->CheckingValidMove(RookEndPos)))
                        {
                            Check = true;
                        }
                    }
                    if(!Check)
                    {
                        King->ResetMove(KingEndPos);
                        Rook->ResetMove(RookEndPos);
                        return true;
                    }
                }
            }
            else if(Direction < 0) //Links castlen
            {
                Coordinates<uint8_t, uint8_t> Pos1((Rook->GetPosX()+1),Rook->GetPosY());
                Coordinates<uint8_t, uint8_t> KingEndPos((Rook->GetPosX()+2),Rook->GetPosY());
                Coordinates<uint8_t, uint8_t> RookEndPos((Rook->GetPosX()+3),Rook->GetPosY());
                if(Rook->CheckingValidMove(Pos1)&&Rook->CheckingValidMove(KingEndPos)&&Rook->CheckingValidMove(RookEndPos))
                {
                    for (ChessPiece* I :gamefield.GetVector())
                    {
                        if((I->GetColor() !=gamefield.GetTurn()) && (I->CheckingValidMove(RookEndPos)||I->CheckingValidMove(KingEndPos)))
                        {
                            Check = true;
                        }
                    }
                    if(!Check)
                    {
                        King->ResetMove(KingEndPos);
                        Rook->ResetMove(RookEndPos);
                        return true;
                    }
                }

            }
        }
    }
    return false;
}

bool GameManager::EnPassant(ChessPiece *&Piece, Coordinates<uint8_t, uint8_t> &End)
{
    bool CorrectBeginPos = false;
    bool CorrectEndPos = false;
    bool EnPassant = false;
    if(Piece->IsPawn())
    {
        if(!Piece->GetColor()&&(Piece->GetPosY() == 5))//correct Beginposition for white
        {
            CorrectBeginPos = true;
        }
        else if(Piece->GetColor()&&(Piece->GetPosY() == 4))//correct Beginposition for black
        {
            CorrectBeginPos = true;
        }

        if(abs(Piece->GetPosX()-End.GetX()) == 1)
        {
            if(!Piece->GetColor()&&((Piece->GetPosY() - End.GetY()) == -1))//correct Endposition for white
            {
                CorrectEndPos = true;
            }
            else if(Piece->GetColor()&&(Piece->GetPosY() - End.GetY()) == 1)//correct position for black
            {
                CorrectEndPos = true;
            }
        }

        if(CorrectBeginPos && CorrectEndPos)
        {
            int Direction = Piece->GetPosX() - End.GetX();
            Coordinates<uint8_t, uint8_t> AdjacentToPawn((Piece->GetPosX()),Piece->GetPosY());

            if(Direction == 1) //right
            {
                AdjacentToPawn.setX((Piece->GetPosX()-1));
            }
            else if(Direction == -1) //left
            {
                AdjacentToPawn.setX((Piece->GetPosX()+1));
            }
            for (ChessPiece* I :gamefield.GetVector()) // Searching for Viable Adjacent Piece
            {
                if((I->GetPosX()==AdjacentToPawn.GetX())&&(I->GetPosY()==AdjacentToPawn.GetY())&&(I->GetColor()!=Piece->GetColor())&&I->IsPawn()&&I->GetSecondMove())
                {
                    EnPassant = true;
                }
            }

            if(EnPassant)
            {
                gamefield.RemovePiece(AdjacentToPawn,!Piece->GetColor());
                Piece->ResetMove(End);
                return true;
            }
        }
    }
    return false;
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

        //PrintGamePiecePosistion(list);
        PrintBoard(list);
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
            if(!ValidMove)
            {
                ValidMove = Castle(BeginPosition,EndPosition);
            }

            if(!ValidMove)
            {
                ValidMove = EnPassant(SelectedPiece,EndPosition);
            }

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




