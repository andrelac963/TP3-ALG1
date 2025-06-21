#ifndef EXACTSOLVER_HPP
#define EXACTSOLVER_HPP

#include <vector>

// Solver exato por Programação Dinâmica sobre subconjuntos (bitmask)
class ExactSolver
{
    int K; // número de peões
    const std::vector<std::vector<int>> &dist;
    long long iterationCount; // contador de iterações (transições DP)

public:
    ExactSolver(const std::vector<std::vector<int>> &distMatrix);
    // retorna o custo mínimo (ou -1) e atualiza iterationCount
    int solve();
    long long getIterationCount() const { return iterationCount; }
};

#endif // EXACTSOLVER_HPP