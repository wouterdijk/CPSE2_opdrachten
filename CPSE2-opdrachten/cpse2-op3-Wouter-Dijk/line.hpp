#ifndef LINE_HPP
#define LINE_HPP

#include "shape.hpp"


class line : public shape{
private:
	sf::Vector2f end_position;
	sf::Color kleur;
	std::string color_txt;
	sf::RectangleShape rect;

public:
	line(sf::Vector2f begin_position, sf::Vector2f end_position, sf::Color kleur, std::string color_txt);

	void draw( sf::RenderWindow & window ) override;

	bool interact( sf::Vector2f position ) override;

	std::string file_convert() override;

};

#endif