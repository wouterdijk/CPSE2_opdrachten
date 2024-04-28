#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <SFML/Graphics.hpp>
#include <iostream>

class shape{
protected:
	sf::Vector2f pos;
	sf::Vector2f size;
public:
	shape(sf::Vector2f pos): 
		pos(pos)
	{}

	virtual void draw( sf::RenderWindow & window ) = 0;
	virtual void move(sf::Vector2f position){
		pos = sf::Vector2f( position.x - (size.x / 2), position.y - (size.y / 2));
	};
	virtual bool interact(sf::Vector2f position) = 0;
	virtual std::string file_convert() = 0;
};

#endif