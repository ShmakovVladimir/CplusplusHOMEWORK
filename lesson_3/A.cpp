#include <iostream>

void copyFromLeftToRight(int* arrayToBeCopied,int* arrayToCopyIn,int startIndex,int endIndex){
    for(int i = startIndex;i<=endIndex;i++){
        arrayToCopyIn[i] = arrayToBeCopied[i-startIndex];
    }
}

void mergeSortedArrays(int* arr,int left,int right){
    int middle = left+(right-left)/2;
    int* mergedArray = new int[right-left+1];
    int counter = 0;
    int leftArrayIndex = left;
    int rightArrayIndex = middle+1;
    while(leftArrayIndex<=middle&&rightArrayIndex<=right){
        if(arr[leftArrayIndex] < arr[rightArrayIndex]){
            mergedArray[counter] = arr[leftArrayIndex];
            leftArrayIndex++;
        }
        else{
            mergedArray[counter] = arr[rightArrayIndex];
            rightArrayIndex++;
        }
        counter++;
    }
    while(leftArrayIndex<=middle){
        mergedArray[counter] = arr[leftArrayIndex];
        counter++;
        leftArrayIndex++;
    }
    while(rightArrayIndex<=right){
        mergedArray[counter] = arr[rightArrayIndex];
        counter++;
        rightArrayIndex++;
    }
    copyFromLeftToRight(mergedArray,arr,left,right);
    delete[] mergedArray;
}

void mergeSort(int* arr,int left,int right){
    if(right-left){
        int middle = left+(right-left)/2;
        mergeSort(arr,left,middle);
        mergeSort(arr,middle+1,right);
        mergeSortedArrays(arr,left,right);
    }
}



void printArray(int* arr,int length){
    for(int i = 0;i<length;i++){
        std::cout<<arr[i]<<"  ";
    }
}

int* enterArray(int length){
    int* arr = new int[length];
    std::cout<<std::endl;
    for(int i = 0;i<length;i++){
        std::cout<<"Enter the array's "<<i+1<<" element: ";
        std::cin>>arr[i];
    }
    return arr;
}

int* randomArray(int length,int maxValue = 100){
    int* arr = new int[length];
    for(int i = 0;i<length;i++){
        arr[i] = rand()%maxValue;
    }
    return arr;
}

void keyboardInputMode(){
    int arrayLength;
    std::cout<<"enter your array length: ";
    std::cin>>arrayLength;
    int* array = enterArray(arrayLength);
    std::cout<<"Your array is: ";
    printArray(array,arrayLength);
    mergeSort(array,0,arrayLength-1);
    std::cout<<std::endl<<"sorted version is: ";
    printArray(array,arrayLength);
    delete[] array;
}

void randomInputMode(){
    int arrayLength = rand()%30;
    int* array = randomArray(arrayLength);
    std::cout<<"Your array is: ";
    printArray(array,arrayLength);
    mergeSort(array,0,arrayLength-1);
    std::cout<<std::endl<<"sorted version is: ";
    printArray(array,arrayLength);
    delete[] array;
}

int main(int argc,char* argv[]){
    int randomInputModeCodeSeries = atoi("-random");
    if(argc<=1)
        keyboardInputMode();
    else if(atoi(argv[1]) == randomInputModeCodeSeries)
        randomInputMode();
    else{
        std::cout<<"Error, this program has no such mode";
    }
    return 0;
}