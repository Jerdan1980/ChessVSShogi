# Requirements
- SFML 2.5.1 MinGW x64
- MinGW 7.3.0 x64 (provided by SFML)

# Compiling
1. create a makefile and replace the SFMLDIR var with your directory
2. run `mingw32-make` or whatever
3. copy/paste the dll files from SFML/bin to the /build folder
4. run `./build/app.exe`

# Piece Representation
Negative number means the piece is flipped vertically
- 00 Blank
- 1X White Chess Pieces
	- 10 King
	- 11 Queen
	- 12 Rook
	- 13 Bishop
	- 14 Knight
	- 15 Pawn
- 2X Black Chess Pieces
	- 20 King
	- 21 Queen
	- 22 Rook
	- 23 Bishop
	- 24 Knight
	- 25 Pawn
- 3X Shogi Pieces (Unpromoted)
	- 30 King (wont differientate between the two versions)
	- 31 Rook
	- 32 Bishop
	- 33 Gold General
	- 34 Silver General
	- 35 Knight
	- 36 Lance
	- 37 Pawn
- 4X Shogi Pieces (Promoted)
	- 41 Promoted Rook
	- 42 Promoted Bishop
	- 44 Promoted Silver General
	- 45 Promoted Knight
	- 46 Promoted Lance
	- 47 promoted Pawn