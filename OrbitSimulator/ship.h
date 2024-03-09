/***********************************************************************
 * Heaader File:
 *    Ship : Entity
 * Author:
 *    Austin Jesperson
 * Summary:
 *    The 
 ************************************************************************/
#pragma once
#include "position.h"
#include "cmath"

using namespace std;

double PI = 3.14159265358979;

class Ship
{
public:
	Ship() 
	{
		angle = (PI / 2.0);
		radius = 10.0;
		Position start;
		start.setPixelsX(-450);
		start.setPixelsY(450);
		position = start;
		velocity = Position(0.0, -2000.0);
		acceleration = Position();
	}

	void rotate(double a)
	{
		angle += a;
	}

	void thrust() 
	{
		acceleration.setMetersX(2.0 * cos(angle - (PI / 2.0))); 
		acceleration.setMetersY(2.0 * sin(angle - (PI / 2.0))); 
	}

	void stopThrust() 
	{
		acceleration.setMetersX(0.0);
		acceleration.setMetersY(0.0);
	}

	void move(bool isLeft, bool isRight, bool isDown)
	{
		if (isLeft && !isRight)
		{
			rotate(-.1);
		}

		if (!isLeft && isRight)
		{
			rotate(.1);
		}

		if (isDown)
		{
			thrust();
		}

		if (!isDown)
		{
			stopThrust();
		}
	}

	double getAngle() { return angle; }
	double getRadius() { return radius; }
	Position getPosition() { return position; }
	Position getVelocity() { return velocity; }
	Position getAcceleration() { return acceleration; }

private:
	double angle;
	double radius;
	Position position;
	Position velocity;
	Position acceleration;

};
