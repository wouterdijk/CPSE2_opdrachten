#include "line.hpp"
#include <math.h>
#include <cmath>

line::line(sf::Vector2f begin_position, sf::Vector2f end_position, sf::Color kleur, std::string color_txt):
	shape(begin_position),
	end_position(end_position),
	kleur(kleur),
	color_txt(color_txt)
{
	rect.setFillColor(kleur);
	rect.setSize( sf::Vector2f(sqrt(pow((end_position.x - pos.x),2) + pow((end_position.y - pos.y),2)) , 1 ));
	rect.setRotation( atan2(pos.y - end_position.y , pos.x - end_position.x) * 180 / 3.14 - 180);
	rect.setPosition(begin_position);
	size = end_position - pos;
}

void line::draw( sf::RenderWindow & window ){
	rect.setPosition(pos);
	window.draw(rect);
}

bool line::interact( sf::Vector2f position ){
	if(rect.getGlobalBounds().contains( sf::Vector2f(position))){
		return true;
	}
	return false;
}

std::string line::file_convert(){
	std::string s;
	s = std::to_string(int(rect.getPosition().x)) + " " + std::to_string(int(rect.getPosition().y)) + " LINE " + color_txt + " "
	 + std::to_string(int(rect.getPosition().x + size.x)) + " " + std::to_string(int(rect.getPosition().y + size.y));
	return s;		
}