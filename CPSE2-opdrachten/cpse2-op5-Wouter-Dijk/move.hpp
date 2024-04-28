#ifndef MOVE_HPP
#define MOVE_HPP

class move{
public:
	int pos;
	char player;

public:
	move(int pos, char player):
		pos(pos),
		player(player)
	{}
};

#endif