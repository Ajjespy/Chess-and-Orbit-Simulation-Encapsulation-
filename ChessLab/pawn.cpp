/***********************************************************************
 * Source File:
 *    PAWN : Handles a pawn on the board
 * Author:
 *    Austin Jesperson
 * Summary:
 *    A pawn on the chess board.
 ************************************************************************/

#include "pawn.h"
set <RC> Pawn::getMoves()
{
    
    set <RC> possible;

    if isWhite()
    {
		possible = { {0,1}, {0,2}, {1,1}, {-1,1} };
    }
    else
    {
		possible = { {0,-1}, {0,-2}, {1,-1}, {-1,-1} };
    }
    
    
    /*int row = getPosition().getLocation() / 8;  // current location row
    int col = getPosition().getLocation() % 8;  // current location column
    int r;                   // the row we are checking
    int c;                   // the column we are checking
    
    if (!isWhite())
    {
        c = col;
        r = row - 2;
        if (getNMoves() == 0)
        {
            if (row == 6 && board[r * 8 + c].getType() == SPACE && board[(r - 1) * 8 + c].getType() == SPACE)
            {
                possible.insert(r * 8 + c);  // forward two blank spaces
            };
        };
        
        r = row - 1;
        if (r >= 0 && board[r * 8 + c].getType() == SPACE)
            possible.insert(r * 8 + c);  // forward one blank space

        c = col - 1;
        if (board[Position(r,c).getLocation()].isWhite() && board[Position(r, c).getLocation().isWhite())
            possible.insert(r * 8 + c);    // attack left

        c = col + 1;
        if (board[Position(r, c).getLocation()].isWhite() && board[Position(r, c).getLocation()].isWhite())
            possible.insert(r * 8 + c);    // attack right

        // what about en-passant and pawn promotion
        if (row == 3)
        {
            c = col - 1;
            if (board[Position(row, c).getLocation()].getType() == PAWN && board[Position(row, c).getLocation()].isWhite() && Position(row, c).getLocation() == board.lastMoved())
            {
                possible.insert(r * 8 + c);
            };    // attack left

            c = col + 1;
            if (board[Position(row, c).getLocation()].getType() == PAWN && board[Position(row, c).getLocation()].isWhite() && Position(row, c).getLocation() == board.lastMoved())
            {
                possible.insert(r * 8 + c);
            };  // attack right)

        };

    }

    if (isWhite())
    {
        c = col;
        r = row + 2;
        if (getNMoves() == 0)
        {
            if (row == 1 && board[r * 8 + c].getType() == SPACE && board[(r + 1) * 8 + c].getType() == SPACE)
            {
                possible.insert(r * 8 + c);  // forward two blank spaces
            };
        };

        r = row + 1;
        if (r <= 7 && board[r * 8 + c].getType() == SPACE)
            possible.insert(r * 8 + c);  // forward one blank space

        c = col - 1;
        if (!board[Position(r, c).getLocation()].isWhite() && !board[Position(r, c).getLocation()].isWhite())
            possible.insert(r * 8 + c);    // attack left

        c = col + 1;
        if (!board[Position(r, c).getLocation()].isWhite() && !board[Position(r, c).getLocation()].isWhite())
            possible.insert(r * 8 + c);    // attack right

        // what about en-passant and pawn promotion
        if (row == 4)
        {
            c = col - 1;
            if (board[Position(row, c).getLocation()].getType() == PAWN && !board[Position(row, c).getLocation()].isWhite() && Position(row, c).getLocation() == board.lastMoved())
            {
                possible.insert(r * 8 + c);
            };    // attack left

            c = col + 1;
            if (board[Position(row, c).getLocation()].getType() == PAWN && !board[Position(row, c).getLocation()].isWhite() && Position(row, c).getLocation() == board.lastMoved())
            {
                possible.insert(r * 8 + c);
            };  // attack right)

        };

    }*/

    return possible;
   
} 


void Pawn::draw(ogstream& gout)
{
	gout.drawPawn(position.getLocation(), fWhite);
}