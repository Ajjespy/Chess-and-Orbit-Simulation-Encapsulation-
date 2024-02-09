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

class Piece
{
public:
	// Constructor
	Piece(int r, int c, bool color, PieceType pt)

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

	// in progress
	virtual void display(ogstream gout);
	virtual void getMoves();

protected:
	Position position;
	bool fWhite;
	int nMoves = 0;
	int lastMove;
	PieceType type;
};
