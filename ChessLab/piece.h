/***********************************************************************
 * Header File:
 *    PIECE : Handles each piece on the board.
 * Author:
 *    Emilio Ordonez
 * Summary:
 *    A piece on the chess board.
 ************************************************************************/
#pragma once
#include "position.h"
#include "uiDraw.h"

class Piece
{
public:
	// Constructor
	Piece(int r, int c, bool color);

	void assignPos(Position pos)
	{
		position = pos;
		nMoves++;
	}

	bool isWhite()
	{
		return fWhite;
	}

	// In progress
	bool isMove()
	{
		return true;
	}

	int getNMoves()
	{
		return nMoves;
	}

	Position getPosition()
	{
		return position;
	}

	// in progress
	bool justMoved()
	{
		return true;
	}

	// in progress
	virtual char getLetter();
	virtual void display(ogstream gout);
	virtual void getMoves();
	void assignPiece(Piece piece);

protected:
	Position position;
	bool fWhite;
	int nMoves;
	int lastMove;
};
