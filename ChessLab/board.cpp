/***********************************************************************
 * Source File:
 *    BOARD : Handles the chess board.
 * Author:
 *    Emilio Ordonez and Austin Jesperson
 * Summary:
 *    The chess board.
 ************************************************************************/

#include "board.h"

Board::Board()
{
    clear();
}

void Board::clear()
{
    for (int i = 0; i < 64; i++)
    {
        assign(Position(i), Piece(Position(i), NULL, SPACE));
    }
}


void Board::assign(Position pos, Piece p)
{
    board[pos.getLocation()] = p;
}

void Board::reset()
{
    //Place pieces on the board
    //White pieces;
    board[0] = Piece(Position(0), true, ROOK);  
    board[1] = Piece(Position(1), true, KNIGHT);
    board[2] = Piece(Position(2), true, BISHOP); 
    board[3] = Piece(Position(3), true, QUEEN); 
    board[4] = Piece(Position(4), true, KING); 
    board[5] = Piece(Position(5), true, BISHOP); 
    board[6] = Piece(Position(6), true, KNIGHT); 
    board[7] = Piece(Position(7), true, ROOK); 
    for (int i = 8; i < 16; i++)
    {
        board[i] = Piece(Position(i), true, PAWN);
    }

    //Black pieces;
    board[63] = Piece(Position(63), false, ROOK);
    board[62] = Piece(Position(62), false, KNIGHT);
    board[61] = Piece(Position(61), false, BISHOP);
    board[60] = Piece(Position(60), false, KING); 
    board[59] = Piece(Position(59), false, QUEEN);
    board[58] = Piece(Position(58), false, BISHOP);
    board[57] = Piece(Position(57), false, KNIGHT);
    board[56] = Piece(Position(56), false, ROOK);
    for (int i = 48; i < 56; i++)
    {
        board[i] = Piece(Position(i), false, PAWN);
    }
            
}