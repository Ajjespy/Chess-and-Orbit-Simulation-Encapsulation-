/***********************************************************************
 * Source File:
 *    BISHOP : Handles the bishop piece on the board
 * Author:
 *    Emilio Ordonez and Austin Jesperson
 * Summary:
 *    A bishop on the board. 
 ************************************************************************/
#include "bishop.h"

void Bishop::draw(ogstream& gout)
{
	gout.drawBishop(position.getLocation(), fWhite);
}