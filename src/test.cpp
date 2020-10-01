#include "Piece.h"
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include <vector>
#include "TileMaps.cpp"
#include "BoardConstructor.cpp"

int main() {
  sf::RenderWindow window(sf::VideoMode(19 * 45, 12 * 45), "Chess vs Shogi");

	//add a font
	sf::Font font;
	if(!font.loadFromFile("../resources/fonts/SawarabiMincho-Regular.ttf"))
		return -1;
	
	//make some text
	sf::Text text;
	text.setFont(font);
	text.setString(L"Hello かわいい");
	text.setCharacterSize(26);
	text.setFillColor(sf::Color::Black);
	
	//set a bool to redraw
	bool redraw = true;

	//create the background
	const std::string bg = "2222222222222222222" +
						(std::string)"0000000000000000000" +
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
	if (!bgMap.load("../resources/images/Board.png", sf::Vector2u(45, 45), bg, 19, 12, sf::Vector2i(0,0)))
		return -1;	
	
	//get the pieces
	//board constructor
	std::vector<Piece*> pieces;
	createBoard(pieces);
	PieceMap boardMap;
	if (!boardMap.load("../resources/images/Pieces.png", sf::Vector2u(45, 45), pieces, 9, 9, sf::Vector2i(5, 2)))
		return -1;

	//highlighting
	std::string high = "0000000000000000000" +
				(std::string)"0000000000000000000" +
				(std::string)"0000000000002000000" +
				(std::string)"0000000000010000000" +
				(std::string)"0000000000100000000" +
				(std::string)"0000000001000000000" +
				(std::string)"0000000010000000000" +
				(std::string)"0000000100000000000" +
				(std::string)"0000001000000000000" +
				(std::string)"0000000000000000000";
	TiledMap highMap;
	if (!highMap.load("../resources/images/Highlights.png", sf::Vector2u(45, 45), high, 19, 10, sf::Vector2i(0, 1)))
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
						sf::Vector2i tile = (localPosition - highMap.getOffset(true)) / 45;
						//mock update (toggle between modes)
						high[tile.x + tile.y * highMap.getWidth()] = "012"[((high[tile.x + tile.y * highMap.getWidth()] - '0') + 1) % 3];
						//slate tilemaps to be updated
						redraw = true;
						//state what tile was updated
						text.setString("(" + std::to_string(tile.x) + ", " + std::to_string(tile.y) + ")");
					}
					break;
			}
		}

		//update tilemaps
		if (redraw) {
			boardMap.update(pieces);
			highMap.update(high);
			redraw = false;
		}

		//draw everything
		window.clear();
		window.draw(bgMap);
		window.draw(boardMap);
		window.draw(highMap);
		window.draw(text);
		window.display();		
	}

	return 0;
}