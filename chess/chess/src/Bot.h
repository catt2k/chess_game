#pragma once
#include <vector>
#include "chess_set.h"

struct AlphaBeta {
    double a;
    double b;
	std::vector<chess_set> cs;
};

class Bot {
public:
	void play(std::vector<chess_set>& cs);
private:
    double evaluate_func(const std::vector<chess_set>& cs);
	AlphaBeta max(std::vector<chess_set> cs, const int& depth, const AlphaBeta& input_ab);
	AlphaBeta min(std::vector<chess_set> cs, const int& depth, const AlphaBeta& input_ab);

    double pawnEval[8][8] =
    {
        {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0} ,
        {5.0, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0, 5.0},
        {1.0, 1.0, 2.0, 3.0, 3.0, 2.0, 1.0, 1.0},
        {0.5, 0.5, 1.0, 2.5, 2.5, 1.0, 0.5, 0.5},
        {0.0, 0.0, 0.0, 2.0, 2.0, 0.0, 0.0, 0.0},
        {0.5, -0.5, -1.0, 0.0, 0.0, -1.0, -0.5, 0.5},
        {0.5, 1.0, 1.0, -2.0, -2.0, 1.0, 1.0, 0.5},
        {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0}
    };

    double knightEval[8][8] =
    {
        {-5.0, -4.0, -3.0, -3.0, -3.0, -3.0, -4.0, -5.0} ,
        {-4.0, -2.0,  0.0,  0.0,  0.0,  0.0, -2.0, -4.0},
        {-3.0,  0.0,  1.0,  1.5,  1.5,  1.0,  0.0, -3.0},
        {-3.0,  0.5,  1.5,  2.0,  2.0,  1.5,  0.5, -3.0},
        {-3.0,  0.0,  1.5,  2.0,  2.0,  1.5,  0.0, -3.0},
        {-3.0,  0.5,  1.0,  1.5,  1.5,  1.0,  0.5, -3.0},
        {-4.0, -2.0,  0.0,  0.5,  0.5,  0.0, -2.0, -4.0},
        {-5.0, -4.0, -3.0, -3.0, -3.0, -3.0, -4.0, -5.0}
    };

    double queenEval[8][8] =
    {
        {-2.0, -1.0, -1.0, -0.5, -0.5, -1.0, -1.0, -2.0} ,
        {-1.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0, -1.0},
        {-1.0,  0.0,  0.5,  0.5,  0.5,  0.5,  0.0, -1.0},
        {-0.5,  0.0,  0.5,  0.5,  0.5,  0.5,  0.0, -0.5},
        {0.0,  0.0,  0.5,  0.5,  0.5,  0.5,  0.0, -0.5},
        {-1.0,  0.5,  0.5,  0.5,  0.5,  0.5,  0.0, -1.0},
        {-1.0,  0.0,  0.5,  0.0,  0.0,  0.0,  0.0, -1.0},
        {-2.0, -1.0, -1.0, -0.5, -0.5, -1.0, -1.0, -2.0}
    };

    double kingEval[8][8] =
    {
        {-3.0, -4.0, -4.0, -5.0, -5.0, -4.0, -4.0, -3.0} ,
        {-3.0, -4.0, -4.0, -5.0, -5.0, -4.0, -4.0, -3.0},
        {-3.0, -4.0, -4.0, -5.0, -5.0, -4.0, -4.0, -3.0},
        {-3.0, -4.0, -4.0, -5.0, -5.0, -4.0, -4.0, -3.0},
        {-2.0, -3.0, -3.0, -4.0, -4.0, -3.0, -3.0, -2.0},
        {-1.0, -2.0, -2.0, -2.0, -2.0, -2.0, -2.0, -1.0},
        {2.0,  2.0,  0.0,  0.0,  0.0,  0.0,  2.0,  2.0},
        {2.0,  3.0,  1.0,  0.0,  0.0,  1.0,  3.0,  2.0}
    };

    double bishopEval[8][8] =
    {
        {-2.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -2.0} ,
        {-1.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0, -1.0},
        {-1.0,  0.0,  0.5,  1.0,  1.0,  0.5,  0.0, -1.0},
        {-1.0,  0.5,  0.5,  1.0,  1.0,  0.5,  0.5, -1.0},
        {-1.0,  0.0,  1.0,  1.0,  1.0,  1.0,  0.0, -1.0},
        {-1.0,  1.0,  1.0,  1.0,  1.0,  1.0,  1.0, -1.0},
        {-1.0,  0.5,  0.0,  0.0,  0.0,  0.0,  0.5, -1.0},
        {-2.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -2.0}
    };

    double rookEval[8][8] =
    {
        {0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0} ,
        {0.5,  1.0,  1.0,  1.0,  1.0,  1.0,  1.0,  0.5},
        {-0.5,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0, -0.5},
        {-0.5,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0, -0.5},
        {-0.5,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0, -0.5},
        {-0.5,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0, -0.5},
        {-0.5,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0, -0.5},
        {0.0,   0.0, 0.0,  0.5,  0.5,  0.0,  0.0,  0.0}
    };
};
