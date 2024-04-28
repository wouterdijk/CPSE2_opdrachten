#ifndef PICTURE_HPP
#define PICTURE_HPP

#include "shape.hpp"

class picture : public shape{
private:
	sf::Texture texture;
	sf::Sprite sprite;
	std::string filename;

public:
	picture(sf::Vector2f position, std::string filename);

	void draw( sf::RenderWindow & window )  override;

	bool interact( sf::Vector2f position ) override;

	std::string file_convert() override;

};

#endif