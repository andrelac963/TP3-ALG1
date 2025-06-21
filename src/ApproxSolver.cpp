#include "ApproxSolver.hpp"

ApproxSolver::ApproxSolver(const std::vector<std::vector<int>> &distMatrix)
    : K((int)distMatrix.size() - 1),
      dist(distMatrix),
      iterationCount(0)
{
}

// Em cada um dos K passos escolhe o peão mais próximo ainda não visitado.
// Contabiliza em iterationCount cada comparação de dist[cur][j].
int ApproxSolver::solve()
{
    const int INF = 1000000000;
    iterationCount = 0;
    int mask = 0, curr = 0, total = 0;

    for (int step = 0; step < K; ++step)
    {
        int bestD = INF, bestJ = -1;
        for (int j = 1; j <= K; ++j)
        {
            ++iterationCount; // uma iteração de comparação
            if (!(mask & (1 << (j - 1))))
            {
                int d = dist[curr][j];
                if (d < bestD)
                {
                    bestD = d;
                    bestJ = j;
                }
            }
        }
        if (bestJ < 0 || bestD >= INF)
            return -1; // inacessível
        total += bestD;
        mask |= (1 << (bestJ - 1));
        curr = bestJ;
    }
    return total;
}