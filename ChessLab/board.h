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

	bool isFree(int location)
	{
		Piece* p = board[location];
		if (p->getType() == SPACE)
		{
			return true;
		}
		return false;
	}
	struct RC {
		int row;
		int col;
	};

	void reset();
	void clear();
	void move(int positionFrom, int positionTo);
	void assign(Position pos, Piece* p);
	void draw(const Interface& ui);
	int lastMoved() { return last; };
	//const Piece& operator [] 

private:
	Piece* board[64];
	int currentMove = 0;
	ogstream gout;
	void swap(Position pos1, Position pos2);
	int last;
	set <Move> moves;

	set<Move> convertDirectionToMove(RC* directions, const Position& p)
	{
		Move check = Move();
		check.setSrc(p);
		Position posCheck = p;

		if (board[p.getLocation()]->ifSlide())
		{
			for (int i = 0; i < directions->; i++)
			{
				posCheck.setRow(p.getRow() + directions[i].row);
				posCheck.setCol(p.getCol() + directions[i].col);
				while(board[posCheck.getLocation()].getType() == SPACE)
				{
					check.setDes(posCheck);
					moves.insert(check);
					posCheck.setRow(posCheck.getRow() + directions[i].row);
					posCheck.setCol(posCheck.getCol() + directions[i].col);
				}
				if (board[p.getLocation()]->isWhite() != board[posCheck.getLocation()]->isWhite())
				{
					check.setDes(posCheck);
					moves.insert(check);
				}
			}
		}
		else
		{
			for (int i = 0; i < directions.size(); i++)
			{
				posCheck.setRow(p.getRow() + directions[i].row);
				posCheck.setCol(p.getCol() + directions[i].col);
				if (board[posCheck.getLocation()].getType() == SPACE)
				{
					check.setDes(posCheck);
					moves.insert(check);
				}
				else if (board[p.getLocation()]->isWhite() != board[posCheck.getLocation()]->isWhite())
				{
					check.setDes(posCheck);
					check.setCapture(board[posCheck.getLocation()]->getType());
					moves.insert(check);
					check.setCapture(SPACE);
				}
			}
		}
	}
};
