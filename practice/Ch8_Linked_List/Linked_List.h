#ifndef LINKED_LIST_H_INCLUDED
#define LINKED_LIST_H_INCLUDED

template <typename T>
struct Node{
    T Data;
    Node* Next; //指向下一個資料的指標
};

template <typename T>
class Linked_List{
    private:
        Node<T>* First; //指向第一個節點

    public:
        Linked_List(); //建構式
        Print_List(); //印出所有資料
        Search_List(T); //在linked list內找尋特定資料
};

template <typename T>
Linked_List<T>::Linked_List(){
    First = nullptr; //初始化為空指標
}

#endif