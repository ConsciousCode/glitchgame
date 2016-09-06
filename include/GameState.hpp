#ifndef GAME_STATE_HPP
#define GAME_STATE_HPP

#include <vector>

struct GameState;

#include "Controller.hpp"
#include "Room.hpp"
#include "Entity.hpp"

struct GameState {
	Player player;
	Controller controller;
	Room room;
	
	std::vector<Entity*> entities;
};

#endif
