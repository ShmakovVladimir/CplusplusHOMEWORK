#include <iostream>
#include <algorithm>

void swap(float* a,float* b){
    float c = *a;
    *a = *b;
    *b = c;
}
int translate(int i,int j,int secondDimention){
    return i*secondDimention+j;
}
void subStrings(float* matrix,int secondDimention,int string1,int string2,float cff){
    for(int col = 0;col<secondDimention;col++){
        matrix[translate(string1,col,secondDimention)]-=(cff*matrix[translate(string2,col,secondDimention)]);
    }
}
void divStringByNumber(float* matrix,int secondDimention,int string,float number){
    for(int col = 0;col<secondDimention;col++){
        matrix[translate(string,col,secondDimention)]/=number;
    }
}
void swapStrings(float* matrix,int secondDimention,int string1,int string2){
    for(int col = 0;col<secondDimention;col++){
        swap(&matrix[translate(string1,col,secondDimention)],&matrix[translate(string2,col,secondDimention)]);
    }
}
void matrixOutput(float* matrix,int firstDimention,int secondDimention){
    for(int i = 0;i<firstDimention;i++){
        for(int col = 0;col<secondDimention;col++){
            std::cout<<matrix[translate(i,col,secondDimention)]<<"   ";
        }
        std::cout<<std::endl;
    }
}
void steppedMatrix(float * matrix,int firstDimention,int secondDimention){
    for(int col = 0;col<std::min<int>(secondDimention,firstDimention);col++){
        int nonZeroString = col;
        while(nonZeroString<firstDimention&&!matrix[translate(nonZeroString,col,secondDimention)])
            nonZeroString++;
        if(nonZeroString<firstDimention){
            divStringByNumber(matrix,secondDimention,nonZeroString,matrix[translate(nonZeroString,col,secondDimention)]);
            if(nonZeroString!=col)
                swapStrings(matrix,secondDimention,nonZeroString,col);
            for(int i = 0;i<firstDimention;i++){
                if(i!=col){
                    subStrings(matrix,secondDimention,i,col,matrix[translate(i,col,secondDimention)]);
                }
            }
        }
    }  
    // std::cout<<std::endl;
    // matrixOutput(matrix,firstDimention,secondDimention);
}

int main(){
    int numberOfCol,numberOfStrings;
    std::cout<<"Enter number of variables: ";
    std::cin>>numberOfCol;
    numberOfCol++;
    std::cout<<"Enter number of the equations: ";
    std::cin>>numberOfStrings;
    float* systemMatrix = new float[numberOfCol*numberOfStrings];
    for(int col = 0;col<numberOfCol;col++){
        if(col==numberOfCol-1)
            std::cout<<"enter the b: ";
        else
            std::cout<<"enter x"<<col+1<<" coefficients: ";
    
        for(int i = 0;i<numberOfStrings;i++){
            std::cout<<"- : ";
            std::cin>>systemMatrix[translate(i,col,numberOfCol)];
        }
        std::cout<<std::endl;
    }
    std::cout<<std::endl<<"Your system matrix is: "<<std::endl;
    matrixOutput(systemMatrix,numberOfStrings,numberOfCol);
    std::cout<<std::endl;
    steppedMatrix(systemMatrix,numberOfStrings,numberOfCol);
    std::cout<<std::endl<<"Reduced matrix: " <<std::endl; 

    matrixOutput(systemMatrix,numberOfStrings,numberOfCol);
    std::cout<<std::endl<<"Solved"<<std::endl;
    for(int i = 0;i<numberOfCol-1;i++){
        std::cout<<"x"<<i+1<<" = "<<systemMatrix[translate(i,numberOfCol-1,numberOfCol)]<<std::endl;
    }
    delete[] systemMatrix;
    return 0;
}