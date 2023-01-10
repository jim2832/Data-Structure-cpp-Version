#ifndef VECTOR_H_INCLUDED
#define VECTOR_H_INCLUDED

#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

template <typename T>
class Vector{
    private:
        T* Pointer; //指到動態陣列的指標
        int Len;

    public:
        Vector(int = 0); //建構式
        ~Vector(); //解構式
        T Front(); //回傳第一個元素
        T Back(); //回傳最後一個元素
};

//建構式
template <typename T>
Vector<T>::Vector(int length){
    if(length == 0){
        Pointer = nullptr; //空指標 (也可以寫Pointer = 0)
        Len = 0;
    }
    else{
        Len = length;
        Pointer = (T*) calloc(length, sizeof(T));
    }
}

//解構式
template <typename T>
Vector<T>::~Vector(){
    free(Pointer);
}

template <typename T>
T Vector<T>::Front(){
    return *Pointer; //取Pointer的位址也代表是第一筆資料
}

template <typename T>
T Vector<T>::Back(){
    return *(Pointer + Len - 1);
}

#endif