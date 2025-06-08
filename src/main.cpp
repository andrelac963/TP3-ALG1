#include "../include/board.hpp"
#include "../include/exact_solver.hpp"
#include "../include/greedy_solver.hpp"
#include <iostream>
#include <chrono>

int main()
{
    int n, m, k;
    std::cin >> n >> m >> k;

    Board board(n, m);
    board.load_board();

    auto start_exact = std::chrono::high_resolution_clock::now();
    int exact_result = ExactSolver::solve(board);
    auto end_exact = std::chrono::high_resolution_clock::now();

    auto start_greedy = std::chrono::high_resolution_clock::now();
    int greedy_result = GreedySolver::solve(board);
    auto end_greedy = std::chrono::high_resolution_clock::now();

    std::cout << "Exact Result: " << exact_result << "\n";
    std::cout << "Greedy Result: " << greedy_result << "\n";

    std::chrono::duration<double> exact_time = end_exact - start_exact;
    std::chrono::duration<double> greedy_time = end_greedy - start_greedy;

    std::cout << "Exact Time: " << exact_time.count() << " seconds\n";
    std::cout << "Greedy Time: " << greedy_time.count() << " seconds\n";

    return 0;
}