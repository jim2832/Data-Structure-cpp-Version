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
        //迭代器類別
        class Iterator{
            private:
                T* iter; //迭代器指標

            public:
                Iterator(T* = nullptr); //建構式
                void operator++(); //++Iterator
                void operator--(); //--Iterator
                void operator++(int); // Iterator++
                void operator--(int); // Iterator--
                void operator=(Iterator); //Iterator=
                bool operator==(Iterator); //Iterator==
                bool operator!=(Iterator); //Iterator!=
                bool operator>(Iterator); //Iterator>
                bool operator<(Iterator); //Iterator<
                bool operator>=(Iterator); //Iterator>=
                bool operator<=(Iterator); //Iterator<=
                T& operator*(); //取值運算子
                int operator-(Iterator); //回傳兩個迭代器的差
                Iterator operator+(int); //迭代器的指標(iter)直接 + 一個數字
                Iterator operator-(int); //迭代器的指標(iter)直接 - 一個數字
        };

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
        void Insert(Iterator, T); //在特定index插入資料
        void Erase(Iterator); //在特定index刪除資料
        void Erase(Iterator, Iterator); //在一段範圍內刪除資料
        void Clear(); //清除所有資料
        void Reserve(int); //更改Capacity
        void Resize(int); //更改Len
        Iterator Begin(); //回傳迭代的第一個結果
        Iterator End(); //回傳迭代最後一個結果的下一個
};

/*外部函式*/
template <typename T>
typename Vector<T>::Iterator Find(Vector<T> v, T data){
    for(auto iter=v.Begin(); iter!=v.End(); iter++){
        if(*iter == data){
            return iter;
        }
    }
    return v.End();
}

template <typename T>
typename Vector<T>::Iterator Remove(Vector<T> v, T target){
    int count = 0;
    for(auto iter=v.Begin(); iter!=v.End(); iter++){
        if(*iter == target){
            continue;
        }
        *(v.Begin() + count) = *iter;
        count++;
    }

    for(auto iter=v.Begin()+count; iter!=v.End(); iter++){
        *iter = target;
    }

    return v.Begin() + count;
}

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
    //如果容量還夠
    if(Len == Capacity){
        if(Capacity == 0){
            Reserve(1);
        }
        else{
            Reserve(Capacity * 2);
        }
    }
    *(Pointer + Len) = data;
    Len++;
}

template <typename T>
void Vector<T>::Pop_Back(){
    //例外處理
    if(Empty()) return;
    
    Len--; //長度-1
}

template <typename T>
void Vector<T>::Insert(Iterator iter2, T data){
    //例外處理
    if(iter2 >= End()) return;
    if(iter2 < Begin()) return;

    //如果已經滿了
    if(Len == Capacity){
        if(Capacity == 0){
            Capacity = 1;
        }
        else{
            Reserve(Capacity * 2);
        }
    }

    //把舊資料搬移過去
    // 1 2 3 4 5
    // insert 100 to index 0
    // 100 1 2 3 4 5
    auto temp = iter2;
    for(iter2=End(); iter2>=temp; iter2--){
        *(iter2 + 1) = *(iter2); //temp之後的都要往後移
    }
    *(temp) = data;
    Len++;
}

template <typename T>
void Vector<T>::Erase(Iterator iter2){
    //例外處理
    if(Empty()) return;
    if(iter2 >= End()) return;
    if(iter2 < Begin()) return;

    // 1 2 3 4 5
    // delete index 1
    // 1 3 4 5 5
    for(iter2++; iter2<End(); iter2++){
        *(iter2 - 1) = *(iter2);
    }
    Len--; //先將長度-1
}

template <typename T>
void Vector<T>::Erase(Iterator start, Iterator end){
    //簡易的做法
    /*
    for(int i=start; i<end; i++){
        Erase(start);
    }
    */

    //進階的做法
    if(Empty()) return;
    if(end >= End()) return;
    if(end <= start) return;
    if(start < Begin()) return;
    
    // 1 2 3 4 5
    // delete index 1, 2
    // 1 4 5 4 5
    auto temp = end;
    for(; temp<End(); temp++){
        *(temp - (end-start)) = *temp;
    }
    Len -= end - start; //要刪除end-start筆資料
}

template <typename T>
void Vector<T>::Clear(){
    free(Pointer);
    Len = 0;
    Capacity = 0;
    Pointer = nullptr;
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

template <typename T>
typename Vector<T>::Iterator Vector<T>::Begin(){
    Iterator result(Pointer);
    return result;
}

template <typename T>
typename Vector<T>::Iterator Vector<T>::End(){
    Iterator result(Pointer + Len);
    return result;
}

/*迭代器的函式*/
template <typename T>
Vector<T>::Iterator::Iterator(T* pointer){
    iter = pointer;
}

template <typename T>
void Vector<T>::Iterator::operator++(){
    iter++;
}

template <typename T>
void Vector<T>::Iterator::operator--(){
    iter--;
}

template <typename T>
void Vector<T>::Iterator::operator++(int){
    iter++;
}

template <typename T>
void Vector<T>::Iterator::operator--(int){
    iter--;
}

template <typename T>
void Vector<T>::Iterator::operator=(Iterator iter2){
    iter = iter2.iter;
}

template <typename T>
bool Vector<T>::Iterator::operator==(Iterator iter2){
    return iter == iter2.iter;
}

template <typename T>
bool Vector<T>::Iterator::operator!=(Iterator iter2){
    return iter != iter2.iter;
}

template <typename T>
bool Vector<T>::Iterator::operator>(Iterator iter2){
    return iter > iter2.iter;
}

template <typename T>
bool Vector<T>::Iterator::operator<(Iterator iter2){
    return iter < iter2.iter;
}

template <typename T>
bool Vector<T>::Iterator::operator>=(Iterator iter2){
    return iter >= iter2.iter;
}

template <typename T>
bool Vector<T>::Iterator::operator<=(Iterator iter2){
    return iter <= iter2.iter;
}

template <typename T>
T& Vector<T>::Iterator::operator*(){
    return *iter;
}

template <typename T>
int Vector<T>::Iterator::operator-(Iterator iter2){
    return (iter - iter2.iter);
}

template <typename T>
typename Vector<T>::Iterator Vector<T>::Iterator::operator+(int offset){
    Iterator result(iter + offset);
    return result;
}

template <typename T>
typename Vector<T>::Iterator Vector<T>::Iterator::operator-(int offset){
    Iterator result(iter - offset);
    return result;
}

#endif