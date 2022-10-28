#include "task.h"


Task::Task(): length {0}, arr{nullptr}
{

}
Task::Task(int* array,std::size_t len): length{len},numbers{std::vector<int>(len)}
{
    arr = new int[length];
    std::copy_n(array,length,arr);
    for(int i = 0;i<length;i++)
        numbers[i] = array[i];
}

Task::~Task()
{
    delete[] arr;
}

std::ostream& operator<<(std::ostream& outObj,const Task& objToPrint)
{
    outObj<<"length is: "<<objToPrint.length<<std::endl;
    outObj<<"numbers in vector are: ";
    for(int number: objToPrint.numbers)
        outObj<<number<<"  ";
    outObj<<std::endl<<"numbers in array are: ";
    for(int i = 0;i<objToPrint.length;i++)
        outObj<<objToPrint.arr[i]<<" ";
    return outObj;
}

Task::Task(const Task& objRight): length{objRight.length},numbers{objRight.numbers}
{
    std::cout<<std::endl<<"copy"<<std::endl;
    arr = new int[length];
    std::copy_n(objRight.arr,length,arr);
}

Task::Task(Task&& objRight): length{objRight.length},numbers{std::move(objRight.numbers)}
{
    std::cout<<std::endl<<"move"<<std::endl;
    objRight.length = 0;
    arr = objRight.arr;
    objRight.arr = nullptr;
}

Task& Task::operator=(const Task& objToCopy)
{
    if(this == &objToCopy)
        return (*this);
    std::cout<<std::endl<<"copy operator = "<<std::endl;
    length = objToCopy.length;
    numbers = objToCopy.numbers;
    delete[] arr;
    arr = new int[length];
    std::copy_n(objToCopy.arr,length,arr);
    return (*this);
}

Task& Task::operator=(Task&& objToBeMoved)
{
    if(this == &objToBeMoved)
        return (*this);
    std::cout<<std::endl<<"move operator = "<<std::endl;
    length = objToBeMoved.length;
    delete[] arr;
    arr = objToBeMoved.arr;
    objToBeMoved.length = 0;
    objToBeMoved.arr = nullptr;
    numbers = std::move(objToBeMoved.numbers);
    return (*this);
}