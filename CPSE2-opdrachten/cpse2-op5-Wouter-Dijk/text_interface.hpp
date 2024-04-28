#ifndef TEXT_INTERFACE_HPP
#define TEXT_INTERFACE_HPP

#include "game_model.hpp"
#include <iostream>

class text_interface{
public:
	text_interface(){};
    void updateView(game_model& m);
	void showWinner(game_model& m);
};

#endif