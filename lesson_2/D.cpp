#include <iostream>


int translate(int i,int j,int numberOfCollumns){
    return i*numberOfCollumns+j;
}

int* LCS(int* sequnce1,int* sequence2,int firstSequenceLength,int secondSequenceLength){
    int sliceLengthArrDim = (firstSequenceLength+1)*(secondSequenceLength+1);
    int* sliceLength  = new int[sliceLengthArrDim];
    for(int i = 0;i<sliceLengthArrDim;i++){
        sliceLength[i] = 0;
    }

    for(int i = 1;i<=firstSequenceLength;i++){
        int firstSeqElement = sequnce1[i-1];
        for(int j = 1;j<=secondSequenceLength;j++){
            int secondSeqElement = sequence2[j-1];
            int left = sliceLength[translate(i,j-1,secondSequenceLength+1)];
            int up = sliceLength[translate(i-1,j,secondSequenceLength+1)];
            int diagonal = sliceLength[translate(i-1,j-1,secondSequenceLength+1)];
            if(secondSeqElement==firstSeqElement)
                sliceLength[translate(i,j,secondSequenceLength+1)] = diagonal+1;
            else
                sliceLength[translate(i,j,secondSequenceLength+1)] = std::max(left,up);
        }
    }
    int lcsLength = sliceLength[sliceLengthArrDim-1]+1; //по нулевому индексу храним длину НОП
    int* lcs = new int[lcsLength];
    lcs[0] = lcsLength;
    int i = firstSequenceLength;
    int j = secondSequenceLength;
    int indexCounter = 1;
    while(lcsLength>indexCounter&&i&&j){
        int left = sliceLength[translate(i,j-1,secondSequenceLength+1)];
        int up = sliceLength[translate(i-1,j,secondSequenceLength+1)];
        if(sequnce1[i-1]==sequence2[j-1]){
            lcs[indexCounter] = sequnce1[i-1];
            i--;
            j--;
            indexCounter++;
        }
        else if(left>up)
            j--;
        else
            i--;  
    }
    delete[] sliceLength; 
    return lcs;
}
void arrayOut(int* arr,int size){
    for(int i = 0;i<size;i++){
        std::cout<<arr[i]<<" ";
    }
}
int* inputArray(int size){
    int* arr = new int[size];
    for(int i = 0;i<size;i++){
        std::cout<<"Enter element "<<i<<" :";
        std::cin>>arr[i];
    }
    return arr;
}
int main(){
    int seqSize1,seqSize2;
    std::cout<<"Enter size of the first sequence: ";
    std::cin>>seqSize1;
    std::cout<<"Enter size of the second sequence: ";
    std::cin>>seqSize2;
    std::cout<<std::endl<<"Enter the first sequence: "<<std::endl;
    int *seq1 = inputArray(seqSize1);
    std::cout<<std::endl<<"Enter the second sequence: "<<std::endl;
    int *seq2 = inputArray(seqSize2);
    std::cout<<std::endl<<"Your sequences are:"<<std::endl;
    arrayOut(seq1,seqSize1);
    std::cout<<std::endl;
    arrayOut(seq2,seqSize2);
    int* maxSubSeq = LCS(seq1,seq2,seqSize1,seqSize2);
    std::cout<<std::endl<<"Greatest sub sequence length is: "<<maxSubSeq[0]-1;
    std::cout<<std::endl<<"Greatest sub sequence is: ";
    for(int i = maxSubSeq[0]-1;i>0;i--){
        std::cout<<maxSubSeq[i]<<" ";
    }
    delete[] seq1;
    delete[] seq2;
    delete[] maxSubSeq;
    return 0;
}