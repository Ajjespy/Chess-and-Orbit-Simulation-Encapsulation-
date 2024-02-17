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


	bool blackTurn()
	{
		if (currentMove % 2 == 0)
		{
			return true;
		}
		return false;
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
	int currentMove = 1; 
	ogstream gout;
	void swap(Position pos1, Position pos2);
	Move last = Move();
	set <Move> moves;

	void convertDirectionToMove(RC* movesArrayP, int length, Piece* currPiece)
	{
		int c = currPiece->getPosition().getCol(); //current column
		int r = currPiece->getPosition().getRow(); //current row 
		int cc = c;
		int rr = r;
		Move m;

		// bishops, rooks, queens
		if (currPiece->ifSlide())
		{
			for (int i = 0; i < length; i++)
			{
				rr += movesArrayP[i].row;
				cc += movesArrayP[i].col;
				if ((rr * 8 + cc) >= 0 && (rr * 8 + cc) < 64)
				{
					while (rr >= 0 && rr < 8 && cc >= 0 && cc < 8 && board[rr * 8 + cc]->getType() == SPACE)
					{
						m.setSrc(currPiece->getPosition());
						m.setDes(board[rr * 8 + cc]->getPosition());
						moves.insert(m);
						rr += movesArrayP[i].row;
						cc += movesArrayP[i].col;
					}
					if (rr >= 0 && rr < 8 && cc >= 0 && cc < 8 && currPiece->isBlack() != board[rr * 8 + cc]->isBlack())
					{
						m.setSrc(currPiece->getPosition());
						m.setDes(board[rr * 8 + c]->getPosition());
						m.setCapture(board[rr * 8 + cc]->getType());
						moves.insert(m);
					}

				}
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
						m.setSrc(currPiece->getPosition());
						m.setDes(board[rr * 8 + cc]->getPosition());
						moves.insert(m);    // forward two blank spaces
					};
				};

				rr = r - 1;
				if (rr >= 0 && board[rr * 8 + cc]->getType() == SPACE)
				{
					m.setSrc(currPiece->getPosition());
					m.setDes(board[rr * 8 + cc]->getPosition());
					moves.insert(m);
					// forward one blank space
				}

				cc = c - 1;
				if (!board[rr * 8 + cc]->isBlack() && board[rr * 8 + cc]->getType() != SPACE)
				{
					m.setSrc(currPiece->getPosition());
					m.setDes(board[rr * 8 + cc]->getPosition());
					moves.insert(m);    // attack left
				}

				cc = c + 1;
				if (!board[rr * 8 + cc]->isBlack() && board[rr * 8 + cc]->getType() != SPACE)
				{
					m.setSrc(currPiece->getPosition());
					m.setDes(board[rr * 8 + cc]->getPosition());
					moves.insert(m);  // attack right
				}

				// what about en-passant and pawn promotion
				if (r == 3)
				{
					cc = c - 1;
					if (board[r * 8 + cc]->getType() == PAWN && !board[r * 8 + cc]->isBlack() && (r * 8 + cc) == lastMoved())
					{
						m.setSrc(currPiece->getPosition());
						m.setDes(board[r * 8 + cc]->getPosition());
						m.setEnPassant();
						moves.insert(m);  // attack leftt
						
					};  

					cc = c + 1;
					if (board[r * 8 + cc]->getType() == PAWN && !board[r * 8 + cc]->isBlack() && (r * 8 + cc) == lastMoved())
					{
						m.setSrc(currPiece->getPosition());
						m.setDes(board[r * 8 + cc]->getPosition());
						m.setEnPassant();
						moves.insert(m);
					};  // attack right)

				};

			}

			else if (!currPiece->isBlack()) //white pawn
			{
				rr = r + 2; //row is r
				if (currPiece->getNMoves() == 0)
				{
					if (r == 1 && board[rr * 8 + cc]->getType() == SPACE && board[(r + 1) * 8 + cc]->getType() == SPACE)
					{
						m.setSrc(currPiece->getPosition());
						m.setDes(board[rr * 8 + cc]->getPosition());
						moves.insert(m);  // forward two blank spaces
					};
				};

				rr = r + 1;
				if (rr <= 7 && board[rr * 8 + cc]->getType() == SPACE)
				{
					m.setSrc(currPiece->getPosition());
					m.setDes(board[rr * 8 + cc]->getPosition());
					moves.insert(m);   //forward one blank space
				}

				cc = c - 1;
				if (board[rr * 8 + cc]->isBlack() && board[rr * 8 + cc]->getType() != SPACE)
				{
					m.setSrc(currPiece->getPosition());
					m.setDes(board[rr * 8 + cc]->getPosition());
					moves.insert(m);    // attack left
				}

				cc = c + 1;
				if (board[rr * 8 + cc]->isBlack() && board[rr * 8 + cc]->getType() != SPACE)
				{
					m.setSrc(currPiece->getPosition());
					m.setDes(board[rr * 8 + cc]->getPosition());
					moves.insert(m);    // attack right
				}


				 //what about en-passant and pawn promotion
				if (r == 4)
				{
					cc = c - 1;
					if (board[r * 8 + cc]->getType() == PAWN && board[r * 8 + cc]->isBlack() && (r * 8 + cc) == lastMoved())
					{
						m.setSrc(currPiece->getPosition());
						m.setDes(board[r * 8 + cc]->getPosition());
						m.setEnPassant();
						moves.insert(m); // attack left
					};    

					cc = c + 1;
					if (board[r * 8 + cc]->getType() == PAWN && board[r * 8 + cc]->isBlack() && (r * 8 + cc) == lastMoved())
					{
						m.setSrc(currPiece->getPosition());
						m.setDes(board[r * 8 + cc]->getPosition());
						m.setEnPassant();
						moves.insert(m);  // attack right)
					};  
				};

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
						m.setSrc(currPiece->getPosition());
						m.setDes(board[rr * 8 + cc]->getPosition());
						moves.insert(m);
					}
					else
					{
						if (currPiece->isBlack() != board[rr * 8 + cc]->isBlack())
						{
							m.setSrc(currPiece->getPosition());
							m.setDes(board[rr * 8 + cc]->getPosition());
							moves.insert(m);
						}
					}

				}
				rr = r;
				cc = c;
			}
		}

