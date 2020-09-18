#include <SFML/Graphics.hpp>
#include <string>
#include "background.cpp"
#include "boardmap.cpp"

int main() {
  sf::RenderWindow window(sf::VideoMode(855,495), "SFML works!");

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
	Background bgMap;
	if (!bgMap.load("../resources/images/Board.png", sf::Vector2u(45, 45), bg, 19, 11))
		return -1;	
	
	//get the pieces
	int board[] = 
	{
		+22, +24, +23, +21, +20, +23, +24, +22, +00,
		+25, +25, +25, +25, +25, +25, +25, +25, +00,
		+00, +00, +00, +00, +00, +00, +00, +00, +00,
		+00, +00, +00, +00, +00, +00, +00, +00, +00,
		+00, +00, +00, +00, +00, +00, +00, +00, +00,
		+00, +00, +00, +00, +00, +00, +00, +00, +00,
		+37, +37, +37, +37, +37, +37, +37, +37, +37,
		+00, +32, +00, +00, +00, +00, +00, +31, +00,
		+36, +35, +34, +33, +30, +33, +34, +35, +36
	};
	for (unsigned int i = 0; i < sizeof(board)/sizeof(board[0]); i++) {
		board[i] *= -1;
	}
	BoardMap boardMap;
	if (!boardMap.load("../resources/images/Pieces.png", sf::Vector2u(45, 45), board, 9, 9, sf::Vector2u(5 * 45, 45)))
		return -1;

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
			window.close();
		}

		window.clear();
		window.draw(bgMap);
		window.draw(boardMap);
		window.display();
	}

	return 0;
}