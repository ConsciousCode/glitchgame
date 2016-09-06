#ifndef GAME_DEBUG_HPP
#define GAME_DEBUG_HPP

#include <SFML/Graphics.hpp>

#include "GameState.hpp"

/**
 * Putting all debug code in a single class that does nothing when not
 *  debugging makes integrating that code loads easier.
**/
struct Debug {
	sf::RectangleShape select;
	unsigned char repl;
	
	Debug();
	
	Debug& operator++();
	
	template<typename T>
	Debug& operator<<(T x) {
		#ifdef DEBUG
		std::cout << x;
		#endif
		
		return *this;
	}
	
	void handle_event(GameState* gs, sf::RenderWindow* w, sf::Event ev);
	
	void draw(sf::RenderWindow* w);
};

static Debug debug;

#endif
