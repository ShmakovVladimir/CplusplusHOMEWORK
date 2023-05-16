//awk  'BEGIN{RS="\\. "}1' file
#include <codecvt>
#include <cstddef>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <thread>
#include <mutex>
#include <algorithm>
#include <set>
#include <map>
#include <iterator>
#include <numeric>
#include <sstream>
#include "logDuration.hpp"


std::mutex mtx;

double count_sim(const std::vector<std::string>& s_1, 
                 const std::vector<std::string>& s_2)
{
    std::set<std::string> unique_s1(s_1.begin(), s_1.end());
    std::set<std::string> unique_s2(s_2.begin(), s_2.end());
    std::vector<std::string> interception;
    std::vector<std::string> sets_union;
    std::set_intersection(unique_s1.begin(),
                          unique_s1.end(),
                          unique_s2.begin(),
                          unique_s2.end(),
                          std::back_inserter(interception));
    std::set_union(unique_s1.cbegin(), unique_s1.cend(),
                   unique_s2.cbegin(), unique_s2.cend(),
                   std::back_inserter(sets_union));
    return double(interception.size()) / sets_union.size();
}

void parallel_imp(const std::vector<std::vector<std::string>>& full,
                  const std::vector<std::vector<std::string>>& slice,
                  std::map<int, std::vector<int>>& result_table,
                  double t = 0.8)
{
  int indx = 0; 
  for(auto& s_1: full)
    {
        int indx_pair = 0;
        for(auto& s_2: slice)
        {
            if(indx != indx_pair & count_sim(s_1, s_2) > t)
            {
                mtx.lock();
                result_table[indx].push_back(indx_pair);
                mtx.unlock();
            }
        indx_pair++;
        }
        indx++;
    }
}

void count_result(const std::vector<std::vector<std::string>>& sentences,
                 std::map<int, std::vector<int>>& result_table,
                 int thread_q)
{
    LogDuration lg("");
    std::vector<std::thread> treads(thread_q);
    int step = sentences.size() / thread_q;   
    for(int i = 0; i < thread_q; i++)
    {
        int slice_begin = i * step;
        int slice_end = (i + 1) * step * (i != thread_q - 1) + (i == thread_q - 1) * sentences.size();
        std::vector<std::vector<std::string>> slice(slice_end - slice_begin + 1);
        
        
        std::copy(sentences.begin() + slice_begin, 
                  sentences.begin() + slice_end,
                  slice.begin());

        treads[i] = std::thread(parallel_imp,
                                sentences, 
                                slice, 
                                std::ref(result_table),
                                0.8);
        
    }
    for(auto& thread: treads)
        thread.join();
}


int main(int argc, char** argv)
{
    std::size_t slice_length = atoi(argv[1]);
    std::size_t threads_num = atoi(argv[2]);
    std::string line;
    std::string filepath = "sentences.txt";
    std::fstream file;
    std::vector<std::vector<std::string>> sentences;
    std::string sentence;
    file.open(filepath);
    while(getline(file, sentence))
    {
        std::stringstream ss(sentence);
        std::istream_iterator<std::string> begin(ss);
        std::istream_iterator<std::string> end;
        std::vector<std::string> vstrings(begin, end);
        sentences.push_back(vstrings);
    }
    std::map<int, std::vector<int>> result_table;
    double t = 0.85;
    int indx = 0;
    std::vector<std::vector<std::string>> sentences_slices(slice_length);
    std::copy(sentences.begin(), sentences.begin() + slice_length, sentences_slices.begin());
    count_result(sentences_slices, 
                 result_table, 
                 threads_num);
    
    return 0;
}
