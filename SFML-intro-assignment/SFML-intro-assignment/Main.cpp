#include <iostream>
#include"SFML/System.hpp"
#include"SFML/Graphics.hpp"
#include"SFML\Window.hpp"
#include"SFML/Audio.hpp"
#include"SFML\Network.hpp"

#include "PhysicsBlackBox.h"

int main() {
	std::cout << "Hewwo\n";

	//Create the window
	sf::RenderWindow window(sf::VideoMode(800, 800), "Your first SFML program!", sf::Style::Default);
	window.setFramerateLimit(60);


	PendulumInformation pi;
	pi.angle1 = 3.14159265358979323846 / 2;
	pi.angle1P = 0;
	pi.angle2 = 0;
	pi.angle2P = 0;
	pi.gravity = -9.8;
	pi.length1 = 300;
	pi.length2 = 300;
	pi.mass1 = 10;
	pi.mass2 = 10;
	pi.pos1 = pi.length1 * sf::Vector2f(sin(pi.angle1), -cos(pi.angle1));
	pi.pos2 = pi.pos1 + pi.length2 * sf::Vector2f(sin(pi.angle2), -cos(pi.angle2));

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
		}

		//Remove previous frame
		window.clear();

		//UPDATE FRAME HERE

		//Display new frame
		window.display();
	}
	return 0;
}