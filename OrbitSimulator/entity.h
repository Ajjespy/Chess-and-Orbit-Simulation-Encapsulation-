/***********************************************************************
 * Heaader File:
 *    Entity
 * Author:
 *    Austin Jesperson
 * Summary:
 *    An Entity in our simulation.
 ************************************************************************/

#pragma once
#include "position.h"
#include "cmath"
#include "uiDraw.h"

using namespace std;

double PI = 3.14159265358979;

class Entity
{
public:
	Entity()
	{
		angle = 0.0;
		radius = 0.0;
		Position start;
		start.setPixelsX(-450);
		start.setPixelsY(450);
		position = start; 
		velocity = Position();
		acceleration = Position(); 
	}

	void rotate(double a) {angle += a;}
	double getAngle() { return angle; }
	double getRadius() { return radius; }
	Position getPosition() { return position; }
	Position getVelocity() { return velocity; }
	Position getAcceleration() { return acceleration; }

	//In Progress
		//Check like positions for collisions
	bool operator == (const Entity& rhs) const { return (position == rhs.position);}

		//function move(), handle movement with Physics, need to look at naming with ship's function
	void moves();

		//Virtual function for drawing, TBD by child classes
	virtual void draw(ogstream& gout) {};

		//Virtual function for collisions
		//Need to return new entities
	/*virtual Entity collide()
	{ 
		Entity entity;  
		return entity;
	};*/

protected:
	double angle;
	double radius;
	Position position;
	Position velocity;
	Position acceleration;
};
