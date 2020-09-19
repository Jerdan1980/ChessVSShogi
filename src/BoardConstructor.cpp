#include "Piece.h"
#include <vector>


void createBoard(std::vector<Piece*> &pieces) {
	for (int i = 0; i < 4; i++) {
		pieces.push_back(new Rook(1, 0));
		pieces.push_back(new Bishop(1, 0));
	}
	pieces.push_back(new Queen(1));
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 9; j++) {
			pieces.push_back(new Piece());
		}
	}
}