#ifdef DEBUG
		// castling
		if (currPiece->getType() == KING)
		{
			if (!currPiece->isBlack())
			{
				// white side, queen side
				if (currPiece->getNMoves() == 0 && board[0]->getType() == ROOK && board[0]->getNMoves() == 0)
				{
					// check to make sure spots in between are open
					if (board[1]->getType() == SPACE && board[2]->getType() == SPACE && board[3]->getType() == SPACE)
					{
						m.setSrc(currPiece->getPosition());
						m.setDes(board[1]->getPosition());
						m.setCastle(false);
						moves.insert(m);
					}
				}
				// white side, king side
				if (currPiece->getNMoves() == 0 && board[7]->getType() == ROOK && board[7]->getNMoves() == 0)
				{
					// check to make sure spots in between are open
					if (board[5]->getType() == SPACE && board[6]->getType() == SPACE)
					{
						m.setSrc(currPiece->getPosition());
						m.setDes(board[6]->getPosition());
						m.setCastle(true);
						moves.insert(m);
					}
				}
			}
			else
			{
				// black side, queen side
				if (currPiece->getNMoves() == 0 && board[0]->getType() == ROOK && board[0]->getNMoves() == 0)
				{
					// check to make sure spots in between are open
					if (board[57]->getType() == SPACE && board[58]->getType() == SPACE && board[59]->getType() == SPACE)
					{
						m.setSrc(currPiece->getPosition());
						m.setDes(board[57]->getPosition());
						m.setCastle(false);
						moves.insert(m);
					}
				}
				// white side, king side
				if (currPiece->getNMoves() == 0 && board[7]->getType() == ROOK && board[7]->getNMoves() == 0)
				{
					// check to make sure spots in between are open
					if (board[61]->getType() == SPACE && board[62]->getType() == SPACE)
					{
						m.setSrc(currPiece->getPosition());
						m.setDes(board[62]->getPosition());
						m.setCastle(true);
						moves.insert(m);
					}
				}
			}
		}
#endif // DEBUG
	}
};
