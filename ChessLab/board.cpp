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
        assign(Position(i),new Space(Position(i)));
    }
}


void Board::assign(Position pos, Piece* p)
{
    board[pos.getLocation()] = p;
}


void Board::reset()
{
    //Place pieces on the board
    //White pieces;
	assign(Position(0), new Rook(Position(0), false));
	assign(Position(1), new Knight(Position(1), false));
	assign(Position(2), new Bishop(Position(2), false));
	assign(Position(3), new King(Position(3), false));
	assign(Position(4), new Queen(Position(4), false));
	assign(Position(5), new Bishop(Position(5), false));
    assign(Position(6), new Knight(Position(6), false));
    assign(Position(7), new Rook(Position(7), false));

	for (int i = 8; i < 16; i++)
	{
		board[i] = new Pawn(Position(i), false);
	}

    //Black pieces;
	assign(Position(63), new Rook(Position(63), true));
	assign(Position(62), new Knight(Position(62), true));
	assign(Position(61), new Bishop(Position(61), true));
	assign(Position(60), new King(Position(60), true));
	assign(Position(59), new Queen(Position(59), true));
	assign(Position(58), new Bishop(Position(58), true));
    assign(Position(57), new Knight(Position(57), true));
    assign(Position(56), new Rook(Position(56), true));

   for (int i = 48; i < 56; i++)
    {
        board[i] = new Pawn(Position(i), true);
    }
}
 

void Board::draw(const Interface& ui)
{
    gout.drawBoard();
	gout.drawHover(ui.getHoverPosition());
    gout.drawSelected(ui.getSelectPosition());

    for(int i = 0; i < 64; i++)
    {
        board[i]->draw(gout);
    }

    
}


void Board::move(int positionFrom, int positionTo)
{
    assign(Position(positionTo), board[positionFrom]);
    board[positionFrom]->assignPos(positionTo);
    assign(Position(positionFrom), new Space(Position(positionFrom)));
}