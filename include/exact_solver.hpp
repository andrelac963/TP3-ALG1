#ifndef EXACT_SOLVER_HPP
#define EXACT_SOLVER_HPP

#include "board.hpp"

class ExactSolver
{
public:
    static int solve(const Board &board);

private:
    static void dfs(const Board &board, std::pair<int, int> queen_pos,
                    std::vector<bool> &captured, int moves, int &min_moves);
    static int distance(std::pair<int, int> a, std::pair<int, int> b);
};

#endif