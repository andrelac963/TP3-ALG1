#include "../include/greedy_solver.hpp"
#include <cmath>
#include <limits>

int GreedySolver::solve(const Board &board)
{
    std::pair<int, int> queen_pos = board.queen_position;
    std::vector<bool> captured(board.pawns.size(), false);
    int total_moves = 0;

    for (size_t remaining = board.pawns.size(); remaining > 0; --remaining)
    {
        size_t closest_pawn = std::numeric_limits<size_t>::max();
        int min_distance = std::numeric_limits<int>::max();

        for (size_t i = 0; i < board.pawns.size(); ++i)
        {
            if (!captured[i])
            {
                auto target = board.pawns[i];
                int dist = distance(queen_pos, target);

                // Verifica se o caminho até o peão é válido
                bool valid_move = true;
                int x = queen_pos.first, y = queen_pos.second;

                while (x != target.first || y != target.second)
                {
                    int step_x = (target.first > x) - (target.first < x);
                    int step_y = (target.second > y) - (target.second < y);

                    x += step_x;
                    y += step_y;

                    if (!board.is_valid_move(x, y))
                    {
                        valid_move = false;
                        break;
                    }
                }

                if (valid_move && dist < min_distance)
                {
                    min_distance = dist;
                    closest_pawn = i;
                }
            }
        }

        if (closest_pawn == std::numeric_limits<size_t>::max())
            return -1;

        total_moves += min_distance;
        queen_pos = board.pawns[closest_pawn];
        captured[closest_pawn] = true;
    }

    return total_moves;
}

int GreedySolver::distance(std::pair<int, int> a, std::pair<int, int> b)
{
    return std::max(std::abs(a.first - b.first), std::abs(a.second - b.second));
}