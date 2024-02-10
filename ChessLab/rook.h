/***********************************************************************
 * Header File:
 *    ROOK : Handles the rook piece on the board
 * Author:
 *    Emilio Ordonez and Austin Jesperson
 * Summary:
 *    A rook on the chess board.
 ************************************************************************/

#include "piece.h"
#include "board.h"
#pragma once

using namespace std;

class Board;

class Rook : public Piece
{
public:
	Rook(Position pos, bool color, PieceType pt = ROOK)
	{
		position = pos;
		fWhite = color;
		type = pt;
	}

	void draw(ogstream& gout);
	set <int> getMoves(const Board& board);
};
