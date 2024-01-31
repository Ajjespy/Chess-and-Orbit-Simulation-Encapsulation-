/***********************************************************************
 * Header File:
 *    TEST MOVE : test the Piece class
 * Author:
 *    Emilio Ordonez
 ************************************************************************/

#pragma once

class PieceTest
{
public:
	void run() const
	{
		constructorBlack();
		constructorWhite();
		assignPos();
		invalidPos();
		keepTrackofMoves();
	}
private:
	void constructorWhite() const;
	void constructorBlack() const;

	void assignPos() const;
	void invalidPos() const;

	void keepTrackofMoves() const;
};