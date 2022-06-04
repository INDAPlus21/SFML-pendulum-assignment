#include "PhysicsBlackBox.h"
#include <cmath>


//You should not need to alter this code, talk to me if there are any problems

void Next(PendulumInformation& pi, const float time) {
	const int n = 10;
	float h = time / n;

	float t0 = 0;

	for (size_t i = 0; i < n; i++)
	{
		PendulumInformationDerivative k1 = Step(pi,k1,h);

		//k2 calculation
		PendulumInformation tempK2 = pi;
		tempK2.angle1 += k1.angle1P * h / 2.f;
		tempK2.angle2 += k1.angle2P * h / 2.f;
		tempK2.angle1P += k1.angle1PP * h / 2.f;
		tempK2.angle2P += k1.angle2PP * h / 2.f;

		tempK2.pos1 += k1.pos1P * h / 2.f;
		tempK2.pos2 += k1.pos2P * h / 2.f;
		PendulumInformationDerivative k2 = Step(tempK2, k1, h);

		//k3 calculation
		PendulumInformation tempK3 = pi;
		tempK3.angle1 += k2.angle1P * h / 2.f;
		tempK3.angle2 += k2.angle2P * h / 2.f;
		tempK3.angle1P += k2.angle1PP * h / 2.f;
		tempK3.angle2P += k2.angle2PP * h / 2.f;

		tempK3.pos1 += k2.pos1P * h / 2.f;
		tempK3.pos2 += k2.pos2P * h / 2.f;
		PendulumInformationDerivative k3 = Step(tempK3, k1, h);

		//k4 calculation
		PendulumInformation tempK4 = pi;
		tempK4.angle1 += k3.angle1P * h;
		tempK4.angle2 += k3.angle2P * h;
		tempK4.angle1P += k3.angle1PP * h;
		tempK4.angle2P += k3.angle2PP * h;

		tempK4.pos1 += k3.pos1P * h;
		tempK4.pos2 += k3.pos2P * h;
		PendulumInformationDerivative k4 = Step(pi, k1, h);


		//Actual calculation
		pi.angle1 += h * (k1.angle1P + 2 * (k2.angle1P + k3.angle1P) + k4.angle1P);
		pi.angle2 += h * (k1.angle2P + 2 * (k2.angle2P + k3.angle2P) + k4.angle2P);
		pi.angle1P += h * (k1.angle1PP + 2 * (k2.angle1PP + k3.angle1PP) + k4.angle1PP);
		pi.angle2P += h * (k1.angle2PP + 2 * (k2.angle2PP + k3.angle2PP) + k4.angle2PP);

		pi.pos1 = pi.length1 * sf::Vector2f(sin(pi.angle1), -cos(pi.angle1));
		pi.pos2 = pi.pos1 + pi.length2 * sf::Vector2f(sin(pi.angle2), -cos(pi.angle2));
		t0 += h;
	}



}

PendulumInformationDerivative Step(PendulumInformation& pi, PendulumInformationDerivative& k1, float h) {
	k1.angle1P = pi.angle1P;
	k1.angle2P = pi.angle2P;

	k1.angle1PP = (-pi.gravity * (2 * pi.mass1 + pi.mass2) * sin(pi.angle1) - pi.mass2 * pi.gravity * sin(pi.angle1 - 2 * pi.angle2) - 2 * sin(pi.angle1 - pi.angle2) * pi.mass2 * (pi.angle2P * pi.angle2P * pi.length2 + pi.angle1P * pi.angle1P * pi.length1 * cos(pi.angle1 - pi.angle2))) /
		(pi.length1 * 2 * pi.mass1 + pi.mass2 - pi.mass2 * cos(2 * pi.angle1 - 2 * pi.angle2));
	k1.angle2PP = (2 * sin(pi.angle1 - pi.angle2) * (pi.angle1P * pi.angle1P * pi.length1 * (pi.mass1 + pi.mass2) + pi.gravity * (pi.mass1 + pi.mass2) * cos(pi.angle1) + pi.angle2P * pi.angle2P * pi.length2 * pi.mass2 * cos(pi.angle1 - pi.angle2))) /
		(pi.length2 * (2 * pi.mass1 + pi.mass2 - pi.mass2 * cos(2 * pi.angle1 - 2 * pi.angle2)));

	k1.pos1P = sf::Vector2f(pi.angle1P * pi.length1 * cos(pi.angle1), pi.angle1P * pi.length1 * sin(pi.angle1));
	k1.pos2P = sf::Vector2f(pi.angle1P * pi.length1 * cos(pi.angle1) + pi.angle2P * pi.length2 * cos(pi.angle2), 
							pi.angle1P * pi.length1 * sin(pi.angle1) + pi.angle2P * pi.length2 * sin(pi.angle2));

	return k1;
}