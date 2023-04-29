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
    // if (!(b.get_cols() - rows_num))
    //      std::cout << "Error" << std::endl;
    Matrix result(rows_num, b.get_cols(), false);
    std::vector<std::thread> threads(threads_num);
    int row_split_step = int(rows_num / threads_num);
    for(int thread_ind = 0; thread_ind < threads_num; thread_ind++)
    {
        int start = thread_ind * row_split_step;
        int end = (thread_ind + 1) * row_split_step;
        if(thread_ind == threads_num - 1)
            end = rows_num;
        //matrix_multiplication_split(b, result, start, end);
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
    for(int a_row = row_start; a_row < row_end; a_row++)
    {
        int a_pl_index = a_row * rows_num;
        for(int b_col = 0; b_col < b.get_cols(); b_col++)
        {
            for(int n = 0; n < columns_num; n++)
            {
                result(a_row, b_col) += b.data[n * b_rows_num + b_col] * data[a_pl_index + n];
            }
        }
    }
}