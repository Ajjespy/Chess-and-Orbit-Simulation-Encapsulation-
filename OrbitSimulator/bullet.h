/***********************************************************************
 * C++ File:
 *    Bullet
 * Author:
 *    Austin Jesperson
 * Summary:
 *    A bullet to be fired from our ship
 ************************************************************************/


#pragma once
#include "entity.h"

class Bullet : public Entity
{
public:
	Bullet() 
	{ 
		Entity(); 
		timeStart = 0.0;
		lifeSpan = 20.0;
	}
	//In Progress
		//Make contructor that takes angle, position, and velocity and sets the correct calculated starting position)
	//Bullet(Position p, Position v, )

	bool operator <  (const Bullet& rhs)   const { return timeStart < rhs.timeStart; }
	bool operator >  (const Bullet& rhs)   const { return timeStart > rhs.timeStart; }

private:
	double timeStart;
	double lifeSpan;
};