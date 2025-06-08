#ifndef GREEDY_SOLVER_HPP
#define GREEDY_SOLVER_HPP

#include "board.hpp"

class GreedySolver
{
public:
    static int solve(const Board &board);

private:
    static int distance(std::pair<int, int> a, std::pair<int, int> b);
};

#endif