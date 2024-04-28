#include "picture.hpp"

picture::picture(sf::Vector2f position, std::string filename):
	shape(position),
	filename( filename )
{
	if(texture.loadFromFile( filename )){
		sprite.setTexture( texture );
		sprite.setScale(0.06,0.06);
		sprite.setPosition(position);
	}
	size.x = sprite.getGlobalBounds().width;
	size.y = sprite.getGlobalBounds().height;
}

void picture::draw( sf::RenderWindow & window ){
	sprite.setPosition(pos);
	window.draw(sprite);
}

bool picture::interact( sf::Vector2f pos ){
	if(sprite.getGlobalBounds().contains(sf::Vector2f(pos))){
		return true;
	}
	return false;
}

std::string picture::file_convert(){
	std::string s;
	s = std::to_string(int(pos.x)) + " " + std::to_string(int(pos.y)) + " PICTURE " + filename;
	return s;
}