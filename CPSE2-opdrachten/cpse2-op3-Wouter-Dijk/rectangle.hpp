#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "shape.hpp"


class rectangle : public shape{
private:
	sf::Vector2f end_position;
	sf::Color kleur;
	std::string color_txt;
	sf::RectangleShape rect;

public:
	rectangle(sf::Vector2f begin_position, sf::Vector2f end_position, sf::Color kleur, std::string color_txt);

	void draw( sf::RenderWindow & window ) override;

	bool interact( sf::Vector2f position ) override;

	std::string file_convert() override;

};

#endif