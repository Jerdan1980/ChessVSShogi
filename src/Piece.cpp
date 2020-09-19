#include "Piece.h"
#include <stdlib.h>

int Piece::getNumber(){
    return this->number;
}

int Piece::getShogi(){
    return this->shogi;
}

int Piece::getMovement(){
    return this->movement;
}

bool Piece::getWhite(){
    return this->white;
}

bool Piece::getPromoted(){
    return this->promoted;
}

Piece::Piece(){

}

int Piece::getTilemap(){
   if(this->number != 0){
        if(this->shogi){
            return this->number + this->promoted + (this->number - 10);
        }
        return this->number + !(this->white) + (this->number - 10);
    }
    return 0;
}

Piece::Piece(bool white, int type, int movement, int number){
    this->movement = movement;
    this->shogi = (type % 2) == 0;
    this->white = white;
    if(type != 4){
        this->number = number;
    }
    else{
        this->number = number + 1;
    }
}

bool SingleDiag(int cur[], int to[]) {
    return (abs(cur[1] - to[1]) == 1) && (abs(cur[0] - to[0]) == 1);
}

bool singleCross(int cur[], int to[]){
    return (cur[1] == to[1] && (abs(cur[0] - to[0]) == 1)) || (cur[0] == to[0] && (abs(cur[1] - to[1]) == 1));
}

bool forwardDiag(int cur[], int to[], bool white){
    return ((abs(cur[1] - to[1]) == 1) && (abs(cur[0] - to[0]) == 1));
}

bool singleMove(int cur[], int to[], bool white){
    if(white){
        return to[1] < cur[1];
    }
    return to[1] < cur[1];
}

bool goldCheck(int cur[], int to[], bool white){
    if(singleCross(cur, to)){
            return true;
        } 
    else if(forwardDiag(cur, to, white))
    {
        return singleMove(cur, to, white);
    }
    return false;
}

bool Piece::validMove(int move, int cur[], int to[]){
    if(this->promoted && this->shogi) {
        return goldCheck(cur, to, this->white);
    }
    return ((move & this->movement) != 0);
}

bool Rook::validMove(int move, int cur[], int to[]){
    if(this->promoted && this->shogi) {
        if (SingleDiag(cur, to))
        {
           return true;
        }
    }
    return ((move & this->movement) != 0);
}

bool Bishop::validMove(int move, int cur[], int to[]){
    if(this->promoted && this->shogi) {
        if (singleCross(cur, to))
        {
           return true;
        }
    }
    return ((move & this->movement) != 0);
}

bool Pawn::validMove(int move, int cur[], int to[], bool haspiece){
   if(this->shogi) {
        if (this->promoted)
        {
           return goldCheck(cur, to, this->white);
        }
        else if(cur[0] == to[0])
        {
            return singleMove(cur, to, this->white);
        }
        return false;
    }
    else if((move & this->movement) != 0){
        if(cur[0] == to[0]  ){
            if(white){
               return (to[1] - cur[1] == -1) || ((to[1] - cur[1] == -2) && !(this->moved));
            }
            return (to[1] - cur[1] == 1) || ((to[1] - cur[1] == 2) && !(this->moved));
        }
        else if(forwardDiag(cur, to, white)){
            return singleMove(cur, to, white) && haspiece;
        }
    }
    return false;
}

bool SilverG::validMove(int move, int curr[], int to[]){
    if(this->promoted){
        return goldCheck(curr, to, this->white);       
    }
    else if((move & this->movement) != 0){
        if(SingleDiag(curr, to)){
            return true;
        }
        return singleMove(curr, to, white);
    }
    return false;
}

bool GoldG::validMove(int move, int curr[], int to[]){
    return goldCheck(curr, to, this->white);
}