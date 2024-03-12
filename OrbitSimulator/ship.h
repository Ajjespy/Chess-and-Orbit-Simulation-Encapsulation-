/***********************************************************************
 * Heaader File:
 *    Ship : Entity
 * Author:
 *    Austin Jesperson
 * Summary:
 *    The ship Dream Chaser controlled by the user.
 ************************************************************************/
#pragma once
#include "entity.h"
#include "bullet.h"

class Ship : public Entity
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

	Bullet fire()
	{
		Bullet bullet;
		return bullet;
	}

private:
	

};
