#include <iostream>
#include <algorithm>
int* inputArray(int size){
    int* arr = new int[size];
    for(int i = 0;i<size;i++){
        std::cout<<"Enter element "<<i<<" :";
        std::cin>>arr[i];
    }
    return arr;
}
int translateIndex(int i,int j,int sizeOfArr){
    return i*sizeOfArr+j;
}
int* findSubSeqeunce(int* seq1,int* seq2,int seqSize1,int seqSize2){
    int subSeqLengthDim = (seqSize1+1)*(seqSize2+1);
    int* subSeqLength = new int[subSeqLengthDim];
    for(int i = 0; i<subSeqLengthDim;i++)
        subSeqLength[i] = 0;
    for(int i = 1; i<seqSize1+1;i++){
        int firstSeqElement = seq1[i-1];
        for(int j = 1; j<seqSize2+1;j++){
            int secondSeqElement = seq2[j-1];
            if(firstSeqElement == secondSeqElement)
                subSeqLength[translateIndex(i,j,seqSize2)] = subSeqLength[translateIndex(i-1,j-1,seqSize2)]+1;
            else
                subSeqLength[translateIndex(i,j,seqSize2)] = std::max(subSeqLength[translateIndex(i-1,j,seqSize2)],subSeqLength[translateIndex(i,j-1,seqSize2)]);
        }
    }
    int i = seqSize1;
    int j = seqSize2;
    int maxSubSequenceLength = subSeqLength[translateIndex(i,j,seqSize2)]+1; //в первом элементе массива будем хранить его длину
    int* subSeq = new int[maxSubSequenceLength];
    subSeq[0] = maxSubSequenceLength;
    int indexCounter = 1;
    while(i && j && maxSubSequenceLength-indexCounter){
        int firstSeqElement = seq1[i-1];
        int secondSeqElement = seq2[j-1];
        if(firstSeqElement==secondSeqElement){
            subSeq[indexCounter] = firstSeqElement;
            indexCounter++;
            i--;
            j--;
        }
        else if(subSeqLength[translateIndex(i-1,j,seqSize2)]>=subSeqLength[translateIndex(i,j-1,seqSize2)])
            i--;
        else
            j--;   
    }
    delete[] subSeqLength;
    return subSeq;
}

void arrayOut(int* arr,int size){
    for(int i = 0;i<size;i++){
        std::cout<<arr[i]<<" ";
    }
}

int main(){
    int seqSize1,seqSize2;
    std::cout<<"Enter size of the first sequence: ";
    std::cin>>seqSize1;
    std::cout<<std::endl<<"Enter size of the second sequence: ";
    std::cin>>seqSize2;
    std::cout<<std::endl<<"Enter the first sequence: "<<std::endl;
    int *seq1 = inputArray(seqSize1);
    std::cout<<std::endl<<"Enter the second sequence: "<<std::endl;
    int *seq2 = inputArray(seqSize2);
    std::cout<<std::endl<<"Your sequences are:"<<std::endl;
    arrayOut(seq1,seqSize1);
    std::cout<<std::endl;
    arrayOut(seq2,seqSize2);
    int* maxSubSeq = findSubSeqeunce(seq1,seq2,seqSize1,seqSize2);
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