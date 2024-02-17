/***********************************************************************
 * Header File:
 *    KING : Handles a king piece on the board
 * Author:
 *    Emilio Ordonez and Austin Jesperson
 * Summary:
 *    A king on the chess board.
 ************************************************************************/
#include "piece.h"
#pragma once

class King : public Piece
{
public:
	King(Position pos, bool color, PieceType pt = KING)
	{
		position = pos;
		fWhite = color;
		type = pt;
		possibleDirections = 8;
	}

	RC* getDirections()
	{
		RC* moves = new RC[8]
		{
		   {-1,  1}, {0,  1}, {1,  1},
		   {-1,  0},          {1,  0},
		   {-1, -1}, {0, -1}, {1, -1}
		};

		return moves;
	}

	void draw(ogstream& gout);
};
