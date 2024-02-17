/***********************************************************************
 * Header File:
 *    KNIGHT : Handles the knight piece on the board
 * Author:
 *    Emilio Ordonez and Austin Jesperson
 * Summary:
 *    A knight on the board. 
 ************************************************************************/

#include "piece.h"
#pragma once

class Knight : public Piece
{
public:
	Knight(Position pos, bool color, PieceType pt = KNIGHT)
	{
		position = pos;
		fWhite = color;
		type = pt;
		possibleDirections = 8;
	}

	void draw(ogstream& gout);
	
	RC* getDirections()
	{
		RC* moves = new RC[8]
		{
				 {-1,  2}, { 1,  2},
		{-2,  1},                    { 2,  1},
		{-2, -1},                    { 2, -1},
				 {-1, -2}, { 1, -2}
		};

		return moves;
	}
};
