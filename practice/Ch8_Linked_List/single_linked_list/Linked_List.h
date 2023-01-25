#ifndef LINKED_LIST_H_INCLUDED
#define LINKED_LIST_H_INCLUDED

#include <iostream>
using namespace std;

//節點結構
template <typename T>
struct Node{
    T Data;
    Node* Next; //指向下一個資料的指標
};

//鏈結串列類別
template <typename T>
class Linked_List{
    private:
        Node<T>* First; //指向第一個節點

    public:
        Linked_List(); //建構式
        void Print_List(); //印出所有資料
        int Search_List(T); //在linked list內找尋特定資料
        void Push_Front(T); //新增第一個節點
        void Pop_Front(); //刪除第一個節點
        void Push_Back(T); //在尾端新增節點
        void Pop_Back(); //刪除最尾端的節點
        void Clear(); //刪除所有資料
        void Reverse(); //反轉鏈結串列
};

template <typename T>
Linked_List<T>::Linked_List(){
    First = nullptr; //初始化為空指標
}

//印出所有資料
template <typename T>
void Linked_List<T>::Print_List(){
    //空鏈結
    if(First == nullptr){
        cout << "This is an empty linked list." << endl;
        return;
    }

    Node<T>* current = First;
    cout << "List: ";
    while(current->Next != nullptr){
        cout << current->Data << "->";
        current = current->Next; //往下一個走訪
    }
    cout << current->Data << endl; //印出最後一筆資料
}

//在linked list內找尋特定資料
template <typename T>
int Linked_List<T>::Search_List(T target){
    //空鏈結
    if(First == nullptr){
        return -1;
    }

    int index = 0;
    Node<T>* current = First;
    while(current->Next != nullptr){
        if(current->Data == target){ //找到
            return index;
        }
        current = current->Next; //往下一個走訪
        index++;
    }
    //檢查最後一個節點
    if(current->Data == target){ //找到
        return index;
    }
    else{
        return -1; //表示沒找到
    }
}

//新增第一個節點
template <typename T>
void Linked_List<T>::Push_Front(T value){
    Node<T>* new_node = new Node<T>(); //生成一個新節點(要新增的)
    new_node->Data = value;
    new_node->Next = First;
    First = new_node;

    //另一種寫法
    /*
    Node<T>* new_node = new Node<T>{value, First};
    First = new_node;
    */
}

//刪除第一個節點
template <typename T>
void Linked_List<T>::Pop_Front(){
    //檢查是否為空鏈結
    if(First == nullptr){
        return;
    }
    Node<T>* temp = First;
    First = First->Next;
    delete temp;
}

//在尾端新增節點
template <typename T>
void Linked_List<T>::Push_Back(T value){
    //若是空的，則直接用Push_Front()新增一個新節點
    if(First == nullptr){
        Node<T>* new_node = new Node<T>;
        new_node->Data = value;
        new_node->Next = First;
        First = new_node;
        //Push_Front(value);
    }
    else{
        Node<T>* current = First;
        while(current->Next != nullptr){
            current = current->Next;
        }
        current->Next = new Node<T>; //讓current指向一個新節點
        current->Next->Data = value;
        current->Next->Next = nullptr;
    }
}

//刪除最尾端的節點
template <typename T>
void Linked_List<T>::Pop_Back(){
    //空鏈結
    if(First == nullptr){
        return;
    }
    Node<T>* current = First;
    //代表整個鏈結串列只有一筆資料，則和Pop_Front()的操作是一樣的
    if(current->Next == nullptr){
        delete First;
        First = nullptr;
        //Pop_Front();
    }
    //因為要找到最後一個節點的前一個，因此要用current->Next->Next來檢查
    while(current->Next->Next != nullptr){
        current = current->Next;
    }
    delete current->Next;
    current->Next = nullptr;
}

//刪除所有資料
template <typename T>
void Linked_List<T>::Clear(){
    Node<T>* current;
    while(First != nullptr){
        current = First;
        First = First->Next;
        delete current;
    }
}

//反轉鏈結串列
template <typename T>
void Linked_List<T>::Reverse(){
    //若此是空的鏈結串列 or 此鏈結串列只有一筆資料
    if(First == nullptr || First->Next == nullptr){
        return;
    }
    //宣告三個需要用的指標來記錄節點
    Node<T>* previous = nullptr;
    Node<T>* current = First;
    Node<T>* preceding = First->Next;
    while(preceding != nullptr){
        current->Next = previous; //反轉指標
        //全部的指標都往右移
        previous = current;
        current = preceding;
        preceding = preceding->Next;
    }
    current->Next = previous;
    First = current;
}

#endif