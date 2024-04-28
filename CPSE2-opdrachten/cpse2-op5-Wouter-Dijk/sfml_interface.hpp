#ifndef SFML_INTERFACE_HPP
#define SFML_INTERFACE_HPP

#include "game_model.hpp"
#include <SFML/Graphics.hpp>

class sfml_interface{
public:
	sf::RenderWindow window;
	sf::Texture texture_x;
	sf::Texture texture_o;
	sf::Texture texture_win;
	sf::Texture texture_wit;
	sf::Texture texture_undo;
	sf::Sprite sprite_x;
	sf::Sprite sprite_o;
	sf::Sprite sprite_win;
	sf::Sprite sprite_wit;
	sf::Sprite sprite_undo;

public:
    sfml_interface(int width, int height, std::string title);

    void updateView(game_model& m);
	void showWinner(game_model& m);

};

#endif