
class Piece{
    int number = 0;
    bool white = true;

    public:
    int getNumber();

};

class pawn: public Piece {
    int number = 37;

    public:
    pawn(bool white);
};

class lance: public Piece {
    int number = 37;

    public:
    lance(bool white);
};

class knight: public Piece {
    int number = 37;

    public:
    knight(bool white);
};

class silverG: public Piece {
    int number = 37;

    public:
    silverG(bool white);
};

class goldG: public Piece {
    int number = 37;

    public:
    goldG(bool white);
};

class bishop: public Piece {
    int number = 37;

    public:
    bishop(bool white);
};

class rook: public Piece {
    int number = 37;

    public:
    rook(bool white);
};

class king: public Piece {
    int number = 37;

    public:
    king(bool white);
};
