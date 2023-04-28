#include <iostream>
#include <chrono>
#include <vector>
#include <thread>
#include <future>
#include "logDuration.hpp"
#include "matrix.hpp"




int main(int argc, char** argv)
{
    auto A = Matrix(atoi(argv[1]), atoi(argv[2]), true, atoi(argv[5]));
    auto B = Matrix(atoi(argv[3]), atoi(argv[4]), true, atoi(argv[5]));
    
    std::ofstream out_a;
    out_a.open("A.txt");
    std::ofstream out_b;
    out_b.open("B.txt");
    std::ofstream out_c;
    out_c.open("C.txt");

    A.write_matrix(out_a);
    B.write_matrix(out_b);

    Matrix C = A*B;
    C.write_matrix(out_c);

    std::cout << "Тут вывод времени выполнения";
    return 0;
}