#include <iostream>
#include "Figure.hpp"
#include "Rect.hpp"
#include "Square.hpp"
#include "Circle.hpp"
#include "Ellipse.hpp"
#include "Point.hpp"

int main()
{
    auto square1 = new Square(10,M_PI/2,{40,50});
    std::cout<<"Square1 area: "<<square1->getArea();
    std::cout<<std::endl<<"Square1 perimetr: "<<square1->getPerimetr()<<std::endl;
    auto ellipse = new Ellipse({20,20},M_PI/3,10,40);
    ellipse->print();
    std::cout<<std::endl<<"ellipse area: "<<ellipse->getArea();
    std::cout<<std::endl<<"ellipse perimetr: "<<ellipse->getPerimetr();

    delete square1;
    delete ellipse;
    return 0;
}