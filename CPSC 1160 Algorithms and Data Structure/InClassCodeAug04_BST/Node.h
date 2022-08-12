#include <math.h>
#ifndef NODE_H
#define NODE_H

class Node{
public:
    int element;
    Node* left;
    Node* right;
    int height;
    int balance;

    Node(){
        element = 0;
        left = right  = nullptr;
        height = 0;
        balance = 0;
    }

    Node(int i){
        element = i;
        left = right = nullptr;
        height = 0;
        balance = 0;
    }

    // add a method named ComputerHeight() to compute the height of a node
    int ComputeHeight(Node* node){
        if(node == nullptr){
            return 0;
        }
        else if(node->left == nullptr && node->right == nullptr){
            return 0;
        }
        else if(node->left != nullptr && node->right == nullptr){
            return 1 + ComputeHeight(node->left);
        }
        else if(node->right != nullptr && node->left == nullptr){
            return 1 + ComputeHeight(node->right);
        }
        else{
            int leftHeight = ComputeHeight(node->left);
            int rightHeight = ComputeHeight(node->right);
            node->height = fmax(node->left->height, node->right->height) + 1;
        }
        return node->height;
    }
    // add a method named ComputerBalance() to compute the balance of a node
    int ComputeBalanceFactor(Node* node){
        if(node == nullptr){
            return 0;
        }
        else{
            ComputeBalanceFactor(node->left);
            ComputeBalanceFactor(node->right);
            node->balance = node->right->height - node->left->height;
        }
        return node->balance;
    }




};

#endif