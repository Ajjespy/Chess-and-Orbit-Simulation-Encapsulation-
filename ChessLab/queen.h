/***********************************************************************
 * Header File:
 *    QUEEN : Handles a queen on the board
 * Author:
 *    Emilio Ordonez and Austin Jesperson
 * Summary:
 *    A queen on the board.
 ************************************************************************/

#include "piece.h"
#pragma once

class Queen : public Piece
{
public:
	Queen(Position pos, bool color, PieceType pt = QUEEN)
	{
		position = pos;
		fWhite = color;
		type = pt;
		canSlide = true;
	}

	void draw(ogstream& gout);

	RC* getDirections()
	{
		RC* moves = new RC[8]{
			{-1,  1},
			{0,  1},
			{1,  1},
			{-1,  0},
			{1,  0},
			{-1, -1},
			{0, -1},
			{1, -1}
		};

		return moves;
	}
};
