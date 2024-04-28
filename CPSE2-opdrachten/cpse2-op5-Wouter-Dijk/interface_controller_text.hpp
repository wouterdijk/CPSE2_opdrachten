#ifndef INTERFACE_CONTROLLER_TEXT_HPP
#define INTERFACE_CONTROLLER_TEXT_HPP

#include "text_interface.hpp"

class interface_controller_text {
private:
    game_model& model;
    text_interface& view;

public:
    interface_controller_text(game_model& model, text_interface& view):
		model(model),
		view(view)
	{}
    bool handleInput(bool player);
};

#endif