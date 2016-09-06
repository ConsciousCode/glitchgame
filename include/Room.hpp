#ifndef GAME_ROOM_HPP
#define GAME_ROOM_HPP

#include <vector>

#include <SFML/Graphics.hpp>

#include "config.hpp"

struct Tileset {
	sf::Texture ts;
	std::vector<sf::Sprite> tiles;
	
	void load(const char* fn, int ntiles);
	
	void draw(sf::RenderTarget* g, int x, int y, int t);
};

struct Room {
	unsigned char data[RW*RH];
	
	unsigned char& get(int x, int y);
	
	void save(const char* fn);
	
	void load(const char* fn);
	
	void draw(Tileset* ts, sf::RenderTarget* g);
};

#endif
