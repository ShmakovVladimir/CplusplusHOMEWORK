#include <iostream>
#include <math.h>
float* dataInput(){
    float* factors = new float[3];
    std::cout<<"Enter a: ";
    std::cin>>factors[0];
    std::cout<<std::endl<<"Enter b:";
    std::cin>>factors[1];
    std::cout<<std::endl<<"Enter c:";
    std::cin>>factors[2];
    return factors;
}
void solveAndOutputQuadraticEq(float* factors){
    float eps = pow(10,-5);
    float d = pow(factors[1],2)-4*factors[0]*factors[2];
    std::cout<<std::endl<<"_________________\n"<<"Answer:\n";
    if (abs(d) <= eps){ //считаем дискриминант равным нулю
        std::cout<<"The only answer is: "<<(-1)*factors[1]/(2*factors[0]);
    }
    else if(d<0){
        std::cout<<"There are no answers at all(";
    }
    else{
        std::cout<<"The first answer is: "<<((-1)*factors[1]+sqrt(d))/(2*factors[0])<<std::endl;
        std::cout<<"The second answer is: "<<((-1)*factors[1]-sqrt(d))/(2*factors[0]);
    }
    delete []factors; 
}

int main(){
    solveAndOutputQuadraticEq(dataInput());
    return 0;
}