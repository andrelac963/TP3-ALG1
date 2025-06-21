#include "ExactSolver.hpp"

ExactSolver::ExactSolver(const std::vector<std::vector<int>> &distMatrix)
    : K((int)distMatrix.size() - 1),
      dist(distMatrix),
      iterationCount(0)
{
}

// dp[mask][i] = custo mínimo visitando o conjunto 'mask' de peões
// e terminando no ponto i.
// Complexidade ~ O(K^2 · 2^K), aqui contado em iterationCount.
int ExactSolver::solve()
{
    const int INF = 1000000000;
    int fullMask = (1 << K) - 1;
    int maxMask = 1 << K;
    iterationCount = 0;

    // inicializa DP com INF
    std::vector<std::vector<int>> dp(maxMask, std::vector<int>(K + 1, INF));
    dp[0][0] = 0;

    // para cada subconjunto de peões
    for (int mask = 0; mask < maxMask; ++mask)
    {
        for (int i = 0; i <= K; ++i)
        {
            int cur = dp[mask][i];
            if (cur == INF)
                continue;
            // tenta adicionar cada peão j não visitado
            for (int j = 1; j <= K; ++j)
            {
                ++iterationCount; // conta cada tentativa de transição
                if (!(mask & (1 << (j - 1))))
                {
                    int d = dist[i][j];
                    if (d == INF)
                        continue;
                    int nm = mask | (1 << (j - 1));
                    int cand = cur + d;
                    if (cand < dp[nm][j])
                    {
                        dp[nm][j] = cand;
                    }
                }
            }
        }
    }
    // pega melhor valor ao final
    int ans = INF;
    for (int i = 1; i <= K; ++i)
        if (dp[fullMask][i] < ans)
            ans = dp[fullMask][i];

    return (ans >= INF ? -1 : ans);
}