#ifndef GAME_ENTITY_HPP
#define GAME_ENTITY_HPP

#include <SFML/Graphics.hpp>

#include <iostream>

struct Entity;
struct Player;

struct GameState;

/**
 * Basic entity interface.
**/
struct Entity {
	sf::Sprite sprite;
	
	virtual void upkeep(GameState* gs, sf::Time t) = 0;
	
	virtual void draw(sf::RenderTarget* target) = 0;
	
	virtual bool collide(float x, float y) = 0;
};

struct Player : public Entity {
	void upkeep(GameState* gs, sf::Time t);
	
	void draw(sf::RenderTarget* target);
	
	bool collide(float x, float y);
};

#endif
