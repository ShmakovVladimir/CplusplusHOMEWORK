#include <iostream>
#include <thread>
#include <mutex>
#include <vector>

template <typename type>
void MergeSort(std::vector<type> &arr, std::size_t thread_num = 4)
{
    void merge_sort(int start, int end)
    {
        if(start > end)
            return 
        int mid = (start + end) / 2
        merge_sort(start, mid);
        merge_sort(mid + 1, start);
        merge(start, mid, end);
    }

    void merge(int start, int middle, int end)
    {
        int left_pointer = start;
        int right_pointer = end;
        
    }
}


int main(int argc, char** argv)
{



    return 0;
}