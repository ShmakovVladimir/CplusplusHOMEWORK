#include <iostream>
#include <random>
#include <chrono>
#include <fstream>
#include <string.h>
#include "logDuration.hpp"

bool inCircle(double x, double y)
{
    return (pow(x, 2) + pow(y, 2) < 1);
}


int main(int argc, char** argv)
{
    // Инициализация генератора равномерно распределённых случайных чисел
    std::mt19937_64 rng;
    // initialize the random number generator with time-dependent seed
    uint64_t timeSeed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
    std::seed_seq ss{uint32_t(timeSeed & 0xffffffff), uint32_t(timeSeed>>32)};
    rng.seed(ss);
    // initialize a uniform distribution between 0 and 1
    std::uniform_real_distribution<double> unif(0, 1);
    unsigned long long int inside_circle = 0;
    unsigned long long int iteration_max = pow(10, 5);
    std::string filepath = "exp_1.txt";
    std::ofstream output;
    output.open(filepath);
    LogDuration lg("");
    for(unsigned long long int i = 0; i < iteration_max; i++)
    {
        double x = unif(rng);
        double y = unif(rng);
        inside_circle += inCircle(x, y);
        output << 4 * double(inside_circle) / (i + 1) << std::endl;    
    }

    return 0;
}