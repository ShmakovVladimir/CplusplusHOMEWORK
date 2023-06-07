#include <iostream>
#include <iterator>
#include <thread>
#include <vector>
#include <algorithm>
#include <fstream>
#include <random>
#include <chrono>
#include <mutex>

std::mutex mtx;

void fill_row(std::vector<double> & row)
{
    std::mt19937_64 rng;
    // initialize the random number generator with time-dependent seed
    uint64_t timeSeed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
    std::seed_seq ss{uint32_t(timeSeed & 0xffffffff), uint32_t(timeSeed>>32)};
    rng.seed(ss);
    std::uniform_real_distribution<double> unif(1, 100);
    for(int i = 0; i < row.size(); i++)
        row[i] = unif(rng);
}

void fill_matrix(std::vector<std::vector<double>> & mat)
{
    std::for_each(mat.begin(), mat.end(), fill_row);
}

std::vector<std::vector<double>> transpose(std::vector<std::vector<double>> &b)
{
    std::vector<std::vector<double>> trans_vec(b.size(), std::vector<double>(b.size()));

    for(int i=0;i<b.size();i++)
    {
        for(int j=0;j<b[i].size();j++)
        {
            trans_vec[j][i]=b[i][j];
        }
    }
    return trans_vec;
}

void write_matrix(std::ofstream& out_file, 
                 std::vector<std::vector<double>> & mat)
{
    for(int row = 0; row < mat.size(); row++)
    {
        for(int col = 0; col < mat.size(); col++)
        {
            out_file << mat[row][col] << " ";
        }
        out_file << "\n";
    }
}

std::vector<std::vector<double>> mult(std::vector<std::vector<double>>& A, std::vector<std::vector<double>>& B)
{
    std::vector<std::vector<double>> result(A.size(), std::vector<double>(A.size()));
    for(int i = 0; i < A.size(); i++)
    {
        for(int j = 0; j < A.size(); j++)
        {
            for(int n = 0; n < A.size(); n++)
            {
                result[i][j] = A[i][n] + B[n][j];
            }
        }
    }
    return result;
}

void write_matrix(std::ofstream& out_file, 
                 std::vector<double> & mat)
{
    for(int i = 0; i < mat.size(); i++)
        out_file << mat[i] << " ";
}

void gauss_seidel(std::vector<std::vector<double>>& A,
                  std::vector<double>& b,
                  std::vector<double>& x,
                  const int start,
                  const int end)
{

    std::size_t iteration_count = 1000;
    for (int k = 0; k < iteration_count; k++) {
        for (int i = start; i < end; i++) {
            long double new_x = b[i];
            for (int j = 0; j < A.size(); ++j) {
                if (j != i) {
                    new_x -= A[j][i] * x[j];
                }
            }
            new_x /= A[i][i];
            x[i] = new_x;
        }
    }
}



int main()
{
    std::size_t matrix_size = 3;
    std::vector<std::vector<double>> A_1(matrix_size, std::vector<double>(matrix_size));
    auto A_transposed = transpose(A_1);
    std::cout<<"trans";
    auto A = mult(A_1, A_transposed);
    std::vector<double> b(matrix_size);
    std::vector<double> x(matrix_size, 0.0);

    int threads_num = 1;

    fill_matrix(A);
    fill_row(b);
    fill_row(x);


    auto A_file = std::ofstream("A.txt");
    auto b_file = std::ofstream("b.txt");
    write_matrix(A_file, A);
    write_matrix(b_file, b);

    std::vector<std::thread> threads(threads_num);
    for (int i = 0; i < threads_num; ++i) {
        int start = i * matrix_size / threads_num;
        int end = (i + 1) * matrix_size / threads_num;
        if(i == threads_num - 1)
            end = matrix_size - 1;
        threads[i] = std::thread(gauss_seidel, 
                                std::ref(A), 
                                std::ref(b), 
                                std::ref(x), 
                                start, 
                                end);
    }


    for (int i = 0; i < threads_num; ++i) {
        threads[i].join();
    }

    auto x_file = std::ofstream("x.txt");
    write_matrix(x_file, x);
    std::cout << "It's okay" << std::endl;
    return 0;
}