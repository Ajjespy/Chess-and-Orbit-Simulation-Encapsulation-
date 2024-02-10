/***********************************************************************
 * Source File:
 *    KING : Handles a king piece on the board
 * Author:
 *    Emilio Ordonez and Austin Jesperson
 * Summary:
 *    A king on the board.
 ************************************************************************/

#include "king.h"

void King::draw(ogstream& gout)
{
	gout.drawKing(position.getLocation(), fWhite);
}