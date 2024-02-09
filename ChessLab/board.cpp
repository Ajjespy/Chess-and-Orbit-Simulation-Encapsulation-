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
    reset();
}

void Board::clear()
{
    for (int i = 0; i < 64; i++)
    {
        assign(Position(i), Space(Position(i)));
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
    board[0] = Rook(Position(0), true);  
    board[1] = Knight(Position(1), true);
    board[2] = Bishop(Position(2), true); 
    board[3] = Queen(Position(3), true); 
    board[4] = King(Position(4), true); 
    board[5] = Bishop(Position(5), true); 
    board[6] = Knight(Position(6), true); 
    board[7] = Rook(Position(7), true); 
    for (int i = 8; i < 16; i++)
    {
        board[i] = Pawn(Position(i), true);
    }

    //Black pieces;
    board[63] = Rook(Position(63), false);
    board[62] = Knight(Position(62), false);
    board[61] = Bishop(Position(61), false);
    board[60] = King(Position(60), false); 
    board[59] = Queen(Position(59), false);
    board[58] = Bishop(Position(58), false);
    board[57] = Knight(Position(57), false);
    board[56] = Rook(Position(56), false);
    for (int i = 48; i < 56; i++)
    {
        board[i] = Pawn(Position(i), false);
    }
            
}