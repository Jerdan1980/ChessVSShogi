#include <SFML/Graphics.hpp>
#include <string>
#include "background.cpp"

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

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
			window.close();
		}

		window.clear();
		window.draw(bgMap);
		window.display();
	}

	return 0;
}