/***********************************************************************
 * Source File:
 *    Piece Test : Unit tests for the Piece class
 * Author:
 *    Emilio Ordonez and Austin Jesperson
 * Summary:
 *    The unit tests for Piece
 ************************************************************************/

#include "testPiece.h"
#include "piece.h"
#include <cassert>

/**************************************
 * Constructor (White)
***************************************/
void PieceTest::constructorWhite() const
{
	// SETUP
	// EXERCISE
	Piece pawn = new Piece(2, 0, true);
	// VERIFY 
	assert(pawn.getPosition().getRow() == 2);
	assert(pawn.getPosition().getColumn() == 0);
	assert(pawn.isWhite() == true);
	assert(pawn.hasMoved() == false);
}

/***************************************
 * Constructor (Black)
****************************************/
void PieceTest::constructorBlack() const
{
	// SETUP
	// EXERCISE
	Piece p = new Piece(7, 0, false);
	// VERIFY 
	assert(p.getPosition().getRow() == 7);
	assert(p.getPosition().getColumn() == 0);
	assert(p.isWhite() == false);
	assert(p.hasMoved() == false);
}

/****************************************
 * Move piece
*****************************************/
void PieceTest::assignPos() const
{
	// SETUP
	Piece p = new Piece(2, 0, true); // white pawn at location 8
	Poistion pos = new Position();
	pos.set(4, 0);
	// EXERCISE
	p.assign(pos);
	// VERIFY
	assert(p.getPosition().getRow() == 4);
	assert(p.getPosition().getColumn() == 0);
	assert(p.isWhite() == true);
	assert(p.hasMoved() == true);
}

/***************************************
* Move piece to out of bounds position
****************************************/
void PieceTest::invalidPos() const
{
	// SETUP
	Piece p = new Piece(2, 0, true); //white pawn at location 8
	Position pos = new Position();
	pos.set(20, 15);
	// EXERCISE
	p.assign(pos);
	// VERIFY
	assert(p.getPosition().getRow() == 2);
	assert(p.getPosition().getRow() == 0);
	assert(p.isWhite() == true);
	assert(p.hasMoved() == false);
}

/*****************************************
 * Piece is keeping track of moves
******************************************/
void PieceTest::keepTrackofMoves() const
{
	// SETUP
	Piece p = new Piece(2, 0, true);
	Position pos1 = new Position();
	Position pos2 = new Position();
	Position pos3 = new Position();
	pos1.set(3, 0);
	pos2.set(4, 0);
	pos3.set(5, 0);
	// EXERCISE
	p.assign(pos1);
	p.assign(pos2);
	p.assign(pos3);
	// VERIFY
	assert(p.getNmoves() == 3);
	assert(p.hasMoved() == true);
}
