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


void pi_estimation(std::ofstream& output, 
                   unsigned long long int& iteration_max, 
                   unsigned long long int& inside_circle,
                   int threads_q,
                   unsigned long long int& iteration_q)
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
        mtx.lock();
        iteration_q += 1;
        inside_circle += inside;
        output << 4 * double(inside_circle) / iteration_q << std::endl;    
        mtx.unlock();
    }
}



int main()
{
    std::ofstream output;
    output.open("exp_2.txt");
    unsigned long long int inside_circle = 0;
    unsigned long long int iteration_max = pow(10, 5);
    unsigned long long int iteration_q = 0;
    int thread_q = 8;
    std::vector<std::thread> threads(thread_q);
    
    for (std::size_t i = 0; i < thread_q; i++)
	{
        threads[i] = std::thread(pi_estimation, std::ref(output), std::ref(iteration_max), std::ref(inside_circle), thread_q, std::ref(iteration_q));
    }
    LogDuration lg("");
    for (std::size_t i = 0; i < thread_q; i++)
        threads[i].join();
    return 0;
}