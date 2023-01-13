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
        int Capacity; //向量總共宣告的大小
        int Len; //向量真正使用的大小

    public:
        Vector(int = 0); //建構式
        ~Vector(); //解構式
        T Front(); //回傳第一個元素
        T Back(); //回傳最後一個元素
        T& At(int); //取出特定index的資料
        T& operator[](int); //用overload取出特定index的資料
        int Size(); //回傳目前向量大小
        bool Empty(); //判斷是否為空
        void Push_Back(T); //在尾端新增資料
        void Pop_Back(); //從尾端刪除資料
        void Insert(int, T); //在特定index插入資料
        void Erase(int); //在特定index刪除資料
        void Erase(int, int); //在一段範圍內刪除資料
        void Clear(); //清除所有資料
        void Reserve(int); //更改Capacity
        void Resize(int); //更改Len
};

//建構式
template <typename T>
Vector<T>::Vector(int length){
    if(length == 0){
        Pointer = nullptr; //空指標 (也可以寫Pointer = 0)
        Len = 0;
        Capacity = 0;
    }
    else{
        Len = length;
        Capacity = length;
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

template <typename T>
T& Vector<T>::At(int index){
    return *(Pointer + index);
}

template <typename T>
T& Vector<T>::operator[](int index){
    return *(Pointer + index);
}

template <typename T>
int Vector<T>::Size(){
    return Len;
}

template <typename T>
bool Vector<T>::Empty(){
    return Len == 0; //若len == 0 則 return true
}

template <typename T>
void Vector<T>::Push_Back(T data){
    Len++; //先將長度+1
    T* temp = (T*) malloc(sizeof(T) * Len); //配置一塊新的記憶體空間
    for(int i=0; i<Len-1; i++){ //把舊資料搬移過去
        *(temp + i) = *(Pointer + i);
    }
    *(temp + Len - 1) = data; //新增的資料
    free(Pointer); //釋放舊的空間
    Pointer = temp;
}

template <typename T>
void Vector<T>::Pop_Back(){
    //例外處理
    if(Empty()) return;
    
    Len--; //先將長度-1
    T* temp = (T*) malloc(sizeof(T) * Len); //配置一塊新的記憶體空間
    for(int i=0; i<Len; i++){ //把舊資料搬移過去
        *(temp + i) = *(Pointer + i);
    }
    free(Pointer); //釋放舊的空間
    Pointer = temp;
}

template <typename T>
void Vector<T>::Insert(int index, T data){
    //例外處理
    if(index > Size()) return;
    if(index < 0) return;

    Len++; //先將長度+1
    T* temp = (T*) malloc(sizeof(T) * Len); //配置一塊新的記憶體空間
    for(int i=0; i<Len; i++){ //把舊資料搬移過去
        if(i <index){
            *(temp + i) = *(Pointer + i);
        }
        else if(i == index){
            *(temp + i) = data;
        }
        else{
            *(temp + i) = *(Pointer + i - 1);
        }
    }
    free(Pointer); //釋放舊的空間
    Pointer = temp;
}

template <typename T>
void Vector<T>::Erase(int index){
    //例外處理
    if(Empty()) return;
    if(index >= Size()) return;
    if(index < 0) return;

    Len--; //先將長度-1
    T* temp = (T*) malloc(sizeof(T) * Len); //配置一塊新的記憶體空間
    for(int i=0; i<Len; i++){ //把舊資料搬移過去
        if(i < index){
            *(temp + i) = *(Pointer + i);
        }
        // else if(i == index){
        //     continue;
        // }
        else{
            *(temp + i) = *(Pointer + i + 1);
        }
    }
    free(Pointer); //釋放舊的空間
    Pointer = temp;
}

template <typename T>
void Vector<T>::Erase(int start, int end){
    //簡易的做法
    /*
    for(int i=start; i<end; i++){
        Erase(start);
    }
    */

    //進階的做法
    if(Empty()) return;
    if(end >= Size()) return;
    if(end <= start) return;
    if(start < 0) return;

    Len -= end - start; //要刪除end-start筆資料
    T* temp = (T*) malloc(sizeof(T) * Len); //配置一塊新的記憶體空間
    for(int i=0; i<Len; i++){ //把舊資料搬移過去
        if(i < start){
            *(temp + i) = *(Pointer + i);
        }
        else{
            *(temp + i) = *(Pointer + i + (end - start));
        }
    }
    free(Pointer); //釋放舊的空間
    Pointer = temp;
}

template <typename T>
void Vector<T>::Clear(){
    free(Pointer);
    Len = 0;
}

template <typename T>
void Vector<T>::Reserve(int N){
    //例外處理
    if(N < Len) return;

    Capacity = N;
    T* temp = (T*) malloc(sizeof(T) * Len);
    for(int i=0; i<Len; i++){
        *(temp + i) = *(Pointer + i);
    }
    free(Pointer);
    Pointer = temp;
}

template <typename T>
void Vector<T>::Resize(int N){
    //例外處理
    if(N < 0) return;

    //如果要擴展的大小小於Capacity
    if(N <= Capacity){
        Len = N;
    }
}

#endif