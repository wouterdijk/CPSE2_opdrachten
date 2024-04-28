#include "interface_controller_sfml.hpp"
#include "sfml_interface.hpp"

#include "interface_controller_text.hpp"
#include "text_interface.hpp"

int main() {
	game_model model;
    
    // // Run SFML graphical version
    sfml_interface sfmlView(490, 590, "SFML window" );
    interface_controller_sfml controller(model, sfmlView);
	controller.run();

    // //Run text-only version
	// text_interface textView;
	// interface_controller_text controller(model, textView);
	// bool player = true;
    // while (!model.isGameOver()) {
    //     textView.updateView(model);
    //     player = controller.handleInput(player);
    // }
	// textView.updateView(model);
	// textView.showWinner(model);

    return 0;
}