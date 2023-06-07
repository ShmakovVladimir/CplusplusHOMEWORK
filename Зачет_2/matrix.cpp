#include "matrix.hpp"


Matrix::Matrix(std::size_t first_dim, std::size_t second_dim,  bool random_fill, std::size_t threads_num): 
                                                                rows_num{first_dim}, 
                                                                columns_num{second_dim}, 
                                                                threads_num {threads_num}
{
    data = new long int[int(rows_num * columns_num)];
    for(int i = 0; i < rows_num * columns_num; i++)
        data[i] = (rand() % max_matrix_element) * random_fill;
}

Matrix::~Matrix()
{
    delete[] data;
}

void Matrix::write_matrix(std::ofstream &out_file)
{
    for(int row = 0; row < rows_num; row++)
    {
        for(int col = 0; col < columns_num; col++)
        {
            out_file << data[row * columns_num + col] << " ";
        }
        out_file << "\n";
    }
}


Matrix Matrix::operator*(Matrix& b)
{
    LogDuration lg("");
    Matrix result(rows_num, b.get_cols(), false);
    std::vector<std::thread> threads(threads_num);
    int row_split_step = int(rows_num / threads_num);
    int end = 0;
    for(int thread_ind = 0; thread_ind < threads_num; thread_ind++)
    {
        int start = end;
        end += row_split_step + 1;
        if(thread_ind == threads_num - 1)
            end = rows_num;
        threads[thread_ind] = std::thread(&Matrix::matrix_multiplication_split, 
                                          this, 
                                          std::ref(b), 
                                          std::ref(result), 
                                          start, 
                                          end);
    }
    for(int thread_ind = 0; thread_ind < threads_num; thread_ind++)
    {
        threads[thread_ind].join();   
    }
    return result;
}

void Matrix::matrix_multiplication_split(Matrix& b, Matrix& result, int row_start, int row_end)
{
    int b_rows_num = b.get_rows();
    int b_cols_num = b.get_cols();
    for(int a_row = row_start; a_row < row_end; a_row++)
    {
        int a_plus_ind = a_row * rows_num;
        for(int b_col = 0; b_col < b_cols_num; b_col++ )
        {
            int result_ind = a_plus_ind + b_col;
            for(int n = 0; n < columns_num; n++)
            {
                result.data[result_ind] += data[a_plus_ind + n] * b.data[n * b_rows_num + b_col];
            }
        }
    }
}

Matrix Matrix::operator+(Matrix& b)
{
    auto result = Matrix(rows_num, columns_num, false);
    for(int i = 0; i < rows_num; i++)
    {
        for(int j = 0; j < columns_num; j++)
        {
            result(i, j) = this->operator()(i, j) + b(i, j);
        }
    }
    return result;
}