/***********************************************************************
 * Source File:
 *    ROOK : Handles the rook piece on the board.
 * Author:
 *    Emilio Ordonez and Austin Jesperson
 * Summary:
 *    A rook on the chess board.
 ************************************************************************/

#include "rook.h"

/****************************************************
 * DRAW
 * Draws the rook on the board
 ***************************************************/
void Rook::draw(ogstream& gout)
{
	gout.drawRook(position.getLocation(), fWhite);
}