#include "pawn.h"



set <int> Pawn::getMoves(const Board* board)
{
    set <int> possible;

    
    int row = getPosition() / 8;  // current location row
    int col = getPosition() % 8;  // current location column
    int r;                   // the row we are checking
    int c;                   // the column we are checking
    
    if (!isWhite())
    {
        c = col;
        r = row - 2;
        if (getNMoves() == 0)
        {
            if (row == 6 && board[r * 8 + c] == ' ' && board[(r - 1) * 8 + c] == ' ')
            {
                possible.insert(r * 8 + c);  // forward two blank spaces
            };
        };
        
        r = row - 1;
        if (r >= 0 && board[r * 8 + c] == ' ')
            possible.insert(r * 8 + c);  // forward one blank space

        c = col - 1;
        if (board[Position(r,c).getLocation()] >= 'a' && board[Position(r, c).getLocation()] <= 'z')
            possible.insert(r * 8 + c);    // attack left

        c = col + 1;
        if (board[Position(r, c).getLocation()] >= 'a' && board[Position(r, c).getLocation()] <= 'z')
            possible.insert(r * 8 + c);    // attack right

        // what about en-passant and pawn promotion
        if (row == 3)
        {
            c = col - 1;
            if (board[Position(row, c).getLocation()] == 'p')
            {
                possible.insert(r * 8 + c);
            };    // attack left

            c = col + 1;
            if (board[Position(row, c).getLocation()] == 'p')
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
            if (row == 1 && board[r * 8 + c] == ' ' && board[(r + 1) * 8 + c] == ' ')
            {
                possible.insert(r * 8 + c);  // forward two blank spaces
            };
        };

        r = row + 1;
        if (r <= 7 && board[r * 8 + c] == ' ')
            possible.insert(r * 8 + c);  // forward one blank space

        c = col - 1;
        if (board[Position(r, c).getLocation()] >= 'A' && board[Position(r, c).getLocation()] <= 'Z')
            possible.insert(r * 8 + c);    // attack left

        c = col + 1;
        if (board[Position(r, c).getLocation()] >= 'A' && board[Position(r, c).getLocation()] <= 'Z')
            possible.insert(r * 8 + c);    // attack right

        // what about en-passant and pawn promotion
        if (row == 4)
        {
            c = col - 1;
            if (board[Position(row, c).getLocation()] == 'P')
            {
                possible.insert(r * 8 + c);
            };    // attack left

            c = col + 1;
            if (board[Position(row, c).getLocation()] == 'P')
            {
                possible.insert(r * 8 + c);
            };  // attack right)

        };

    }

    return possible;
}