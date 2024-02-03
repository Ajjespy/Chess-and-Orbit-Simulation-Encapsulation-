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
* PIECE : CONSTRUCTOR
***************************************/
Piece::Piece(int r, int c, bool color)
{
	position = Position(r, c);
	fWhite = color;
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