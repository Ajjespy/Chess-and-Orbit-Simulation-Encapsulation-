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

using namespace std;

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

	void reset();
	void clear();
	void move(int positionFrom, int positionTo);
	void assign(Position pos, Piece* p);
	void draw(const Interface& ui);
	
	// change to move once we implement move class
	int lastMoved() { return 20; };

private:
	Piece* board[64];
	int currentMove = 0;
	ogstream gout;
	void swap(Position pos1, Position pos2);
	Move last = Move();
	set <Move> moves;

	set<int> convertDirectionToMove(RC* movesArrayP, int length, Piece* currPiece)
	{
		set<int> possible;
		int c = currPiece->getPosition().getCol(); //current column
		int r = currPiece->getPosition().getRow(); //current row 
		int cc = c;
		int rr = r;

		// bishops, rooks, queens
		if (currPiece->ifSlide())
		{
			for (int i = 0; i < length; i++)
			{
				rr += movesArrayP[i].row;
				cc += movesArrayP[i].col;
				if ((rr * 8 + cc) >= 0 && (rr * 8 + cc) < 64)
				{
					while (rr >= 0 && rr < 8 && cc >= 0 && cc < 8 &&
						board[rr * 8 + cc]->getType() == SPACE)
					{
						possible.insert(rr * 8 + cc);
						rr += movesArrayP[i].row;
						cc += movesArrayP[i].col;
					}
				}

				// if (board[r * 8 + c]->isWhite() != board[rr * 8 + cc]->isWhite())
				// {
				// 	possible.insert(rr * 8 + cc);
				// }
				//else if (!currPiece->isWhite() && board[rr * 8 + cc]->isWhite())
				//{
				//	possible.insert(rr * 8 + cc);
				//}
				rr = r;
				cc = c;
			}
		}

		// pawn
		else if (currPiece->getType() == PAWN)
		{
			if (currPiece->isBlack()) // black pawn
			{
				rr = r - 2;  //row is r
				if (currPiece->getNMoves() == 0)
				{
					if (r == 6 && board[rr * 8 + cc]->getType() == SPACE && board[(r - 1) * 8 + cc]->getType() == SPACE)
					{
						possible.insert(rr * 8 + cc);  // forward two blank spaces
					};
				};

				rr = r - 1;
				if (rr >= 0 && board[rr * 8 + cc]->getType() == SPACE) 
				{
					possible.insert(rr * 8 + cc);
						// forward one blank space
				}

				cc = c - 1;
				if (!board[rr * 8 + cc]->isBlack() && board[rr * 8 + cc]->getType() != SPACE)
				{
					possible.insert(rr * 8 + cc);    // attack left
				}

				cc = c + 1;
				if (!board[rr * 8 + cc]->isBlack() && board[rr * 8 + cc]->getType() != SPACE)
				{
					possible.insert(rr * 8 + cc);    // attack right
				}

				//// what about en-passant and pawn promotion
				//if (r == 3)
				//{
				//	cc = c - 1;
				//	if (board[r * 8 + cc]->getType() == PAWN && board[r * 8 + cc]->isWhite() && (r * 8 + cc) == lastMoved()) // compare directly laater
				//	{
				//		possible.insert(r * 8 + cc);
				//	};    // attack left

				//	cc = c + 1;
				//	if (board[r * 8 + cc]->getType() == PAWN && board[r * 8 + cc]->isWhite() && (r * 8 + cc) == lastMoved())
				//	{
				//		possible.insert(r * 8 + cc);
				//	};  // attack right)

				//};

			}

			else if (!currPiece->isBlack()) //white pawn
			{
				rr = r + 2; //row is r
				if (currPiece->getNMoves() == 0)
				{
					if (r == 1 && board[rr * 8 + cc]->getType() == SPACE && board[(r + 1) * 8 + cc]->getType() == SPACE)
					{
						possible.insert(rr * 8 + cc);  // forward two blank spaces
					};
				};

				rr = r + 1;
				if (rr <= 7 && board[rr * 8 + cc]->getType() == SPACE)
				{
					possible.insert(rr * 8 + cc);   //forward one blank space
				}

				cc = c - 1;
				if (board[rr * 8 + cc]->isBlack() && board[rr * 8 + cc]->getType() != SPACE)
				{
					possible.insert(rr * 8 + cc);    // attack left
				}

				cc = c + 1;
				if (board[rr * 8 + cc]->isBlack() && board[rr * 8 + cc]->getType() != SPACE)
				{
					possible.insert(rr * 8 + cc);    // attack right
				}
					

				//// what about en-passant and pawn promotion
				//if (r == 4)
				//{
				//	cc = c - 1;
				//	if (board[r * 8 + cc]->getType() == PAWN && !board[r * 8 + cc]->isWhite() && (r * 8 + cc) == lastMoved())
				//	{
				//		possible.insert(rr * 8 + cc);
				//	};    // attack left

				//	cc = c + 1;
				//	if (board[r * 8 + cc]->getType() == PAWN && !board[r * 8 + cc]->isWhite() && (r * 8 + cc) == lastMoved())
				//	{
				//		possible.insert(r * 8 + c);
				//	};  // attack right)
				//};

			}
		}

        // knight and king
		else if (currPiece->getType() == KNIGHT || currPiece->getType() == KING)
		{
			for (int i = 0; i < length; i++)
			{
				rr += movesArrayP[i].row;
				cc += movesArrayP[i].col;
				if (rr >= 0 && rr < 8 && cc >= 0 && cc < 8)
				{
					if (board[rr * 8 + cc]->getType() == SPACE)
					{
						possible.insert(rr * 8 + cc);
					}
					else
					{
						if (currPiece->isBlack() && !board[rr * 8 + cc]->isBlack())
						{
							possible.insert(rr * 8 + cc);
						}
						if (!currPiece->isBlack() && board[rr * 8 + cc]->isBlack())
						{
							possible.insert(rr * 8 + cc);
						}
					}
				
				}
				rr = r;
				cc = c;
			}

			// castling
			if (currPiece->getType() == KING)
			{
			}
		}

		return possible;
	}
};
