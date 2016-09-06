#include <iostream>

#include "Debug.hpp"

Debug::Debug() {
	select.setSize(sf::Vector2f{SCALE, SCALE});
	select.setFillColor(sf::Color(255, 0, 255, 128));
	
	repl = 0;
}

Debug& Debug::operator++() {
	#ifdef DEBUG
	std::cout << std::endl;
	#endif
	
	return *this;
}

void Debug::handle_event(GameState* gs, sf::RenderWindow* w, sf::Event ev) {
	#ifdef DEBUG
	if(ev.type == sf::Event::MouseButtonPressed) {
		if(ev.mouseButton.button == sf::Mouse::Left) {
			sf::Vector2i pos = sf::Mouse::getPosition(*w);
			
			gs->room.get(
				(int)(pos.x/SCALE), (int)(pos.y/SCALE)
			) = repl;
		}
	}
	else if(ev.type == sf::Event::MouseWheelMoved) {
		repl = (repl + ev.mouseWheel.delta)%TS;
	}
	#endif
}

void Debug::draw(sf::RenderWindow* w) {
	#ifdef DEBUG
	sf::Vector2i pos = sf::Mouse::getPosition(*w);
	
	select.setPosition(
		(int)(pos.x/SCALE)*SCALE, (int)(pos.y/SCALE)*SCALE
	);
	w->draw(select);
	#endif
}
