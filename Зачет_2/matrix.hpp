#pragma once
#include <chrono>
#include <vector>
#include <thread>
#include <future>
#include <fstream>
#include <iostream>
#include "logDuration.hpp"
#include <mutex>



class Matrix
{
public:
    Matrix(std::size_t first_dim, std::size_t second_dim, bool random_fill = true, std::size_t threads_num = 4);
    ~Matrix();
    std::size_t get_cols() { return columns_num; };
    std::size_t get_rows() { return rows_num; };
    inline long int& operator()(std::size_t row, std::size_t col) { return data[row * rows_num + col]; };
    void write_matrix(std::ofstream &out_file);
    Matrix operator*(Matrix& b);
    Matrix operator+(Matrix& b);
    long int *data;
private:
    void matrix_multiplication_split(Matrix& b, Matrix& result, int row_start, int row_end);
    std::size_t rows_num;
    std::size_t columns_num;
    std::size_t threads_num;
    long int max_matrix_element = int(1e6);
};