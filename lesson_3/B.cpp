#include <iostream>
#include <C:\Programs\eigen/Eigen/Dense>
#include <cmath>
// path to eigen C:\Programs\eigen

const int linearOperatorMatrixSize = 3; //не надо напрягаться - надо радоваться, поэтому так и написал

// норма разности
float NSEFunction(const Eigen::Matrix<float,linearOperatorMatrixSize,1>* bPrev,const Eigen::Matrix<float,linearOperatorMatrixSize,1>* b){
    return (*bPrev-*b).norm();
}
// квадрат нормы
float SNSEFunction(const Eigen::Matrix<float,linearOperatorMatrixSize,1>* bPrev,const Eigen::Matrix<float,linearOperatorMatrixSize,1>* b){
    return (*bPrev-*b).squaredNorm();
}


Eigen::Matrix<float,linearOperatorMatrixSize,1> findEigenVectorAlgo(const Eigen::Matrix<float,linearOperatorMatrixSize,linearOperatorMatrixSize>* A,
                                                                    float(* errorFunction)(const Eigen::Matrix<float,linearOperatorMatrixSize,1>* bPrev,const Eigen::Matrix<float,linearOperatorMatrixSize,1>* b)){
    Eigen::Matrix<float, linearOperatorMatrixSize, 1> bStart;
    Eigen::Matrix<float, linearOperatorMatrixSize, 1> b;
    //так очень плохо писать, но пока не разобрался с автоматической генерацией рандомного вектора, заданного размера linearOperatorMatrixSize
    bStart<<1,0,0;
    b<<rand()%100,rand()%100,rand()%100;
    int maxIterationsNumber = 5000000;
    float eps = pow(10,-5);
    for(int i = 0;i<maxIterationsNumber&&errorFunction(&bStart,&b)>eps;i++){
        bStart = b;
        b = (*A)*bStart;
        b /= b.norm();
    }
    return b;
}

int main(){
    Eigen::Matrix<float, linearOperatorMatrixSize, linearOperatorMatrixSize> linearOperatorMatrix;
    
    linearOperatorMatrix << -2,-1,0,
                            1,-1,-2,
                            1,-1,-2;
    std::cout<<"Your linear operator matrix is: "<<std::endl;
    std::cout<<std::endl<<linearOperatorMatrix;
    auto eigenVector = findEigenVectorAlgo(&linearOperatorMatrix,&NSEFunction);
    std::cout<<std::endl<<"Your eigen vector is(first error function): "<<std::endl;
    std::cout<<eigenVector;
    eigenVector = findEigenVectorAlgo(&linearOperatorMatrix,&SNSEFunction);
    std::cout<<std::endl<<"Your eigen vector is(second error function): "<<std::endl;
    std::cout<<eigenVector;
    return 0;
}