#include "interface_controller_sfml.hpp"

bool interface_controller_sfml::interact( sf::Vector2f pos, bool player, int m_pos){
	if(view.sprite_wit.getGlobalBounds().contains(pos)){
		for(unsigned int k = 0 ; k < model.moves.size() ; k++){
			if(model.moves[k].pos == m_pos){
				return player;
			}
		}
		if(player){
			model.makeMove(m_pos ,'x');
			moveUndone = !moveUndone;
			return !player;
		}else{
			model.makeMove(m_pos ,'o');
			moveUndone = !moveUndone;
			return !player;
		}
	}
	return player;
}

void interface_controller_sfml::run(){
	bool player = true;
	while (view.window.isOpen()) {
		view.window.clear();
		if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
			sf::Vector2f position = sf::Vector2f(sf::Mouse::getPosition(view.window));
			if(view.sprite_undo.getGlobalBounds().contains(position) && !moveUndone){
				model.undoMove();
				player = !player;
				moveUndone = true;
			}else{
				for(int i = 0; i < 3; i++){
					view.sprite_wit.setPosition(10,160*i+10);
					player = interact(position, player, 3*i+1);
					view.sprite_wit.setPosition(170,160*i+10);
					player = interact(position, player, 3*i+2);
					view.sprite_wit.setPosition(330,160*i+10);
					player = interact(position, player, 3*i+3);
				}
			}
		}
	
		view.updateView(model);

		if(model.isGameOver()){
			view.showWinner(model);
		}

		view.window.display();

        sf::Event event;		
	    while( view.window.pollEvent(event) ){
			if( event.type == sf::Event::Closed ){
				view.window.close();
			}
		}	
	}	
}