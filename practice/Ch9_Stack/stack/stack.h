#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include <iostream>
#include <stdlib.h>
using namespace std;

template <typename T>
class Stack_Array{
    private:
        int Capacity; //總共的容量
        int Top_Index; //頂端資料的index
        T* Pointer; //指向資料的指標
        void Double_Capacity(); //將Capacity設為兩倍

    public:
        Stack_Array(int=0); //建構式
        bool Empty(); //回傳是否為空
        int Size(); //回傳stack大小
        T Top(); //回傳頂端元素
        void Push(T); //將元素存進stack
        void Pop(); //將元素從top刪除
        void Print_Stack(); //印出stack的內容
};

//建構式
template <typename T>
Stack_Array<T>::Stack_Array(int len){
    Capacity = len;
    //代表有空間
    if(len > 0){
        Pointer = (T*)malloc(sizeof(T) * len);
    }
    else{
        Pointer = nullptr;
    }
    Top_Index = -1;
}

//將Capacity設為兩倍
template <typename T>
void Stack_Array<T>::Double_Capacity(){
    if(Capacity == 0){
        Capacity = 1;
        Pointer = (T*)malloc(sizeof(T));
    }
    else{
        Capacity *= 2;
        T* temp = Pointer; //指向舊的空間
        Pointer = (T*)malloc(sizeof(T) * Capacity);
        //搬移舊資料
        for(int i=0; i<=Top_Index; i++){
            Pointer[i] = temp[i];
        }
        free(temp);
    }
}

//回傳是否為空
template <typename T>
bool Stack_Array<T>::Empty(){
    return (Top_Index == -1); //如果是初始化的值則代表是空的
}

//回傳stack大小
template <typename T>
int Stack_Array<T>::Size(){
    return Top_Index + 1;
}

//回傳頂端元素
template <typename T>
T Stack_Array<T>::Top(){
    if(Empty()){
        cout << "This stack is empty!" << endl;
        return -1;
    }
    return Pointer[Top_Index];
}

//將元素存進stack
template <typename T>
void Stack_Array<T>::Push(T value){
    //滿了的情況
    if(Top_Index == Capacity-1){
        Double_Capacity();
    }
    // Top_Index++;
    // Pointer[Top_Index] = value;
    Pointer[++Top_Index] = value;
}

//將元素從top刪除
template <typename T>
void Stack_Array<T>::Pop(){
    if(Empty()){
        return;
    }
    Top_Index--;
}

//印出stack的內容
template <typename T>
void Stack_Array<T>::Print_Stack(){
    cout << "Data: ";
    for(int i=0; i<=Top_Index; i++){
        cout << *(Pointer + i) << " ";
    }
    cout << endl;
}

#endif
