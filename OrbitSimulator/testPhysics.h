/***********************************************************************
 * Header File:
 *    Test Physics : Tests the Physics Engine
 * Author:
 *    Emilio Ordonez 
 * Summary:
 *    All the unit tests for Physics
 ************************************************************************/

#pragma once

#include <iostream>
#include <cstdlib>
#include "position.h"
#include "physics.h"
#include <cassert>

using namespace std;

/**********************************************
 * TEST Physics
 * Contains all the Physics Unit tests
 *********************************************/
class TestPhysics
{
public:
	void run()
	{
		firstCallbackLoop();
		secondCallbackLoop();
		thirdCallbackLoop();
		fourthCallbackLoop();
		fifthCallbackLoop();
		sixthCallbackLoop();
	}

private:
	// GPS First Callback loop
	void firstCallbackLoop() const
	{
		// setup
		double x = 0.0;
		double y;
		Position pos = Position(0.0, 42164000.0);
		Position vel = Position(3100, 0.0);
		Position acceleration = Position(0, 0);
		Physics engine;
		// exericse
		x, y = engine.calculations(pos, vel, acceleration);
		// verify
		assert(abs(x - (-148800.0)) < 0.1);
		assert(abs(y - 42163200.0) < 0.1);
	}

	// GPS Second Callback loop
	void secondCallbackLoop() const
	{
		//setup
		double x = 0.0;
		double y;
		Position pos = Position(-148800.0, 42163200);
		Position vel = Position(-3100, -10.7708);
		Position acceleration = Position(0, 0);
		Physics engine;
		// exercise
		x, y = engine.calculations(pos, vel, acceleration);
		// verify
		assert(abs(x - (- 297597.0)) < 0.1);
		assert(abs(y - 421619000.0) < 0.1);
	}

	// GPS Third callback Loop
	void thirdCallbackLoop() const
	{
		// setup
		double x = 0.0;
		double y;
		Position pos = Position(-297597, 42161900);
		Position vel = Position(-3099.96, -21.5415);
		Position acceleration = Position(0, 0);
		Physics engine;
		// exercise
		x, y = engine.calculations(pos, vel, acceleration);
		// verify
		assert(abs(x - (- 446390.0)) < 0.1);
		assert(abs(y - 42160100.0) < 0.1);
	}

	// GPS Fourth Callback Loop
	void fourthCallbackLoop() const 
	{
		// setup
		double x = 0.0;
		double y;
		Position pos = Position(-446390, 42160100);
		Position vel = Position(-3099.89, -32.312);
		Position acceleration = Position(0, 0);
		Physics engine;
		// excersise
		x, y = engine.calculations(pos, vel, acceleration);
		// verify
		assert(abs(x - (-595176)) < 0.1);
		assert(abs(y - 42157800) < 0.1);
	}

	// GPS Fifth Callback Loop
	void fifthCallbackLoop() const
	{
		// setup
		double x = 0.0;
		double y;
		Position pos = Position(-595176, 42157800);
		Position vel = Position(-3099.77, -43.0822);
		Position acceleration = Position(0, 0);
		Physics engine;
		// exercise
		x, y = engine.calculations(pos, vel, acceleration);
		// verify
		assert(abs(x -  (- 743954)) < 0.1);
		assert(abs(y - 42155000) < 0.1);
	}

	// GPS Sixth Callback Loop
	void sixthCallbackLoop() const
	{
		// setup
		double x = 0.0;
		double y;
		Position pos = Position(-743954, 42155000);
		Position vel = Position(-3099.62, -53.8519);
		Position acceleration = Position(0, 0);
		Physics engine;
		// exercise
		x, y = engine.calculations(pos, vel, acceleration);
		// verify
		assert(abs(x - (- 892722)) < 0.1);
		assert(abs(y - 42151600) < 0.1);
	}

};
