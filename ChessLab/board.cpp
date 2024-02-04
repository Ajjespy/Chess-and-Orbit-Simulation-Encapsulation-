/***********************************************************************
 * Source File:
 *    BOARD : Handles the chess board.
 * Author:
 *    Emilio Ordonez and Austin Jesperson
 * Summary:
 *    The chess board.
 ************************************************************************/

#include "board.h"

Board::Board():
board{
      'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r',
      'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
      'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P',
      'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R' }
{}

void Board::clear()
{
    for (int i = 0; i < 64; i++)
    {
        board[i] = (' ');
    }
}
void Board::assign(Position pos, char p)
{
    board[pos.getLocation()] = p;
}