#ifndef BOARD_HPP
#define BOARD_HPP

#include <vector>
#include <string>
#include <utility>

class Board
{
public:
    int rows, cols;
    std::pair<int, int> queen_position;
    std::vector<std::pair<int, int>> pawns;
    std::vector<std::string> grid;

    Board(int n, int m);
    void load_board();
    bool is_valid_move(int x, int y) const;
};

#endif