/***********************************************************************
 * Source File:
 *    PIECE : Keep track of each piece on the board
 * Author:
 *    Emilio Ordonez 
 * Summary:
 *    All the pieces on the board. 
 ************************************************************************/

#include "piece.h"

/**************************************
* PIECE : ASSIGN POS
***************************************/
void Piece::assignPos(Position pos)
{
	if (pos.getRow() > 7 || pos.getRow() < 0)
	{
		return;
	}
	else if (pos.getCol() > 7 || pos.getCol() < 0)
	{
		return;
	}
	position = pos;
	nMoves++;
}

/**************************************
* PIECE : CONSTRUCTOR
***************************************/
Piece::Piece(Position p, bool color, PieceType pt)
{
	position = p;
	fWhite = color;
	type = pt;
	canSlide = false;
}