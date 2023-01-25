#ifndef CIRCULAR_LINKED_LIST_H_INCLUDED
#define CIRCULAR_LINKED_LIST_H_INCLUDED

#include <iostream>
using namespace std;

//節點結構
template <typename T>
struct Node{
    T Data;
    Node* Prev; //指向上一個資料的指標
    Node* Next; //指向下一個資料的指標
};

//鏈結串列類別
template <typename T>
class Linked_List{
    private:
        Node<T>* Head; //去方向第一個節點
        int Len;

    public:
        //迭代器類別
        class Iterator{
            //friend
            friend Linked_List;

            private:
                Node<T>* iter; //迭代器指標

            public:
                Iterator(Node<T>* = nullptr); //建構式
                void operator++(); //++Iterator
                void operator--(); //--Iterator
                void operator++(int); // Iterator++
                void operator--(int); // Iterator--
                void operator=(Iterator); //Iterator=
                bool operator==(Iterator); //Iterator==
                bool operator!=(Iterator); //Iterator!=
                T& operator*(); //取值運算子
                /*
                Iterator operator+(int); //迭代器的指標(iter)直接 + 一個數字
                Iterator operator-(int); //迭代器的指標(iter)直接 - 一個數字
                */
        };

        //methods
        Linked_List(); //建構式
        /*
        void Print_List(); //印出所有資料
        int Search_List(T); //在linked list內找尋特定資料
        void Push_Front(T); //新增第一個節點
        void Pop_Front(); //刪除第一個節點
        void Pop_Back(); //刪除最尾端的節點
        void Clear(); //刪除所有資料
        void Reverse(); //反轉鏈結串列
        void Insert(Iterator, const T&); //在特定地方插入資料
        void Erase(Iterator); //刪除特別迭代器裡面的資料
        void Remove(T); //刪除特定的資料
        Iterator End(); //回傳最後一個節點的下一個迭代器，即空指標
        Iterator Head_Iter(); //回傳Head
        Iterator Tail_Iter(); //回傳Tail
        */
        void Push_Back(T); //在尾端新增節點
        Iterator Begin(); //回傳第一個節點的迭代器
        void Rotate(int); //在Circular Linked List中旋轉的節點數
    
    //function
    //template <typename T2> friend typename Linked_List<T2>::Iterator Find(Linked_List<T2> List, T2 data);
};


/*外部函式*/
// template <typename T>
// typename Linked_List<T>::Iterator Find(Linked_List<T> List, T data){
//     typename Linked_List<T>::Iterator null_iter(nullptr); //空迭代器

//     //空鏈結
//     if(List.Begin() == nullptr){
//         return null_iter;
//     }

//     auto current(List.Begin());
//     while(current != null_iter){
//         if(*current == data){
//             return current;
//         }
//         current++;
//     }
//     return current; //若都沒有找到，則回傳一個空的current
// }

/* Linked List的函式 */
template <typename T>
Linked_List<T>::Linked_List(){
    Head = nullptr; //初始化為空指標
    Len = 0;
    //Tail = nullptr; //初始化為空指標
}

//印出所有資料
// template <typename T>
// void Linked_List<T>::Print_List(){
//     //空鏈結
//     if(Head == nullptr){
//         cout << "This is an empty linked list." << endl;
//         return;
//     }

//     Node<T>* current = Head;
//     cout << "List: ";
//     while(current->Next != nullptr){
//         cout << current->Data << "->";
//         current = current->Next; //往下一個走訪
//     }
//     cout << current->Data << endl; //印出最後一筆資料
// }

/*
//在linked list內找尋特定資料
template <typename T>
int Linked_List<T>::Search_List(T target){
    //空鏈結
    if(Head == nullptr){
        return -1;
    }

    int index = 0;
    Node<T>* current = Head;
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
   //若是空的，則直接用Push_Front()新增一個新節點
    if(Head == nullptr){
        Node<T>* new_node = new Node<T>;
        new_node->Data = value;
        new_node->Prev = nullptr;
        new_node->Next = nullptr;
        Head = new_node;
        Tail = new_node;
        //Push_Front(value);
    }
    else{
        Head->Prev = new Node<T>;
        Head->Prev->Data = value;
        Head->Prev->Prev = nullptr;
        Head->Prev->Next = Head;
        Head = Head->Prev;
    }
}

//刪除第一個節點
template <typename T>
void Linked_List<T>::Pop_Front(){
    //若此是空的鏈結串列
    if(Head == nullptr){
        return;
    }
    //此鏈結串列只有一筆資料
    if(Head == Tail){
        delete Head;
        Head = Tail = nullptr;
        return;
    }

    //兩筆以上的資料
    Head = Head->Next;
    delete Head->Prev;
    Head->Prev = nullptr;
}
*/

//在尾端新增節點
template <typename T>
void Linked_List<T>::Push_Back(T value){
    if(Head == nullptr){
        // Empty;
        Head = new Node<T>{value, nullptr, nullptr};
        Head->Next = Head->Prev = Head;
    }
    else{
        // Tail: Head->Prev
        Node<T> *new_node = new Node<T>{value, Head->Prev, Head};
        Head->Prev->Next = new_node;
        Head->Prev = new_node;
    }
    Len++;
}

//旋轉
template <typename T>
void Linked_List<T>::Rotate(int offset){
    if(Head == nullptr)
        return;
    offset = offset % Len;
    for(int i=0;i<offset;i++){
        Head = Head->Next;
    }
}

