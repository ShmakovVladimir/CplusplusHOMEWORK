#include <iostream>
#include <thread>
#include <mutex>
#include <vector>

template <typename type>
void MergeSort(std::vector<type> &arr, std::size_t thread_num = 4)
{
    // MergeSort(A, p, r):
    // if p > r 
    //     return
    // q = (p+r)/2
    // mergeSort(A, p, q)
    // mergeSort(A, q+1, r)
    // merge(A, p, q, r)
    void merge_sort(int start, int end)
    {
        if(start > end)
            return 
        int mid = (start + end) / 2
        merge_sort(start, mid);
        merge_sort(mid + 1, start);
        merge(start, mid, end);
    }
}


int main(int argc, char** argv)
{



    return 0;
}