#include <iostream>
#include <thread>
 
int main() {
    std::cout << std::thread::hardware_concurrency() << " concurrent threads are supported.\n";
    return 0;
}