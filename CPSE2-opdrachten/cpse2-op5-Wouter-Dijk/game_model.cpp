#include <iostream>
#include "game_model.hpp"

void game_model::makeMove(int pos, char player){
	moves.push_back( move(pos, player) );
};

void game_model::undoMove(){
	moves.pop_back();
};

char game_model::getWinner(){
	std::vector<std::vector<int>> v = {{1,2,3},{4,5,6},{7,8,9},{1,4,7},{2,5,8},{3,6,9},{1,5,9},{7,5,3}};
	std::vector<char> temp = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
	for(unsigned int i=0 ; i < moves.size() ; i++){
		temp[moves[i].pos] = moves[i].player;
	}

	for(int i=0 ; i<8 ; i++){
		if(temp[v[i][0]] == 'x' && temp[v[i][1]] == 'x' && temp[v[i][2]] == 'x'){
			return 'x';
		}else if(temp[v[i][0]] == 'o' && temp[v[i][1]] == 'o' && temp[v[i][2]] == 'o'){
			return 'o';
		}
	}
	return ' ';
};

bool game_model::isGameOver(){
	if(getWinner() == ' '){
		return false;
	}else{
		return true;
	}
};