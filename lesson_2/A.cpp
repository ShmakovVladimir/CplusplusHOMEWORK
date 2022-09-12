#include <iostream>
#include <algorithm>
void swap(float* a,float* b){
    *a*=(*b); 
    *b = (*a)/(*b); 
    *a/=(*b);
}
int translate(int i,int j,int arraySecondDimentionLength){
    return i*arraySecondDimentionLength+j;
}

void multMatrixString(float* matrix,int secondDim,int string,float multiplier){
    for(int col = 0;col<secondDim;col++){
        matrix[translate(string,col,secondDim)]*=multiplier;
    }
}
void subMatrixStrings(float* matrix,int firstDim,int secondDim,int string1,int string2,float multiplier){
    for(int col = 0;col<secondDim;col++){
        matrix[translate(string1,col,secondDim)]-=(matrix[translate(string2,col,secondDim)]*multiplier);
    }
}
void steppedView(float* matrix,int firstDim, int secondDim){
    //на <<диоганали>> матрицы ставим единицы
    int maxQuadraticSize = std::max(firstDim,secondDim);
    for(int col = 0;col<maxQuadraticSize;col++){
        multMatrixString(matrix,secondDim,col,1/(matrix[translate(col,col,secondDim)]));
    }
    for(int col = 0;col<maxQuadraticSize;col++){
        for(int i = 0;i<secondDim;i++){
            if(col!=i){
                subMatrixStrings(matrix,firstDim,secondDim,col,i,matrix[translate(col,col,secondDim)]);
            }
        }
    }

}

void outputMatrix(float* matrix,int firstDim,int secondDim){
    for(int i = 0;i<firstDim;i++){
        for(int j = 0;j<secondDim;j++){
            std::cout<<matrix[translate(i,j,secondDim)]<<" ";
        }
        std::cout<<std::endl;
    }
}


int main(){
    int eqQ,variablesQ;
    std::cout<<"Enter number of equations: ";
    std::cin>>eqQ;
    std::cout<<"Enter number of variables: ";
    std::cin>>variablesQ;
    int matrixColumnQ = variablesQ+1;
    int matrixStringQ = eqQ; //в последней строке закодруем номера переменных
    int systemMatrixArrayLength = matrixColumnQ*(matrixStringQ);
    float* systemMatrix = new float[matrixColumnQ*eqQ];
    for(int col = 0; col < matrixColumnQ;col++){
        if(col == matrixColumnQ-1)
            std::cout<<std::endl<<"Enter column of free variables: ";
        else
            std::cout<<std::endl<<"Enter a column of coefficients before x"<<col+1<<": ";
        for(int i = 0;i<eqQ;i++){
            std::cout<<"- :";
            std::cin>>systemMatrix[translate(i,col,matrixColumnQ)];
        }
    }
    std::cout<<std::endl<<"Your extended system matrix is: "<<std::endl;
    outputMatrix(systemMatrix,matrixStringQ,matrixColumnQ);
    std::cout<<std::endl<<"stepped matrix is: "<<std::endl;
    steppedView(systemMatrix,matrixStringQ,matrixColumnQ);
    outputMatrix(systemMatrix,matrixStringQ,matrixColumnQ);


    delete[] systemMatrix;
    return 0;
}