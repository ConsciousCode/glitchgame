#include <map>
#include <vector>

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include "config.hpp"
#include "Debug.hpp"

#include "GameState.hpp"
#include "Room.hpp"
#include "Entity.hpp"

int main() {
	sf::RenderWindow w(sf::VideoMode(RW*SCALE, RH*SCALE), "Error");
	sf::Clock clock;
	sf::Event ev;
	
	GameState gs;
	Tileset ts;
	
	//Load the assets
	ts.load("tileset.png", TS);
	gs.room.load("test.map");
	
	while(w.isOpen()) {
		sf::Time elapsed = clock.restart();
		
		while(w.pollEvent(ev)) {
			switch(ev.type) {
				case sf::Event::Closed:
					w.close();
					break;
				
				case sf::Event::KeyPressed:
					gs.controller.press(ev.key.code);
					break;
				
				case sf::Event::KeyReleased:
					gs.controller.release(ev.key.code);
					break;
			}
			
			debug.handle_event(&gs, &w, ev);
		}
		
		w.clear(sf::Color::Red);
		
		gs.room.draw(&ts, &w);
		
		gs.player.upkeep(&gs, elapsed);
		gs.player.draw(&w);
		
		for(Entity* ent : gs.entities) {
			ent->upkeep(&gs, elapsed);
			ent->draw(&w);
		}
		
		debug.draw(&w);
		
		w.display();
	}
	
	return 0;
}
