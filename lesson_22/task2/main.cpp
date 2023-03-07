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

    return 0;
}