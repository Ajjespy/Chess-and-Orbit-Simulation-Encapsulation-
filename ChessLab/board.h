/***********************************************************************
 * Header File:
 *    BOARD : Handles the board.
 * Author:
 *    Emilio Ordonez
 * Summary:
 *    A chess board.
 ************************************************************************/
#pragma once
#include "uiDraw.h"
#include "piece.h"
#include "move.h"

class Board
{
public:
	Board();

	int getCurrentMove()
	{
		return currentMove;
	}

	bool whiteTurn()
	{
		return true;
	}

	void display(Position posHover, Position posSel);
	Piece get(Position pos);
	void free();
	void reset();
	void empty();
	void clear();
	void move(Move move);
	void assign(Position pos, Piece p);

private:
	Piece board[64];
	int currentMove;
	ogstream gout;
	
	void swap(Position pos1, Position pos2);
	void assertBoard();
};
