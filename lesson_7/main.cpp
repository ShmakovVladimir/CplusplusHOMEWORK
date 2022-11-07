#include <iostream>
#include "Figure.h"
#include "Rect.h"
#include "Square.h"
#include "Circle.h"
#include "Ellipse.h"
#include "Point.h"

int main()
{
    Figure* square1 = new Square(10,PI/2,{40,50});
    std::cout<<square1->getArea();
    std::cout<<std::endl<<square1->getPerimetr();
    Figure* ellipse = new Ellipse({20,20},PI/3,10,40);
    ellipse->print();
    std::cout<<std::endl<<"ellipse area: "<<ellipse->getArea();
}