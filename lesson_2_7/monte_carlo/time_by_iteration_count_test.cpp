#include <iostream>
#include <fstream>
#include <mutex>
#include <thread>
#include <chrono>
#include <random>
#include "logDuration.hpp"
#include <cmath>
#include <vector>
#include <cstddef>
#include <future>

std::mutex mtx;

bool inCircle(double x, double y)
{
    return (pow(x, 2) + pow(y, 2) < 1);
}


void pi_estimation(unsigned long long int& iteration_max, 
                   unsigned long long int& inside_circle,
                   int threads_q)
{
    std::mt19937_64 rng;
    uint64_t timeSeed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
    std::seed_seq ss{uint32_t(timeSeed & 0xffffffff), uint32_t(timeSeed>>32)};
    rng.seed(ss);
    std::uniform_real_distribution<double> unif(0, 1);

    for(long long int i = 0; i < iteration_max / threads_q; i++)
    {
        double x = unif(rng);
        double y = unif(rng);
        bool inside = inCircle(x, y);
        inside_circle += inside;    
    }
}



int main(int argc, char** argv)
{
    unsigned long long int inside_circle = 0;
    unsigned long long int iteration_max = atoi(argv[1]);
    int thread_q = atoi(argv[2]);
    std::vector<std::thread> threads(thread_q);
    
    for (std::size_t i = 0; i < thread_q; i++)
	{
        threads[i] = std::thread(pi_estimation, std::ref(iteration_max), std::ref(inside_circle), thread_q);
    }
    LogDuration lg("");
    for (std::size_t i = 0; i < thread_q; i++)
        threads[i].join();
    std::cout << 4 * double(inside_circle) / iteration_max << ' ';
    return 0;
}