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
#
#include <set> // for STD::SET

using namespace std;

class Piece
{
public:
	// Constructor
	Piece(Position p, bool color, PieceType pt);
	Piece() {};

	void assignPos(Position pos);

	bool isWhite()
	{
		return fWhite;
	}

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

	bool ifSlide() { return canSlide; };

	struct RC {
		int row;
		int col;
	};

	PieceType getType() { return type; };
	virtual void draw(ogstream& gout) {};

protected:
	Position position;
	bool fWhite;
	int nMoves = 0;
	int lastMove = -1;
	PieceType type;
	bool canSlide;
};
