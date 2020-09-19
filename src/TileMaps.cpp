#include "Piece.h"
#include <SFML/Graphics.hpp>
#include <string>
#include <vector>

class TiledMap : public sf::Drawable, public sf::Transformable {
public:
	bool load(const std::string& tileset, sf::Vector2u tileSize, const std::string& tiles, unsigned int width, unsigned int height, sf::Vector2u offset) {
		//Load the tileset texture
		if (!m_tileset.loadFromFile(tileset))
			return false;
		
		//resize the vertex array to fit the level size
		m_vertices.setPrimitiveType(sf::Quads);
		m_vertices.resize(width * height * 4);

		//populate the vertex array, with one quad per tile
		for (unsigned int x = 0; x < width; x++) {
			for (unsigned int y = 0; y < height; y++) {
				//get the current tile number
				int tileNumber = tiles[x + y * width] - '0';

				//find its position in the tileset texture
				int tu = tileNumber % (m_tileset.getSize().x / tileSize.x);
				int tv = tileNumber / (m_tileset.getSize().x / tileSize.x);

				//get a pointer to the current tile's quad
				sf::Vertex* quad = &m_vertices[(x + y * width) * 4];

				//define its 4 corners
				quad[0].position = sf::Vector2f(x * tileSize.x + offset.x, y * tileSize.y + offset.y);
				quad[1].position = sf::Vector2f((x + 1) * tileSize.x + offset.x, y * tileSize.y + offset.y);
				quad[2].position = sf::Vector2f((x + 1) * tileSize.x + offset.x, (y + 1) * tileSize.y + offset.y);
				quad[3].position = sf::Vector2f(x * tileSize.x + offset.x, (y + 1) * tileSize.y + offset.y);

				//define its 4 texture coordinates
				quad[0].texCoords = sf::Vector2f(tu * tileSize.x, tv * tileSize.y);
				quad[1].texCoords = sf::Vector2f((tu + 1) * tileSize.x, tv * tileSize.y);
				quad[2].texCoords = sf::Vector2f((tu + 1) * tileSize.x, (tv + 1) * tileSize.y);
				quad[3].texCoords = sf::Vector2f(tu * tileSize.x, (tv + 1) * tileSize.y);
			}
		}
		return true;
	}
private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const {
		//apply the transform
		states.transform *= getTransform();

		//apply the tileset texture
		states.texture = &m_tileset;

		//draw the vertex array
		target.draw(m_vertices, states);
	}

	sf::VertexArray m_vertices;
	sf::Texture m_tileset;
};

class PieceMap : public sf::Drawable, public sf::Transformable {
public:
	bool load(const std::string& tileset, sf::Vector2u tileSize, std::vector<Piece*> &pieces, unsigned int width, unsigned int height, sf::Vector2u offset) {
		//load the tileset texture
		if(!m_tileset.loadFromFile(tileset))
			return false;
		
		//resize the vertex array to fit the level size
		m_vertices.setPrimitiveType(sf::Quads);
		m_vertices.resize(width * height * 4);

		//populate the vertex array, with one quad per tile
		for (unsigned int x = 0; x < width; x++) {
			for (unsigned int y = 0; y < height; y++) {
				//get the current tile number
				int tileNumber = pieces[x + y * width]->getTilemap();

				//find its position in the tileset texture
				int tx = tileNumber % 10;
				int ty = tileNumber / 10;

				//get a pointer to the current tile's quad
				sf::Vertex* quad = &m_vertices[(x + y * width) * 4];
				
				//define its 4 corners
				quad[0].position = sf::Vector2f(x * tileSize.x + offset.x, y * tileSize.y + offset.y);
				quad[1].position = sf::Vector2f((x + 1) * tileSize.x + offset.x, y * tileSize.y + offset.y);
				quad[2].position = sf::Vector2f((x + 1) * tileSize.x + offset.x, (y + 1) * tileSize.y + offset.y);
				quad[3].position = sf::Vector2f(x * tileSize.x + offset.x, (y + 1) * tileSize.y + offset.y);

				//define its 4 texture coords
				bool flip = false; //tiles[x + y * width] < 0;
				quad[flip ? 2 : 0].texCoords = sf::Vector2f(tx * tileSize.x, ty * tileSize.y);
				quad[flip ? 3 : 1].texCoords = sf::Vector2f((tx + 1) * tileSize.x, ty * tileSize.y);
				quad[flip ? 0 : 2].texCoords = sf::Vector2f((tx + 1) * tileSize.x, (ty + 1) * tileSize.y);
				quad[flip ? 1 : 3].texCoords = sf::Vector2f(tx * tileSize.x, (ty + 1) * tileSize.y);
			}
		}
		return 1;
	}
private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const {
		//apply the transform
		states.transform *= getTransform();
		//apply the tileset texture
		states.texture = &m_tileset;
		//draw the vertex array
		target.draw(m_vertices, states);
	}

	sf::VertexArray m_vertices;
	sf::Texture m_tileset;
};