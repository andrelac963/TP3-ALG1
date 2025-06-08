#include "../include/exact_solver.hpp"
#include <climits>
#include <cmath>

int ExactSolver::solve(const Board &board)
{
    int min_moves = INT_MAX;
    std::vector<bool> captured(board.pawns.size(), false);
    dfs(board, board.queen_position, captured, 0, min_moves);
    return min_moves == INT_MAX ? -1 : min_moves;
}

void ExactSolver::dfs(const Board &board, std::pair<int, int> queen_pos,
                      std::vector<bool> &captured, int moves, int &min_moves)
{
    // Verifica se todos os peões foram capturados
    bool all_captured = true;
    for (bool c : captured)
    {
        if (!c)
        {
            all_captured = false;
            break;
        }
    }
    if (all_captured)
    {
        min_moves = (moves < min_moves) ? moves : min_moves;
        return;
    }

    for (size_t i = 0; i < board.pawns.size(); ++i)
    {
        if (!captured[i])
        {
            auto target = board.pawns[i];
            int dist = distance(queen_pos, target);

            // Simula o movimento da rainha até o peão
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

            if (!valid_move)
                continue;

            // Marca o peão como capturado e realiza a chamada recursiva
            captured[i] = true;
            dfs(board, target, captured, moves + dist, min_moves);
            captured[i] = false;
        }
    }
}

int ExactSolver::distance(std::pair<int, int> a, std::pair<int, int> b)
{
    return std::max(std::abs(a.first - b.first), std::abs(a.second - b.second));
}