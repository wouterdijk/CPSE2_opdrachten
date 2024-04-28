#include "sfml_interface.hpp"
#include <iostream>

sfml_interface::sfml_interface(int width, int height, std::string title):
	window(sf::VideoMode(width,height), title)
{
	if(texture_x.loadFromFile( "Plaatje_X.png" )){
		sprite_x.setTexture( texture_x );
		sprite_x.setScale(1.5,1.5);
	}
	if(texture_o.loadFromFile( "Plaatje_O.png" )){
		sprite_o.setTexture( texture_o );
		sprite_o.setScale(1.5,1.5);
	}
	if(texture_wit.loadFromFile( "Plaatje_Wit.png" )){
		sprite_wit.setTexture( texture_wit );
		sprite_wit.setScale(1.5,1.5);
	}
	if(texture_win.loadFromFile( "Plaatje_Win.jpg" )){
		sprite_win.setTexture( texture_win );
		sprite_win.setScale(1.32,1.75);
		sprite_win.setPosition(0,0);
	}
	if(texture_undo.loadFromFile( "Plaatje_Undo.jpg" )){
		sprite_undo.setTexture( texture_undo );
		sprite_undo.setScale(0.5,0.5);
		sprite_undo.setPosition(0,490);
	}
}

void sfml_interface::updateView(game_model& m){
	std::vector<sf::Sprite> temp = {sprite_wit, sprite_wit, sprite_wit, sprite_wit, sprite_wit, sprite_wit, sprite_wit, sprite_wit, sprite_wit};
	for(unsigned int k=0 ; k < m.moves.size() ; k++){
		if(m.moves[k].player == 'x'){
			temp[m.moves[k].pos - 1] = sprite_x;
		}else{
			temp[m.moves[k].pos - 1] = sprite_o;
		}
	}

	window.draw(sprite_undo);

	for(int i = 0; i < 3; i++){
		temp[3*i].setPosition(10,160*i+10);
		window.draw(temp[3*i]);
		temp[3*i+1].setPosition(170,160*i+10);
		window.draw(temp[3*i+1]);
		temp[3*i+2].setPosition(330,160*i+10);
		window.draw(temp[3*i+2]);
	} 
}

void sfml_interface::showWinner(game_model& m){
	window.draw(sprite_win);
	char winner = m.getWinner();
	if(winner == 'x'){
		sprite_x.setPosition(168,30);
		window.draw(sprite_x);	
	}else if(winner == 'o'){
		sprite_o.setPosition(168,30);
		window.draw(sprite_o);		
	}
}