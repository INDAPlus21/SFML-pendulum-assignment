#include <iostream>
#include"SFML/System.hpp"
#include"SFML/Graphics.hpp"
#include"SFML\Window.hpp"
#include"SFML/Audio.hpp"
#include"SFML\Network.hpp"

int main() {
	std::cout << "Hewwo\n";

	//Create the window
	sf::RenderWindow window(sf::VideoMode(800, 800), "Your first SFML program!", sf::Style::Default);

	//Create the things to show on screen
	//A sf::Color represents a colour. You can use a built in colour (like below) or create your own with sf::Color(222, 49, 99) that uses RGB values
	sf::Color backgroundColor = sf::Color::Magenta;

	//A sf::Vector2f is a struct that contains two floats, like a two dimensional vector
	sf::Vector2f position(200.f, 200.f);
	float radius = 50.f;
	//A sf::CircleShape represents a circle, which is stuff like position, radius, color, and other things.
	sf::CircleShape circle(radius);
	//Beware: the position of the shape is at the top left of it
	circle.setPosition(position);
	circle.setFillColor(sf::Color::Green);
	//For more information, see this website: https://www.sfml-dev.org/documentation/2.5.1/classsf_1_1CircleShape.php

	//A sf::RectangleShape represents a rectangle, which is stuff like, position, width, height, color, rotation, and other things
	sf::RectangleShape rectangle(sf::Vector2f(100.f, 50.f));
	//You can add two vectors
	rectangle.setPosition(position + sf::Vector2f(-50.f, 100.f));
	rectangle.setFillColor(sf::Color::Cyan);
	//You can find more information if you click around on this website:  https://www.sfml-dev.org/


	//Update loop
	while (window.isOpen()) {

		//See if the user has done something since last frame
		sf::Event event;
		while (window.pollEvent(event)) {
			//Check what the user has done
			switch (event.type) {
				//See if the user has tried to close the window
			case sf::Event::EventType::Closed:
				window.close();
				break;
				//See if the user has pressed a key
			case sf::Event::EventType::KeyPressed:
				//See what key the user has pressed
				switch (event.key.code) {
					//Do something if the user has pressed W
				case sf::Keyboard::W:
					radius++;
					circle.setRadius(radius);
					break;
				}
				break;
			}

		}

		//Remove previous frame
		window.clear(backgroundColor);

		//Draw things to frame
		window.draw(circle);
		window.draw(rectangle);

		//Display new frame
		window.display();
	}


	return 0;
}