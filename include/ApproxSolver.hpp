#ifndef APPROXSOLVER_HPP
#define APPROXSOLVER_HPP

#include <vector>

// Solver aproximado por heurística gulosa ("vizinho mais próximo")
class ApproxSolver
{
    int K; // número de peões
    const std::vector<std::vector<int>> &dist;
    long long iterationCount; // contador de comparações de distância

public:
    ApproxSolver(const std::vector<std::vector<int>> &distMatrix);
    // retorna custo aproximado (ou -1) e atualiza iterationCount
    int solve();
    long long getIterationCount() const { return iterationCount; }
};

#endif // APPROXSOLVER_HPP