#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <cmath>

struct something
{
    long long int a[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    long long int b[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    long long int c[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    long long int d[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    long long int e[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    long long int f[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    long long int g[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    long long int h[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    long long int i[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    long long int j[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    long long int k[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    long long int l[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    long long int m[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    long long int n[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
};

int main()
{
    something somethingBig;
    std::vector<something> someVector;
	std::string exp1_filePath = "exp3.txt";
	std::ofstream exp1;
	exp1.open(exp1_filePath, std::ofstream::trunc);
	unsigned long int expSize = std::pow(10, 7);
	for(unsigned long int i = 0; i < expSize; i++)
	{
		exp1 << std::to_string(someVector.capacity()) << "\n";
		someVector.push_back(somethingBig);
	}
	
	exp1.close();
	return 0;
}