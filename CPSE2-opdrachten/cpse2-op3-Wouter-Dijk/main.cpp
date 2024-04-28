#include <iostream>
#include <fstream>
#include <sstream>
#include <string.h>
#include <functional>
#include <string>
#include "circle.hpp"
#include "rectangle.hpp"
#include "line.hpp"
#include "picture.hpp"
#include "exceptions.hpp"

bool exists(const std::string& name) {
    if (FILE *file = fopen(name.c_str(), "r")) {
        fclose(file);
        return true;
    } else {
        return false;
    }   
}

sf::Color checkColor(const std::string& color_txt){
	if( color_txt == "Black"){
		return sf::Color::Black;
	} else if( color_txt == "White"){
		return sf::Color::White;
	} else if( color_txt == "Red"){
		return sf::Color::Red;
	} else if( color_txt == "Green"){
		return sf::Color::Green;
	} else if( color_txt == "Yellow"){
		return sf::Color::Yellow;
	} else if( color_txt == "Magenta"){
		return sf::Color::Magenta;
	} else if( color_txt == "Cyan"){
		return sf::Color::Cyan;
	} else if( color_txt == "Blue"){
		return sf::Color::Blue;
	}else{
		throw UnknownColorException(color_txt);
	}

}

void ifNumberCheck(std::string n){
	for(auto ch : n){
		if(!std::isdigit(ch)){
			throw NotNumberException(n);
		}
	}
}

shape* ObjectFactory( std::string info ){
	std::istringstream ss(info);
	std::string str_x, str_y, del, object, color_txt, diameter;
	sf::Color color;
		
	ss >> str_x >> str_y;
	ifNumberCheck(str_x);
	ifNumberCheck(str_y);
	
	ss >> object >> color_txt;

	sf::Vector2f pos(stof(str_x), stof(str_y));

	if( object == "CIRCLE" ){
		color = checkColor(color_txt); 
		ss >> diameter;
		ifNumberCheck(diameter);
		return new circle(pos, color, stoi(diameter), color_txt); 

	} else if( object == "RECTANGLE" ){
		color = checkColor(color_txt); 
		ss >> str_x >> str_y;
		ifNumberCheck(str_x);
		ifNumberCheck(str_y);
		return new rectangle(pos, sf::Vector2f{stof(str_x),stof(str_y)}, color, color_txt); 

	} else if( object == "LINE" ){
		color = checkColor(color_txt); 
		ss >> str_x >> str_y;
		ifNumberCheck(str_x);
		ifNumberCheck(str_y);
		return new line(pos, sf::Vector2f{stof(str_x),stof(str_y)}, color, color_txt); 

	} else if( object == "PICTURE" ){
		if (!exists(color_txt)){ 
			throw NoPictureFileException(color_txt);
		} 
		std::getline(ss, del, ' ');
		return new picture(pos, color_txt); //color is hier de filename voor het plaatje

	} 
	else { 
		throw UnknownFactoryException(object);
	}
	return nullptr;
} 


int main( int argc, char *argv[] ){
	sf::RenderWindow window{ sf::VideoMode{ 640, 480 }, "SFML window" };
	std::fstream file("objects.txt");
    std::string str;
	int lineNumb = 1;
	bool rewrite = true; 

	std::vector< shape *> objects = {};
	try{
		while (std::getline(file, str)){
			if(str == ""){
				throw NotLineException(std::to_string(lineNumb));
			}else{
				objects.push_back(ObjectFactory(str));
			}
			lineNumb++;
		}
	}catch (std::exception& e){
		rewrite = false;
		std::cerr << e.what() << " - Line Number: " << std::to_string(lineNumb) << std::endl;
	}

	while (window.isOpen()) {
		if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
			for( auto & p: objects ){
				sf::Vector2f position = sf::Vector2f(sf::Mouse::getPosition(window));
				if(p->interact(position)){
					p->move(sf::Vector2f(position));
					continue;
				}
			}
		}

		window.clear();

		for( auto & p : objects ){
         	p->draw( window );
      	}

		window.display();

        sf::Event event;		
	    while( window.pollEvent(event) ){
			if( event.type == sf::Event::Closed ){
				if(rewrite){
					std::ofstream ofs("objects.txt", std::ofstream::trunc);
					for( auto & p : objects ){
						std::string s = p->file_convert();
						ofs << s << "\n";
					}
					ofs.close();
				}
				window.close();
			}
		}	
	}
	return 0;
}