#include "../include/board.hpp"
#include <iostream>

Board::Board(int n, int m) : rows(n), cols(m) {}

void Board::load_board()
{
    grid.resize(rows);
    for (int i = 0; i < rows; ++i)
    {
        std::cin >> grid[i];
        for (int j = 0; j < cols; ++j)
        {
            if (grid[i][j] == 'R')
            {
                queen_position = {i, j};
            }
            else if (grid[i][j] == 'P')
            {
                pawns.emplace_back(i, j);
            }
        }
    }
}

bool Board::is_valid_move(int x, int y) const
{
    return x >= 0 && x < rows && y >= 0 && y < cols && grid[x][y] != '-';
}