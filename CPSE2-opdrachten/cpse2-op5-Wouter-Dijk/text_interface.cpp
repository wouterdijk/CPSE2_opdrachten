#include "text_interface.hpp"

void text_interface::updateView(game_model& m){
	std::vector<char> temp = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
	for(unsigned int i=0 ; i < m.moves.size() ; i++){
		temp[m.moves[i].pos - 1] = m.moves[i].player;
	}

	for(int i = 0; i < 9; i+=3){
		std::cout << temp[i] << " | " << temp[i+1] << " | " << temp[i+2] << std::endl; 
	} 
}

void text_interface::showWinner(game_model& m){
	char winner = m.getWinner();
	if(winner == 'x'){
		std::cout << "Player X has won congratulations!!!!!" << std::endl;
	}else if(winner == 'o'){
		std::cout << "Player O has won congratulations!!!!!" << std::endl;
	}
}