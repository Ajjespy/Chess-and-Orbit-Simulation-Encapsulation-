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
	assign(Position(4), new King(Position(4), false));
	assign(Position(3), new Queen(Position(3), false));
	assign(Position(5), new Bishop(Position(5), false));
    assign(Position(6), new Knight(Position(6), false));
    assign(Position(7), new Rook(Position(7), false));
    
	for (int i = 8; i < 16; i++)
	{
        assign(Position(i), new Pawn(Position(i), false));
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
       assign(Position(i), new Pawn(Position(i), true));
    }
}
 

void Board::draw(const Interface& ui)
{
    gout.drawBoard();
	gout.drawHover(ui.getHoverPosition());
    gout.drawSelected(ui.getSelectPosition());

    if (ui.getSelectPosition() != -1)
    {
        Piece* selectedP = board[ui.getSelectPosition()];

        if (selectedP->isValid() && selectedP->isBlack() == blackTurn())
        {
            convertDirectionToMove(selectedP->getDirections(),selectedP->getLengthOfDirections(),selectedP);
            set <Move> ::iterator it;
            for (it = moves.begin(); it != moves.end(); ++it)
            {
                int loc = (*it).getDes().getLocation();
                gout.drawPossible(loc);
            }
        }
    }

    for(int i = 0; i < 64; i++)
    {
        board[i]->draw(gout);
    }
}


bool Board::move(int positionFrom, int positionTo)
{
    // if valid move
    set <Move> ::iterator it;
    for (it = moves.begin(); it != moves.end(); ++it)
    {
        if (it->getDes() == Position(positionTo))
        {
            assign(Position(positionTo), board[positionFrom]); 
            board[positionTo]->assignPos(positionTo); 
            assign(Position(positionFrom), new Space(Position(positionFrom))); 
            currentMove++; 
            last = *it;

            //check for special moves
            if (it->getCastleQ())
            {
                if (board[positionTo]->isBlack())
                {
                    assign(Position(58), board[56]);
                    assign(Position(56), new Space(Position(56))); 
                }
                else
                {
                    assign(Position(2), board[0]);
                    assign(Position(0), new Space(Position(0)));
                }
            }
            if (it->getCastleK())
            {
                if (board[positionTo]->isBlack())
                {
                    assign(Position(61), board[63]); 
                    assign(Position(63), new Space(Position(63)));
                }
                else
                {
                    assign(Position(5), board[7]);
                    assign(Position(7), new Space(Position(7)));
                }
            }
            if (it->getEnPassant())
            {
                if (board[positionTo]->isBlack())
                {
                    assign(Position(it->getDes().getRow() + 1, it->getDes().getCol()), new Space(Position(it->getDes().getRow() + 1, it->getDes().getCol()))); 
                }
                else
                {
                    assign(Position(it->getDes().getRow() - 1, it->getDes().getCol()), new Space(Position(it->getDes().getRow() - 1, it->getDes().getCol())));
                }
            }
            return true;
        }
    }
    return false;  
}