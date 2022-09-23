#include <iostream>

void function(int alpha){
    std::cout<<"Integer function";
}
void function(float alpha){
    std::cout<<"Float function";
}

int main(){
    int alpha = 5;
    function((float)alpha);
    return 0;
}