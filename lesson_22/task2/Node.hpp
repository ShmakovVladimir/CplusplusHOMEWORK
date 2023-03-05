#pragma once
#include <memory>


template <typename dataType>
class TreeNode
{
    public:
        TreeNode(dataType data, std::shared_ptr parent): parent{parent}, d{data};
        std::shared_ptr<TreeNode> childLeft;
        std::shared_ptr<TreeNode> childRight;
        std::shared_ptr<TreeNode> parent;
        dataType d;
};