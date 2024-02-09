/***********************************************************************
 * Header File:
 *    PAWN : Handles a pawn on the board
 * Author:
 *    Austin Jesperson
 * Summary:
 *    A pawn on the chess board.
 ************************************************************************/

#pragma once
#include "piece.h"
#include <set>            // for STD::SET
#include <string>         // for STRING

using namespace std;

class Pawn : public Piece
{
public:
    Pawn(Position pos, bool color, PieceType pt = PAWN)
    {
        position = pos;
        fWhite = color;
    }

    set <int> getMoves(const Board* board);
    //void display(ogstream gout);
};