#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <cmath>

int main()
{
	std::vector<int> someVector;
	std::string exp1_filePath = "exp1.txt";
	std::ofstream exp1;
	exp1.open(exp1_filePath, std::ofstream::trunc);
	unsigned long int expSize = std::pow(10, 3);
	for(unsigned long int i = 0; i < expSize; i++)
	{
		exp1 << std::to_string(someVector.capacity()) << "\n";
		someVector.push_back(rand());
	}
	
	exp1.close();
	return 0;
}
