/***********************************************************************
 * Header File:
 *    BISHOP : Handles the bishop piece on the board
 * Author:
 *    Emilio Ordonez and Austin Jesperson
 * Summary:
 *    A bishop on the board. 
 ************************************************************************/
#include "piece.h"
#pragma once

class Bishop : public Piece
{
public:
	Bishop(Position pos, bool color, PieceType pt = BISHOP)
	{
		position = pos;
		fWhite = color;
		type = pt;
		possibleDirections = 4;
		canSlide = true;
	}

	RC* getDirections()
	{
		RC* moves = new RC[4]{
		   {-1,  1}, {1,  1},
		   {-1, -1}, {1, -1}
		};

		return moves;
	}

	void draw(ogstream& gout);
};
