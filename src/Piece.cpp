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
    if(this->shogi){
        return this->number + this->promoted + (this->number - 10);
    }
    return this->number + !(this->white) + (this->number - 10);
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

bool Piece::validMove(int move, int cur[], int to[]){
    if(this->promoted && this->shogi) {
        if(singleCross(cur, to)){
            return true;
        } 
        
        else if ((abs(cur[1] - to[1]) == 1) && (abs(cur[0] - to[0]) == 1))
        {
           if(this->white){
               return to[1] < cur[1];
           }
           return to[1] < cur[1];
        }
        return false;
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