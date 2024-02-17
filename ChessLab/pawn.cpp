/***********************************************************************
 * Source File:
 *    PAWN : Handles a pawn on the board
 * Author:
 *    Austin Jesperson
 * Summary:
 *    A pawn on the chess board.
 ************************************************************************/

#include "pawn.h"

void Pawn::draw(ogstream& gout)
{
	gout.drawPawn(position.getLocation(), fWhite);
}