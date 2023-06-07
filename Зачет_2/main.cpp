#include <iostream>
#include <thread>
#include <vector>
#include <algorithm>
#include "matrix.hpp"

Matrix get_lower_matrix(Matrix& A)
{
    auto result = Matrix(A.get_cols(), A.get_rows(), false);
    for(int i = 0; i < A.get_cols(); i++)
    {
        for(int j = 0; j < A.get_cols(); j++)
        {
            if(i < j)
                result(i, j) = A(i, j);
        }
    }
    return result;
}


Matrix get_upper_matrix(Matrix& A)
{
    auto result = Matrix(A.get_cols(), A.get_rows(), false);
    for(int i = 0; i < A.get_cols(); i++)
    {
        for(int j = 0; j < A.get_cols(); j++)
        {
            if(i > j)
                result(i, j) = A(i, j);
        }
    }
    return result;
}

Matrix get_dioganal_matrix(Matrix& A)
{
    auto result = Matrix(A.get_cols(), A.get_rows(), false);
    for(int i = 0; i < A.get_cols(); i++)
    {
        for(int j = 0; j < A.get_cols(); j++)
        {
            if(i == j)
                result(i, j) = A(i, j);
        }
    }
    return result;
}

Matrix get_x(Matrix L, Matrix U, Matrix D)
{
    std::size_t iteration_count =  int(1e4);
    auto x = Matrix(1, L.get_cols(), false, 1);
    
}


int main()
{
    int N = 1000;

    auto A_matrix = Matrix(N, N, true, 1);
    auto b_matrix = Matrix(1, N, true, 1);
    auto U_matrix = get_upper_matrix(A_matrix);
    auto L_matrix = get_lower_matrix(A_matrix);
    auto D_matrix = get_dioganal_matrix(A_matrix);
    
    return 0;
}