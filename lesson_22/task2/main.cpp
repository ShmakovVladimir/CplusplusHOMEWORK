#include <iostream>
#include <memory>
#include "Tree.hpp"






int main()
{
    Tree<int> tree(20);
    // добавление в левую часть
    tree.append(18);
    // добавление в правую часть
    tree.append(21);
    // правое справа
    tree.append(22);
    // слева от правой части
    tree.append(21);
    tree.append(22);
    tree.append(100);
    tree.append(11);
    tree.append(12);
    tree.append(134);

    std::cout<<std::endl<<std::endl;
    tree.print();
    std::cout<<std::endl<<std::endl;
    return 0;
}