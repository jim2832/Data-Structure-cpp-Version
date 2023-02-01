#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include <iostream>
#include <stdlib.h>
using namespace std;

template <typename T>
class Stack_Array{
    private:
        int Capacity;
        int Top_Index;
        T* Pointer;

    public:
        Stack_Array(int=0); //建構式
        bool Empty(); //回傳是否為空
        int Size(); //回傳stack大小
        T top(); //回傳頂端元素
        void Push(T); //將元素存進stack
        void Pop(); //將元素從top刪除
        void Print_Stack(); //印出stack的內容
};

#endif