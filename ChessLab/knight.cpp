/***********************************************************************
 * Source File:
 *    KNIGHT : Handles the knight piece on the board
 * Author:
 *    Emilio Ordonez and Austin Jespeson
 * Summary:
 *    A knight on the board. 
 ************************************************************************/

 #include "knight.h"

 void Knight::draw(ogstream& gout)
{
	gout.drawKnight(position.getLocation(), fWhite);
}