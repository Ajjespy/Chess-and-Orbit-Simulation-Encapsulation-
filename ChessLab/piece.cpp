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
	if (pos.getRow() > 8 || pos.getRow() < 1)
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
Piece::Piece(int r, int c, bool color, PieceType pt)
{
	position = Position(r, c);
	fWhite = color;
	type = pt
}

/**************************************
* PIECE : DISPLAY
***************************************/
void Piece::display(ogstream gout)
{
	// in progress
}

/******************************************
* PIECE : GETMOVES
*******************************************/
void Piece::getMoves()
{
	// in progress
}