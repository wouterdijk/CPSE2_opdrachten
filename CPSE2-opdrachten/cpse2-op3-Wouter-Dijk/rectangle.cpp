#include "rectangle.hpp"

rectangle::rectangle(sf::Vector2f begin_position, sf::Vector2f end_position, sf::Color kleur, std::string color_txt):
	shape(begin_position),
	end_position(end_position),
	kleur(kleur),
	color_txt(color_txt)
{
	rect.setFillColor(kleur);
	rect.setPosition(begin_position);
	size = end_position - begin_position;
	rect.setSize(size);
}

void rectangle::draw( sf::RenderWindow & window ){
	rect.setPosition(pos);
	window.draw(rect);
}

bool rectangle::interact( sf::Vector2f position ){
	if(rect.getGlobalBounds().contains(sf::Vector2f(position))){
		return true;
	}
	return false;
}

std::string rectangle::file_convert(){
	std::string string;
	string = std::to_string(int(rect.getPosition().x)) + " " + std::to_string(int(rect.getPosition().y)) + " RECTANGLE " + color_txt + " "
	 + std::to_string(int(rect.getPosition().x + rect.getSize().x)) + " " + std::to_string(int(rect.getPosition().y + rect.getSize().y));
	return string;	
}
