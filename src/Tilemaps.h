#pragma once
#include "Piece.h"
#include <SFML/Graphics.hpp>
#include <string>
#include <vector>

class TiledMap : public sf::Drawable, public sf::Transformable {
	public:
		bool load(const std::string& tileset, sf::Vector2u tileSize, const std::string& tiles, unsigned int width, unsigned int height, sf::Vector2i offset);
		bool update(const std::string& tiles);

		unsigned int getWidth();
		unsigned int getHeight();
		sf::Vector2i getOffset(bool pixel);

	private:
		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

		//variables
		std::string tileset;
		sf::Vector2u tileSize;
		unsigned int width;
		unsigned int height;
		sf::Vector2i offset;
		sf::VertexArray m_vertices;
		sf::Texture m_tileset;
};

class PieceMap : public sf::Drawable, public sf::Transformable {
	public:
		bool load(const std::string& tileset, sf::Vector2u tileSize, const std::vector<Piece*> &pieces, unsigned int width, unsigned int height, sf::Vector2i offset);
		bool update(const std::vector<Piece*> &pieces);

		unsigned int getWidth();
		unsigned int getHeight();
		sf::Vector2i getOffset(bool pixel);

	private:
		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

		//variables
		std::string tileset;
		sf::Vector2u tileSize;
		unsigned int width;
		unsigned int height;
		sf::Vector2i offset;
		sf::VertexArray m_vertices;
		sf::Texture m_tileset;
};