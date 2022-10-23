#pragma once
#include <iostream>
#include <vector>
#include <algorithm>  

class Task
{
    public:
        Task();
        Task(unsigned int len,int* array);
        ~Task();
        friend std::ostream& operator<<(std::ostream& outObj,const Task& objToPrint);
        Task(Task& objRight); //конструктор копирования
        Task(Task&& objRigth); //конструктор перемещения
        Task& operator=(Task& objToCopy); //копирующий оператор присваивания
        Task& operator=(Task&& objToBeMoved); //перемещающий оператор присваивания
    private:
        int* arr;
        unsigned int length;
        std::vector<int> numbers;
};