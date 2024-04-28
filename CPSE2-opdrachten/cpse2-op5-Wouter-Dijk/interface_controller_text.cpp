#include "interface_controller_text.hpp"
#include <iostream>

bool interface_controller_text::handleInput(bool player){
	std::string input;
	int m;
	bool good_input = false;
	if(player){
		std::cout << "X place your move 1 through 9 ( 0 is undo last move ): ";
	}else{
		std::cout << "O place your move 1 through 9 ( 0 is undo last move ): ";
	}
	
	while(!good_input){
		std::cin >> input;
		if(input.length() == 1){
			if(input[0] >= '0' && input[0] <= '9'){
				if(input[0] == '0'){
					model.undoMove();
					return !player;
				}
				m = stoi(input);
				good_input = true;
			}else{
				std::cout << "Invalide character try again: ";
			}
		}else{
			std::cout << "Invalide amount of characters. you can only have one charcter, try again: ";
		}
	}
	std::cout << std::endl;
	
	for(unsigned int i = 0 ; i < model.moves.size() ; i++){
		if(model.moves[i].pos == m){
			std::cout << "This move has already been done try again" << std::endl;
			return player;
		}
	}
	std::cout << "Move made" << std::endl;
	if(player){
		model.makeMove(m,'x');
		return !player;
	}else{
		model.makeMove(m,'o');
		return !player;
	}
}