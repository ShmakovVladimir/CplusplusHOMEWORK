#include <iostream>
void swap(int* arr,int ind1,int ind2){
    int alpha = arr[ind1];
    arr[ind1] = arr[ind2];
    arr[ind2] = alpha;
}
void intersectionSort(int* arr,int length){
    for(int i = 1; i<length; i++){
        for(int k = i; k>0; k--){
            if(arr[k]<arr[k-1]){
                swap(arr,k,k-1);
            }
        }
    }
}
void arrayOut(int* arr,int size){
    for(int i = 0;i<size;i++){
        std::cout<<arr[i]<<" ";
    }
}
//Если находим элемент в массиве - возвращаем его индекс
//В противном случае возвращаем минус еденицу
int binarySearch(int* arr,int size,int element){
    int left = 0;
    int right = size-1;
    while(left<=right){
        int midIndex = (left+right)/2;
        if(arr[midIndex] == element)
            return midIndex;
        else if(arr[midIndex] < element)
            left = midIndex+1;
        else
            right = midIndex-1;
    }
    return -1;
}

int main(){
    int size;
    int* array;

    std::cout<<"Enter the array size: ";
    std::cin>>size;
    array = new int[size];
    std::cout<<"Enter the array's elements:"<<std::endl;
    for(int i = 0; i<size; i++){
        std::cout<<std::endl<<"Element "<<i<<": ";
        std::cin>>array[i];
    }
    intersectionSort(array,size);
    std::cout<<"sorted version: ";
    arrayOut(array,size);
    int elementToFind;
    std::cout<<std::endl<<"What element should I find?: ";
    std::cin>>elementToFind;
    int elementArrIndex = binarySearch(array,size,elementToFind);
    if(elementArrIndex+1)
        std::cout<<std::endl<<"Element found by index "<<elementArrIndex;
    else
        std::cout<<std::endl<<"There is no such element";
    
    delete[] array;
    return 0;
}