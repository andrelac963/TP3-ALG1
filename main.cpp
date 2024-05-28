#include <iostream>
#include <vector>
#include <set>
#include <list>
#include <algorithm>

using namespace std;

class Cristal
{
public:
    // Cordenadas
    int x, y;
    // Brilho
    int v;
    // Conexões
    int d, c, e, b;
};

int main()
{
    int L, C, N;

    scanf("%d %d %d", &L, &C, &N);

    vector<Cristal> cristais(N);

    for (int i = 0; i < N; i++)
    {
        int x, y, v, d, c, e, b;
        scanf("%d %d %d %d %d %d %d", &x, &y, &v, &d, &c, &e, &b);
        cristais[i] = {x, y, v, d, c, e, b};
    }

    // Solução inicial: pegar todos os cristais
    vector<Cristal> solution = cristais;
    int totalValue = 0;
    for (auto &crystal : solution)
    {
        totalValue += crystal.v;
    }

    // Tentar remover cada cristal e verificar se a solução ainda é válida
    for (int i = 0; i < solution.size(); i++)
    {
        Cristal removed = solution[i];
        solution.erase(solution.begin() + i);
        bool valid = true;
        for (auto &crystal : solution)
        {
            if ((abs(crystal.x - removed.x) == 1 && crystal.y == removed.y) ||
                (abs(crystal.y - removed.y) == 1 && crystal.x == removed.x))
            {
                valid = false;
                break;
            }
        }
        if (valid)
        {
            totalValue -= removed.v;
        }
        else
        {
            solution.insert(solution.begin() + i, removed);
        }
    }

    cout << solution.size() << " " << totalValue << "\n";
    for (auto &crystal : solution)
    {
        cout << crystal.x << " " << crystal.y << "\n";
    }

    return 0;
}