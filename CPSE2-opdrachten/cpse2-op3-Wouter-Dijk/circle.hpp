#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "shape.hpp"

class circle : public shape{
private:
	sf::Color kleur;
	float diameter;
	std::string color_txt;
	sf::CircleShape c;

public:
	circle( sf::Vector2f position, sf::Color kleur, float diameter, std::string color_txt);

	void draw( sf::RenderWindow & window ) override;

	bool interact( sf::Vector2f position ) override;

	std::string file_convert() override;

};

#endif
