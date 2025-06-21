#ifndef TIMER_HPP
#define TIMER_HPP

#include <chrono>

// Classe para medir intervalos de tempo em milissegundos
class Timer
{
    using clock = std::chrono::high_resolution_clock;
    clock::time_point t_start;

public:
    // Inicia a contagem
    void start()
    {
        t_start = clock::now();
    }
    // Retorna milissegundos desde start()
    double elapsed() const
    {
        using namespace std::chrono;
        return duration_cast<duration<double, std::milli>>(
                   clock::now() - t_start)
            .count();
    }
};

#endif // TIMER_HPP