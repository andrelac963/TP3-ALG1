#include "Board.hpp"
#include <vector>
#include <utility>

Board::Board()
    : N(0), M(0), K(0)
{
}

// Leitura de dimensões e configuração do tabuleiro
void Board::read(std::istream &in)
{
    in >> N >> M >> K;
    grid.resize(N);
    for (int i = 0; i < N; ++i)
    {
        in >> grid[i];
    }
    // coleta posição da rainha e de cada peão
    std::pair<int, int> queen;
    std::vector<std::pair<int, int>> pawns;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            char c = grid[i][j];
            if (c == 'R')
                queen = {i, j};
            else if (c == 'P')
                pawns.emplace_back(i, j);
        }
    }
    // monta vetor points: primeiro rainha, depois peões
    points.clear();
    points.reserve(K + 1);
    points.push_back(queen);
    for (auto &p : pawns)
        points.push_back(p);
}

// Para cada ponto de índice idx = 0..K, roda BFS contando cada movimento
// de rainha (qualquer número de casas em linha/coluna/diagonal) como custo 1.
void Board::computeDistances()
{
    const int INF = 1000000000;
    dist.assign(K + 1, std::vector<int>(K + 1, INF));

    // deslocamentos em 8 direções
    static const int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
    static const int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

    for (int idx = 0; idx <= K; ++idx)
    {
        // distências do BFS no grid original
        std::vector<std::vector<int>> gridDist(N, std::vector<int>(M, INF));
        std::vector<std::pair<int, int>> q;
        q.reserve(N * M);
        int head = 0;

        int sx = points[idx].first;
        int sy = points[idx].second;
        gridDist[sx][sy] = 0;
        q.emplace_back(sx, sy);

        while (head < (int)q.size())
        {
            auto [cx, cy] = q[head++];
            int cd = gridDist[cx][cy];
            // para cada direção, "varre" o raio até bloqueio ou borda
            for (int d = 0; d < 8; ++d)
            {
                int nx = cx + dx[d], ny = cy + dy[d];
                while (nx >= 0 && nx < N && ny >= 0 && ny < M && grid[nx][ny] != '-')
                {
                    if (gridDist[nx][ny] == INF)
                    {
                        gridDist[nx][ny] = cd + 1;
                        q.emplace_back(nx, ny);
                    }
                    nx += dx[d];
                    ny += dy[d];
                }
            }
        }
        // extrai distância a cada outro ponto de interesse
        for (int j = 0; j <= K; ++j)
        {
            auto [tx, ty] = points[j];
            dist[idx][j] = gridDist[tx][ty];
        }
    }
}