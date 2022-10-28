#pragma once
#include <iostream>
#include <vector>
#include <algorithm>  

class Task
{
    public:
        Task();
        Task(int* array,std::size_t len);
        ~Task();
        friend std::ostream& operator<<(std::ostream& outObj,const Task& objToPrint);
        Task(const Task& objRight); //конструктор копирования
        Task(Task&& objRigth); //конструктор перемещения
        Task& operator=(const Task& objToCopy); //копирующий оператор присваивания
        Task& operator=(Task&& objToBeMoved); //перемещающий оператор присваивания
    private:
        int* arr;
        std::size_t length;
        std::vector<int> numbers;
};