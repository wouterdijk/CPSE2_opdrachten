#include "circle.hpp"

circle::circle( sf::Vector2f position , sf::Color kleur, float diameter, std::string color_txt):
	shape( position ),
	kleur( kleur ),
	diameter( diameter ),
	color_txt( color_txt )
{
	c.setFillColor(kleur);
	size = sf::Vector2f(diameter, diameter);
	c.setRadius(diameter/2);
}

void circle::draw( sf::RenderWindow & window ) {
	c.setPosition(pos);
	window.draw(c);
}

bool circle::interact( sf::Vector2f pos ){
	if(c.getGlobalBounds().contains(sf::Vector2f(pos))){
		return true;
	}
	return false;
}

std::string circle::file_convert(){
	std::string s;
	s = std::to_string(int(pos.x)) + " " + std::to_string(int(pos.y)) + " CIRCLE " + color_txt + " " + std::to_string(int(diameter));
	return s;
}