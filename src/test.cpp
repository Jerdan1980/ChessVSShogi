#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include <vector>
#include "TileMaps.cpp"
#include "Piece.h"

int main() {
  sf::RenderWindow window(sf::VideoMode(855,495), "SFML works!");
	
	//set a bool to redraw
	bool redraw = true;

	//create the background
	const std::string bg = "0000000000000000000" +
						(std::string)"0000012121212101110" +
						(std::string)"0000021212121201110" +
						(std::string)"0000012121212101110" +
						(std::string)"0000021212121201110" +
						(std::string)"0000012121212100000" +
						(std::string)"0111021212121200000" +
						(std::string)"0111012121212100000" +
						(std::string)"0111021212121200000" +
						(std::string)"0111012121212100000" +
						(std::string)"0000000000000000000";
	TiledMap bgMap;
	if (!bgMap.load("../resources/images/Board.png", sf::Vector2u(45, 45), bg, 19, 11, sf::Vector2u(0,0)))
		return -1;	
	
	//get the pieces
	int board[] = 
	{
		+22, +24, +23, +21, +20, +23, +24, +00, +22,
		+25, +25, +25, +25, +25, +25, +25, +25, +00,
		+00, +00, +00, +00, +00, +00, +00, +00, +00,
		+00, +00, +00, +00, +00, +00, +00, +00, +00,
		+00, +00, +00, +00, +00, +00, +00, +00, +00,
		+00, +00, +37, +00, +00, +00, +00, +00, +00,
		+37, +37, +00, +37, +37, +37, +37, +37, +37,
		+00, +32, +00, +00, +00, +00, +00, +31, +00,
		+36, +35, +34, +33, +30, +33, +34, +35, +36
	};
	PieceMap boardMap;
	if (!boardMap.load("../resources/images/Pieces.png", sf::Vector2u(45, 45), board, 9, 9, sf::Vector2u(5 * 45, 45)))
		return -1;

	//highlighting
	//create the background
	std::string high = "00000000000000000" +
				(std::string)"00000000000200000" +
				(std::string)"00000000001000000" +
				(std::string)"00000000010000000" +
				(std::string)"00000000100000000" +
				(std::string)"00000001000000000" +
				(std::string)"00000010000000000" +
				(std::string)"00000100000000000" +
				(std::string)"00000000000000000";
	TiledMap highMap;
	if (!highMap.load("../resources/images/Highlights.png", sf::Vector2u(45, 45), high, 17, 9, sf::Vector2u(45, 45)))
		return -1;	

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			switch (event.type) {
				//check if closed window
				case sf::Event::Closed:
					window.close();
					break;
				
				//check if you selected something
				case sf::Event::MouseButtonPressed:
					if (event.mouseButton.button == sf::Mouse::Left) {
						//get mouse position
						sf::Vector2i localPosition = sf::Mouse::getPosition(window);
						//get corresponding tile
						sf::Vector2i tile = (localPosition - sf::Vector2i(45, 45)) / 45;
						//mock update (toggle between modes)
						high[tile.x + tile.y * 17] = "012"[((high[tile.x + tile.y * 17] - '0') + 1) % 3];
						//slate tilemaps to be updated
						redraw = true;
					}
					break;
			}
		}

		//update tilemaps
		if (redraw) {
			boardMap.load("../resources/images/Pieces.png", sf::Vector2u(45, 45), board, 9, 9, sf::Vector2u(5 * 45, 45));
			highMap.load("../resources/images/Highlights.png", sf::Vector2u(45, 45), high, 17, 9, sf::Vector2u(45, 45));
			redraw = false;
		}

		//draw everything
		window.clear();
		window.draw(bgMap);
		window.draw(boardMap);
		window.draw(highMap);
		window.display();		
	}

	return 0;
}