#include<iostream>

using namespace std;

#ifndef NODE_H
#define NODE_H
template<typename T>
class Node{
public:
    T element;
    Node* next;
    Node* prev;

    Node(){
      element = 0;
      next = nullptr;
      prev = nullptr;
    }

    Node(T e){
      element = e;
      next = nullptr;
      prev = nullptr;
    }
};

#endif

