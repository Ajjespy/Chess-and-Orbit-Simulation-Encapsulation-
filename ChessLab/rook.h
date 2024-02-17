/***********************************************************************
 * Header File:
 *    ROOK : Handles the rook piece on the board
 * Author:
 *    Emilio Ordonez and Austin Jesperson
 * Summary:
 *    A rook on the chess board.
 ************************************************************************/

#include "piece.h"
#pragma once

using namespace std;

class Rook : public Piece
{
public:
	Rook(Position pos, bool color, PieceType pt = ROOK)
	{
		position = pos;
		fWhite = color;
		type = pt;
		canSlide = true;
		possibleDirections = 4;
	}
	
	void draw(ogstream& gout);

	RC* getDirections()
	{
		RC* moves = new RC[4]{
			{0, 1},
			{-1, 0},
			{1, 0},
			{0, -1}
		};

		return moves;
	}
	
private:
};
