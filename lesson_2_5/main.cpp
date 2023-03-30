#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>

int counter()
{
    static int pos = 0;
    return ++pos;
}


int main()
{
    std::vector<int> sequence(10);
    std::generate(sequence.begin(), sequence.end(), counter);
    std::cout << "Пункт 1:" << std::endl;
    for(auto num: sequence)
        std::cout << num << " ";
    std::cout << std::endl;
	
    
    return 0;
}
