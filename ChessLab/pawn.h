#pragma once
#include "piece.h"
#include <set>            // for STD::SET
#include <string>         // for STRING
#include "position.h"

using namespace std;

class Pawn : public Piece
{
public:
    set <int> getMoves(const Board* board);
    void display(ogstream gout);
    