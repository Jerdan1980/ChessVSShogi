#include "Piece.h"
#include <vector>


std::vector<Piece> createBoard() {
	std::vector<Piece> pieces;
	Piece* temp;
	for (int i = 0; i < 4; i++) {
		temp = new Rook(1, 0);
		pieces.push_back(*temp);
		temp = new Bishop(1, 0);
		pieces.push_back(*temp);
	}
	temp = new Queen(1);
	pieces.push_back(*temp);
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 9; j++) {
			temp = new Piece();
			pieces.push_back(*temp);
		}
	}
	return pieces;
}