#ifndef BOARD_HPP
#define BOARD_HPP

#include <vector>
#include <string>
#include <utility>
#include <istream>

// Representa o tabuleiro, posições de interesse e matriz de distâncias
class Board
{
public:
    int N, M,                                // dimensões
        K;                                   // número de peões
    std::vector<std::string> grid;           // mapa do tabuleiro
    std::vector<std::pair<int, int>> points; // [0]=rainha, [1..K]=peões
    std::vector<std::vector<int>> dist;      // (K+1)x(K+1) de distâncias

    Board();
    // Lê N M K e o grid; coleta posição da rainha e dos peões
    void read(std::istream &in);
    // Para cada ponto de interesse (0..K), roda BFS de "raio de rainha"
    // e preenche dist[i][j]
    void computeDistances();
};

#endif // BOARD_HPP