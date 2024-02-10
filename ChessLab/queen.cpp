/***********************************************************************
 * Source File:
 *    QUEEN : Handles a queen on the board
 * Author:
 *    Emilio Ordonez and Austin Jesperson
 * Summary:
 *    A queen on the board.
 ************************************************************************/
 #include "queen.h"

 void Queen::draw(ogstream& gout)
{
	gout.drawQueen(position.getLocation(), fWhite);
}