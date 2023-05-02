#pragma once
#include <memory>
#include <iostream>
#include <string>

template <typename T>
class Tree {
    private: 
        class Node {
            public:
                Node(const T& val) : value(val), childLeft(nullptr), childRight(nullptr) {}
                
                ~Node() {
                std::cout << "Node with data = " << value << " deleted" << std::endl;
                value.~T();
                }

                std::weak_ptr<Node> parent;
                std::shared_ptr<Node> childLeft;
                std::shared_ptr<Node> childRight;
                T value;
        };

        void AppendLeft(const T& val) {
            active->childLeft = std::make_shared<Node>(val); 
            active->childLeft->parent = std::weak_ptr<Node>(active);
        }

        void AppendRight(const T& val) {
            active->childRight = std::make_shared<Node>(val);
            active->childRight->parent = std::weak_ptr<Node>(active);
        }

        //функция print с stackoverflow
        void printBT(const std::string& prefix, std::shared_ptr<Node> node, bool isLeft)
        {
            if( node != nullptr )
            {
                if( node != root)
                    std::cout << (isLeft ? "/---" : "----" );

        // print the value of the node
            std::cout << node->value << std::endl;
            std::string newPrefix = (isLeft ? "/---" : "----" ) + prefix;
        // enter the next tree level - left and right branch
            printBT(newPrefix + (isLeft ? "/   -" : "----"), node->childLeft, true);
            printBT(newPrefix + (isLeft ? "/   -" : "----"), node->childRight, false);
            }
        }

        std::shared_ptr<Node> root;
        std::shared_ptr<Node> active;

    public:
        Tree(const T& val) {
            root = std::make_shared<Node>(val);
            active = root;
        }

        void append(const T& val)
        {
            if(val <= (active->value) && !active->childLeft)
            {
                std::cout << "Left appended" << std::endl;
                AppendLeft(val);
            }
            else if(val <= active->value)
            {
                std::cout << "New level added(from left)" << std::endl;
                active = (active->childLeft);
                append(val);
            }
            if(val > active->value && !active->childRight)
            {
                std::cout << "Right appended" << std::endl;
                AppendRight(val);
            }
            else if(val > active->value)
            {
                std::cout << "New level added(from right)" << std::endl;
                active = (active->childRight);
                append(val);
            }
        }

        void print()
        {
            printBT("+", root, false);
        }

};