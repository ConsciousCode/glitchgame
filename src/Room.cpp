#include "Room.hpp"

void Tileset::load(const char* fn, int ntiles) {
	ts.loadFromFile(fn);
	tiles.clear();
	
	for(int i = 0; i < ntiles; ++i) {
		tiles.push_back(
			sf::Sprite{ts, sf::IntRect{
				(i%TSW)*SCALE, (i/TSW)*SCALE, SCALE, SCALE
			}}
		);
	}
}

void Tileset::draw(sf::RenderTarget* g, int x, int y, int t) {
	tiles[t].setPosition(sf::Vector2f{(float)x, (float)y});
	g->draw(tiles[t]);
}

unsigned char& Room::get(int x, int y) {
	return data[(y*RW + x)%(RW*RH)];
}

void Room::save(const char* fn) {
	FILE* f = fopen(fn, "r");
	fwrite(data, 1, RW*RH, f);
	fclose(f);
}

void Room::load(const char* fn) {
	FILE* f = fopen(fn, "r");
	fread(data, 1, RW*RH, f);
	fclose(f);
}

void Room::draw(Tileset* ts, sf::RenderTarget* g) {
	for(int y = 0; y < RH; ++y) {
		for(int x = 0; x < RW; ++x) {
			ts->draw(g, x*SCALE, y*SCALE, get(x, y));
		}
	}
}
