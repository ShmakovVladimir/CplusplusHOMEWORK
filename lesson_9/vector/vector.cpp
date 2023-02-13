#include "vector.hpp"



template <typename T>
Vector<T>::Vector() noexcept: length{0}, capasity{startCapasity}, elements{new T[startCapasity]}
{
	
}

template <typename T>
Vector<T>::Vector(std::size_t len): length{len},capasity{startCapasity + capasityPerLength*len}
{
    if(length <= 0)
        throw std::length_error("Array's length must be positive");
    elements = new T[capasity];
}

template <typename T> 
Vector<T>::Vector(std::size_t len, T* el): length{len},capasity{startCapasity + capasityPerLength*len}
{
    if(length <= 0)
        throw std::length_error("Array's length must be positive");
    elements = new T[capasity];
    for(int i = 0; i < length ; i++)
        elements[i] = el[i];
}

template <typename T>
void Vector<T>::push(const T elementToBePushed) noexcept
{
    
    if(length++ < capasity)
        elements[length] = elementToBePushed;
    else 
    {
        capasity*=capasityPerLength;
        T* newElements = new T[capasity];
        for(int i = 0; i < length-1; i++)
            newElements[i] = elements[i];
        delete[] elements;
        elements = newElements;
    }
}


std::ostream& operator<<(std::ostream& outObj,const Vector<int>& vectorToPrint) noexcept
{
    for(int i = 0; i < vectorToPrint.length; i++)
        outObj<<vectorToPrint.elements[i]<<"\t";
    return outObj;
}





template <typename T>
Vector<T>::~Vector() noexcept
{
    delete[] elements;
}

