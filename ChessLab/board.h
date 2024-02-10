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
#include "uiInteract.h"
#include "move.h"
#include "piece.h"
#include "space.h"
#include "pawn.h"
#include "king.h"
#include "queen.h"
#include "rook.h"
#include "bishop.h"
#include "knight.h"


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
		return currentMove % 2 == 0;
	}

	void display(Position posHover, Position posSel);

	void free();
	void reset();
	void clear();
	void move(int positionFrom, int positionTo);
	void assign(Position pos, Piece* p);
	void draw(const Interface& ui);

	Piece* getPiece(int location) const
	{
		return  board[location];
	}

private:
	Piece* board[64];
	int currentMove = 0;
	ogstream gout;
	void swap(Position pos1, Position pos2);
	void assertBoard();
};
