#include <iostream>
#include <memory>
#include "Tree.hpp"






int main()
{
    Tree<int> tree(20);
    // добавление в левую часть
    tree.AppendRight(18);
    // добавление в правую часть
    tree.AppendLeft(21);
    // правое справа
    tree.AppendRight(22);
    // слева от правой части
    tree.AppendLeft(21);

    return 0;
}