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
int main(){
    int size;
    int* array;

    std::cout<<"Enter the array size: ";
    std::cin>>size;
    array = new int[size];
    std::cout<<"Enter the array's elements:"<<std::endl;
    for(int i = 0;i<size;i++){
        std::cout<<std::endl<<"Element "<<i<<": ";
        std::cin>>array[i];
    }
    std::cout<<std::endl<<"Start array:"<<std::endl;
    arrayOut(array,size);
    std::cout<<std::endl<<"Sorted array:"<<std::endl;
    intersectionSort(array,size);
    arrayOut(array,size);
    
}
