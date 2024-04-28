#ifndef GAME_MODEL_HPP
#define GAME_MODEL_HPP

#include <vector>
#include "move.hpp"

class game_model{
public:
    std::vector<move> moves;

public:
	game_model(){};
    void makeMove(int pos, char player);
    void undoMove();
    char getWinner();
    bool isGameOver();
};

#endif