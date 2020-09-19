#pragma once
using namespace std;

class Piece{
    protected:
    int number = 0;
    bool white = true;
    int movement = 0;
    bool promoted = false;
    bool shogi = false;

    public:    
    Piece();
    Piece(bool white, int type, int movement, int number);
    int getTilemap();
    int getNumber();
    int getShogi();
    int getMovement();
    bool getWhite();
    bool getPromoted();
    bool validMove(int move, int curr[], int to[]);

};

class Queen: public Piece {

    public:
    Queen(bool white) : Piece(white, 1, 110, 18) {};
};

class Pawn: public Piece {
    bool moved = false;
    
    public:
    Pawn(bool white, bool shogi) : Piece(white, shogi+3, 110, 16) {};
    bool validMove(int move, int cur[], int to[], bool haspiece);
};

class Lance: public Piece {

    public:
    Lance(bool white) : Piece(white, 2, 100, 19) {};
};

class Knight: public Piece {

    public:
    Knight(bool white, bool shogi) : Piece(white, shogi+3, 1, 12) {};
};

class SilverG: public Piece {
    
    public:
    SilverG(bool white) : Piece(white, 2, 110, 20) {};
    bool validMove(int move, int curr[], int to[]);
};

class GoldG: public Piece { 

    public:
    GoldG(bool white) : Piece(white, 2, 110, 21) {};
    bool validMove(int move, int curr[], int to[]);
};

class Bishop: public Piece {
    
    public:
    Bishop(bool white, bool shogi) : Piece(white, shogi+3, 10, 10) {};
    bool validMove(int move, int curr[], int to[]);
};

class Rook: public Piece {

    public:
    Rook(bool white, bool shogi) : Piece(white, shogi+3, 100, 14) {};
    bool validMove(int move, int curr[], int to[]);
};

class King: public Piece {

    public:
    King(bool white, bool shogi) : Piece(white, shogi+3, 110, 21) {};
};
