#pragma once
#include "SFML/Graphics.hpp";

struct PendulumInformation {
	//How much each mass weighs, the first being the one connected to the origin
	int mass1;
	int mass2;

	//Centerpositions of the masses
	sf::Vector2f pos1;
	sf::Vector2f pos2;

	//Angle of the first arm. 0 means straight down, and it increases counter-clockwise
	float angle1;
	//Derivative of the first angle, don't mind this
	float angle1P;
	//Same as above but for the second arm
	float angle2;
	float angle2P;

	//Length of the arms, first being connected to the origin
	float length1;
	float length2;

	//Gravitational acceleration, 9.82 here in Sweden
	float gravity;
};

//Don't mind this, not important for you
struct PendulumInformationDerivative{
	sf::Vector2f pos1P;
	sf::Vector2f pos2P;

	float angle1P;
	float angle2P;
	float angle1PP;
	float angle2PP;
};

void Next(PendulumInformation& pi, float time);




