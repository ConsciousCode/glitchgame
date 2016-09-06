#ifndef GAME_CONTROLLER_HPP
#define GAME_CONTROLLER_HPP

#include <map>

#include <SFML/Window.hpp>

struct Controller {
	std::map<sf::Keyboard::Key, bool> mapping;
	
	struct {
		sf::Keyboard::Key up, down, left, right;
		
		sf::Keyboard::Key start, jump;
	} binding;
	
	std::map<sf::Keyboard::Key, bool> pressed;
	
	void press(sf::Keyboard::Key key);
	
	void release(sf::Keyboard::Key key);
	
	int horiz();
	
	int vert();
};

#endif
