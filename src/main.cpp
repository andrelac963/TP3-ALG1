#include <iostream>
#include <string>
#include "Board.hpp"
#include "ExactSolver.hpp"
#include "ApproxSolver.hpp"
#include "Timer.hpp"

// Modo VPL: imprime só a solução exata.
// Com --verbose ou -v: imprime também solução aprox. e tempos+iterações.
int main(int argc, char *argv[])
{
    bool verbose = false;
    if (argc > 1)
    {
        std::string a = argv[1];
        if (a == "--verbose" || a == "-v")
            verbose = true;
    }

    // 1) Leitura e pré-processamento
    Board board;
    board.read(std::cin);
    board.computeDistances();

    const int INF = 1000000000;
    // Se algum peão for inacessível, retorna -1 direto
    for (int j = 1; j <= board.K; ++j)
    {
        if (board.dist[0][j] >= INF)
        {
            std::cout << -1 << "\n";
            return 0;
        }
    }

    // 2) Solução exata
    Timer t1;
    t1.start();
    ExactSolver exact(board.dist);
    int ansEx = exact.solve();
    double timeEx = t1.elapsed();
    long long iterEx = exact.getIterationCount();
    std::cout << ansEx << "\n";

    // 3) (opcional) Solução aproximada + estatísticas
    if (verbose)
    {
        Timer t2;
        t2.start();
        ApproxSolver approx(board.dist);
        int ansAp = approx.solve();
        double timeAp = t2.elapsed();
        long long iterAp = approx.getIterationCount();

        std::cout
            << ansAp << "\n"
            << "Exact time:   " << timeEx << " ms, iterations: " << iterEx << "\n"
            << "Approx time:  " << timeAp << " ms, iterations: " << iterAp << "\n";
    }

    return 0;
}