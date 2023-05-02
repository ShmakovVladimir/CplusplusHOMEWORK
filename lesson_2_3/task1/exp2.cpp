#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <cmath>

int main(int argv, char** argc)
{
    std::vector<int> reserveVector{20, 300, 1000};
    int expNumber = 1;
	for(auto it = reserveVector.begin(); it != reserveVector.end(); it++, expNumber++)
    {
        std::vector<int> someVector;
        someVector.reserve(*it);
        std::string expFilePath = "exp2_"+ std::to_string(expNumber) + ".txt";
        std::ofstream exp1;
        exp1.open(expFilePath, std::ofstream::trunc);
        unsigned long int expSize = std::pow(10, 3);
        for(unsigned long int i = 0; i < expSize; i++)
        {
            exp1 << std::to_string(someVector.capacity()) << "\n";
            someVector.push_back(rand());
        }
        
        exp1.close();
    }
	return 0;
}
