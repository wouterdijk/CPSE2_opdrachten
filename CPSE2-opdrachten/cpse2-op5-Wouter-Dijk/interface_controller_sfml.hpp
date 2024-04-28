#ifndef INTERFACE_CONTROLLER_SFML_HPP
#define INTERFACE_CONTROLLER_SFML_HPP

#include <iostream>
#include <SFML/Graphics.hpp>
#include "sfml_interface.hpp"

class interface_controller_sfml {
private:
    game_model& model;
    sfml_interface& view;
	bool moveUndone = false;

public:
    interface_controller_sfml(game_model& model, sfml_interface& view):
		model(model),
		view(view)
	{}
	
	bool interact( sf::Vector2f pos, bool player, int m_pos);
	void run();
};

#endif