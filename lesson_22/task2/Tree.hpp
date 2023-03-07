#pragma once
#include <memory>
#include <iostream>

template <typename T>
class Tree {
    class Node {
        public:
            std::weak_ptr<Node> parent;
            std::shared_ptr<Node> child_left;
            std::shared_ptr<Node> child_right;
            T value;

            Node(const T& val) : value(val), child_left(nullptr), child_right(nullptr) {}

            ~Node() {
            std::cout << "Node with value " << value << " is deleted" << std::endl;
            value.~T();
            }
    };

    std::shared_ptr<Node> head;
    std::shared_ptr<Node> active;
public:
    void AppendLeft(const T& val) {
        active->child_left = std::make_shared<Node>(val); 
        active->child_left->parent = std::weak_ptr<Node>(active);
    }

    void AppendRight(const T& val) {
        active->child_right = std::make_shared<Node>(val);
        active->child_right->parent = std::weak_ptr<Node>(active);
    }
    Tree(const T& val) {
        head = std::make_shared<Node>(val);
        active = head;
    }
    void append(const T& val)
    {
        if(val <= (active->value) && !active->child_left)
            AppendLeft(val);
        else if(val <= active->value)
        {
            active = active->child_left;
            append(val);
        }
         if(val > active->value && !active->child_left)
            AppendRight(val);
        else if(val > active->value)
        {
            active = active->child_right;
            append(val);
        }
    }

};