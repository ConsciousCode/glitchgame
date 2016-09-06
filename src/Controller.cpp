#include "Controller.hpp"

void Controller::press(sf::Keyboard::Key key) {
	pressed[key] = true;
}

void Controller::release(sf::Keyboard::Key key) {
	pressed[key] = false;
}

int Controller::horiz() {
	return pressed[binding.right] - pressed[binding.left];
}

int Controller::vert() {
	return pressed[binding.down] - pressed[binding.up];
}
