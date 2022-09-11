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
int translateIndex(int i,int j,int sizeX){
    return i*sizeX+j;
}
int* findSubSeqeunce(int* seq1,int* seq2,int seqSize1,int seqSize2){
    int dynamicArrayLength = seqSize1*seqSize2;
    int* subLength = new int[dynamicArrayLength];
    for(int i = 0; i < dynamicArrayLength; i++){
        subLength[i] = 0;
    }
    for(int i = 1;i<seqSize1;i++){
        int firstSeqEl = seq1[i-1];
        for(int j = 1;j<seqSize2;j++){
            int secondSeqEl = seq2[j-1];
            if(firstSeqEl==secondSeqEl)
                subLength[translateIndex(i,j,seqSize1)] = subLength[translateIndex(i-1,j-1,seqSize1)]+1;
            else
                subLength[translateIndex(i,j,seqSize1)] = std::max(subLength[translateIndex(i-1,j,seqSize1)],
                                                                      subLength[translateIndex(i,j-1,seqSize1)]);
        }
    }
    bool flag = (seq1[seqSize1-1] == seq2[seqSize2-1]);
    int maxSubLength = subLength[dynamicArrayLength-1]+(int)flag+1;
    int* subSeq = new int[maxSubLength];
    int indexCounter = (int)flag+1;
    subSeq[0] = maxSubLength;
    if(flag)
        subSeq[1] = seq1[seqSize1-1];
    int i = seqSize1;
    int j = seqSize2;
    while(i && j){
        int firstSeqEl = seq1[i-1];
        int secondSeqEl = seq2[j-1];
        if(firstSeqEl == secondSeqEl){
            subSeq[indexCounter] = firstSeqEl;
            indexCounter++;
            i--;
            j--;
        }
        else
            i-=(int)(subLength[translateIndex(i-1,j,seqSize1)]>=subLength[translateIndex(i,j-1,seqSize1)]);
            j-=(int)(subLength[translateIndex(i-1,j,seqSize1)]<subLength[translateIndex(i,j-1,seqSize1)]);
        
    }
    delete[] subLength;
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
    std::cout<<std::endl<<maxSubSeq[0];
    std::cout<<std::endl<<"Greatest sub sequence is: ";
    for(int i = maxSubSeq[0]-1;i>0;i--){
        std::cout<<maxSubSeq[i]<<" ";
    }
    delete[] seq1;
    delete[] seq2;
    delete[] maxSubSeq;
    return 0;
}