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
	Knight(Position pos, bool color)
	{
		position = pos;
		fWhite = color;
	}
};
