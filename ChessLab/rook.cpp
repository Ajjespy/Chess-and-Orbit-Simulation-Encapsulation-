/***********************************************************************
 * Source File:
 *    ROOK : Handles the rook piece on the board.
 * Author:
 *    Emilio Ordonez and Austin Jesperson
 * Summary:
 *    A rook on the chess board.
 ************************************************************************/

#include "rook.h"


/****************************************************
 * DRAW
 * Draws the rook on the board
 ***************************************************/
void Rook::draw(ogstream& gout)
{
	gout.drawRook(position.getLocation(), fWhite);
}

/*****************************************************
 * GET MOVES
 * Gets the possible moves for the rook based on its
 * current position on the board
 ******************************************************/
set<int> Rook::getMoves(const Board& board)
{
    int location = position.getLocation();
    set <int> possible;

    // return the empty set if there simply are no possible moves
    if (location < 0 || location >= 64)
        return possible;

    int row = position.getRow();  // current location row
    int col = position.getCol();  // current location column
    int r;                   // the row we are checking
    int c;                   // the column we are checking
    bool amBlack = fWhite;

    RC moves[4] =
    {
        {0,  1},
        {-1, 0},         
        {1, 0},
        {0, -1}
    };
        
    for (int i = 0; i < 4; i++)
    {
        r = row + moves[i].row;
        c = col + moves[i].col;
        while (r >= 0 && r < 8 && c >= 0 && c < 8)
        {
            possible.insert(r * 8 + c);
            r += moves[i].row;
            c += moves[i].col;
        }
        
        if (amBlack)
            possible.insert(r * 8 + c);
        if (!amBlack)
            possible.insert(r * 8 + c);
        }
}