/*
//刪除最尾端的節點
template <typename T>
void Linked_List<T>::Pop_Back(){
    //若此是空的鏈結串列
    if(Head == nullptr){
        return;
    }
    //此鏈結串列只有一筆資料
    if(Head == Tail){
        delete Tail;
        Head = Tail = nullptr;
        return;
    }

    //兩筆以上的資料
    Tail = Tail->Prev;
    delete Tail->Next;
    Tail->Next = nullptr;
}

//刪除所有資料
template <typename T>
void Linked_List<T>::Clear(){
    Node<T>* current;
    while(Head != nullptr){
        current = Head;
        Head = Head->Next;
        delete current;
    }
    Tail = nullptr;
}

//反轉鏈結串列
template <typename T>
void Linked_List<T>::Reverse(){
    //若此是空的鏈結串列 or 此鏈結串列只有一筆資料
    if(Head == nullptr || Head == Tail){
        return;
    }
    //宣告三個需要用的指標來記錄節點
    Node<T>* previous = nullptr;
    Node<T>* current = Head;
    Node<T>* preceding = Head->Next;

    Tail = Head;
    while(preceding != nullptr){
        current->Next = previous; //反轉指標
        current->Prev = preceding; //反轉指標
        //全部的指標都往右移
        previous = current;
        current = preceding;
        preceding = preceding->Next;
    }
    current->Next = previous;
    current->Prev = preceding;
    Head = current;
}

//在特定地方插入資料
template <typename T>
void Linked_List<T>::Insert(Iterator it, const T& value){
    //示例
    // A B, B is provided by user = it
    // A C B
    // TODO: Cannot use to push front.
    // TODO: Cannot use to push tail.
    if(it == Begin()){
        Push_Front(value);
        return;
    }
    if(it == End() || it == Iterator(Tail)){
        Push_Back(value);
        return;
    }
    Node<T> *new_node = new Node<T>(value, it.iter->Prev, it.iter);
    it.iter->Prev->Next = new_node; // A -> Next = C
    it.iter->Prev = new_node; // B -> Prev = C
}

//刪除特別迭代器裡面的資料
template <typename T>
void Linked_List<T>::Erase(Iterator it){
    // A B C, B is provided by user = it
    // A C
    // TODO: Cannot use to erase front.
    // TODO: Cannot use to erase tail.
    if(it == Begin()){
        Pop_Front(value);
        return;
    }
    if(it == End() || it == Iterator(Tail)){
        Pop_Back(value);
        return;
    }
    it.iter->Prev->Next = it.iter->Next; // A -> Next = C
    it.iter->Next->Prev = it.iter->Prev; // C -> Prev = A
    delete it.iter;
}

//刪除特定的資料
template <typename T>
void Linked_List<T>::Remove(T value){
    for(auto iter=Begin(); iter!=End(); iter++){
        // A B C, delete B
        // A C, let iterator = A
        if(*iter == value){
            if(iter == Begin()){
                Pop_Front();
            }
            else{
                auto temp = iter;
                temp--;
                Erase(iter);
                iter = temp;
            }
        }
    }
}
*/

//回傳第一個節點的迭代器
template <typename T>
typename Linked_List<T>::Iterator Linked_List<T>::Begin(){
    return Iterator(Head);
}

/*
//回傳最後一個節點的下一個迭代器，即空指標
template <typename T>
typename Linked_List<T>::Iterator Linked_List<T>::End(){
    return Iterator(nullptr);
}

//回傳Head
template<typename T>
typename Linked_List<T>::Iterator Linked_List<T>::Head_Iter(){
    return Iterator(Head);
}

//回傳Tail
template<typename T>
typename Linked_List<T>::Iterator Linked_List<T>::Tail_Iter(){
    return Iterator(Tail);
}
*/


/*迭代器的函式*/
template <typename T>
Linked_List<T>::Iterator::Iterator(Node<T>* pointer){
    iter = pointer;
}

template <typename T>
void Linked_List<T>::Iterator::operator++(){
    //不是空代表有指到東西
    if(iter != nullptr){
        iter = iter->Next;
    }
}

template <typename T>
void Linked_List<T>::Iterator::operator--(){
    if(iter != nullptr){
        iter = iter->Prev;
    }
}

template<typename T>
void Linked_List<T>::Iterator::operator++(int){
    // Iterator++
    if(iter != nullptr){
        iter = iter->Next;
    }
}


template<typename T>
void Linked_List<T>::Iterator::operator--(int){
    // Iterator--
    if(iter != nullptr){
        iter = iter->Prev;
    }
}

template <typename T>
void Linked_List<T>::Iterator::operator=(Iterator iter2){
    iter = iter2.iter;
}

template <typename T>
bool Linked_List<T>::Iterator::operator==(Iterator iter2){
    return iter == iter2.iter;
}

template <typename T>
bool Linked_List<T>::Iterator::operator!=(Iterator iter2){
    return iter != iter2.iter;
}

template <typename T>
T& Linked_List<T>::Iterator::operator*(){
    return iter->Data;
}

/*
template <typename T>
typename Linked_List<T>::Iterator Linked_List<T>::Iterator::operator+(int offset){
    Iterator result(iter);
    for(int i=0; i<offset; i++){
        //如果是空指標則直接結束
        if(result->iter == nullptr){
            return result;
        }
        result->iter = result->iter->Next;
    }
    return result;
}

template <typename T>
typename Linked_List<T>::Iterator Linked_List<T>::Iterator::operator-(int offset){
    Iterator result(iter);
    for(int i=0; i<offset; i++){
        //如果是空指標則直接結束
        if(result->iter == nullptr){
            return result;
        }
        result->iter = result->iter->Prev;
    }
    return result;
}
*/

#endif