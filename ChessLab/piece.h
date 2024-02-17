/***********************************************************************
 * Header File:
 *    PIECE : Handles each piece on the board.
 * Author:
 *    Emilio Ordonez
 * Summary:
 *    A piece on the chess board.
 ************************************************************************/
#pragma once
#include "position.h"
#include "uiDraw.h"
#include "pieceType.h"
#include "rc.h"
#include <set> // for STD::SET

using namespace std;

class Piece
{
public:
	// Constructor
	Piece(Position p, bool color, PieceType pt);
	Piece() {};

	bool isBlack()
	{
		return fWhite;
	}

	void assignPos(Position pos);

	// In progress
	bool isMove()
	{
		return true;
	}

	int getNMoves()
	{
		return nMoves;
	}

	Position getPosition()
	{
		return position;
	}

	// in progress
	bool hasMoved()
	{
		if (nMoves > 0)
		{
			return true;
		}
		return false;
	}

	bool isValid()
	{
		if (type == SPACE)
		{
			return false;
		}
		return true;
	}

	virtual RC* getDirections()
	{
		RC* moves = new RC[4]{
			{0, 1},
			{-1, 0},
			{1, 0},
			{0, -1}
		};

		return moves;
	}

	bool ifSlide() { return canSlide; };

	virtual void draw(ogstream& gout) {};

	int getLengthOfDirections()
	{
		return possibleDirections;
	}

	PieceType getType()
	{
		return type;
	}
	
	const Piece& operator = (const Piece& rhs)
	{
		Position position = rhs.position;
		bool fWhite = rhs.fWhite;
		int nMoves = rhs.nMoves;
		PieceType type = rhs.type;
		bool canSlide = rhs.canSlide;
		int possibleDirections = rhs.possibleDirections;
	}

protected:
	Position position;
	bool fWhite = false; // false is equal to white, true is equal to black
	int nMoves = 0;
	PieceType type = SPACE;
	bool canSlide = false;
	int possibleDirections = 4;

};
