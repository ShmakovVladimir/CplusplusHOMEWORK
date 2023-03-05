#pragma once
#include <iostream>
#include <memory>
#include "Node.hpp"





class Tree()
{
    public:
        Tree(key_t rootElement): root(rootElement, nullptr);
        
    private:
        TreeNode<key_t> root;
};