#include <iostream>
using namespace std;

template <typename T>
struct Node{
    T Data;
    Node* Next;
};

template <typename T>
class Queue{
    private:
        Node<T>* First;
        Node<T>* Rear;

    public:
        Queue(); //建構式
        T Front(); //回傳刪除端的資料
        T Back(); //回傳新增端的資料
        bool Empty(); //檢查是否為空
        int Size(); //回傳queue長度
        void Push(T); //將資料從queue尾端新增
        void Pop(); //將資料從queue前端刪除
        void Print_Queue(); //印出queue中的所有資料
};

//建構式
template <typename T>
Queue<T>::Queue(){
    First = Rear = nullptr;
}

//回傳刪除端的資料
template <typename T>
T Queue<T>::Front(){
    if(Empty()){
        cout << "This queue is empty" << endl;
        return 0;
    }
    return First->Data;
}

//回傳新增端的資料
template <typename T>
T Queue<T>::Back(){
    if(Empty()){
        cout << "This queue is empty" << endl;
        return 0;
    }
    return Rear->Data;
}

//檢查是否為空
template <typename T>
bool Queue<T>::Empty(){
    return (First == nullptr);
}

//回傳queue長度
template <typename T>
int Queue<T>::Size(){
    if(Empty()){
        cout << "This queue is empty" << endl;
        return 0;
    }
    int len = 1;
    Node<T>* current = First;
    while(current != Rear){
        len++;
        current = current->Next;
    }
    return len;
}

//將資料從queue尾端新增
template <typename T>
void Queue<T>::Push(T value){
    if(Empty()){
        First = Rear = new Node<T>;
        First->Data = value;
        Rear->Data = value;
        First->Next = nullptr;
        Rear->Next = nullptr;
        return;
    }

    Node<T>* new_node = new Node<T>;
    new_node->Data = value;
    new_node->Next = nullptr;
    Rear->Next = new_node;
    Rear = new_node;
}

//將資料從queue前端刪除
template <typename T>
void Queue<T>::Pop(){
    if(Empty()) return;

    Node<T>* temp = First;
    First = First->Next;
    delete temp;
    if(First == nullptr){
        Rear = nullptr;
    }
}

//印出queue中的所有資料
template <typename T>
void Queue<T>::Print_Queue(){
    if(Empty()){
        cout << "This queue is empty" << endl;
    }
    else{
        Node<T>* current = First;
        cout << "Queue: ";
        while(current != Rear){
            cout << current->Data << " ";
            current = current->Next;
        }
        cout << current->Data << endl; //印出rear
    }
}

int main(void){
    int N;
    cout << "Please enter a number: ";
    cin >> N;

    Queue<int> data;

    for(int i=1; i<=5; i++){
        data.Push(i);
    }

    while(data.Size() > 1){
        cout << endl;
        data.Print_Queue();
        int delete_number = data.Front();
        cout << "Delete card number: " << delete_number << endl;
        data.Pop();

        int move_number = data.Front();
        cout << "Move number " << move_number << " from top to the bottom" << endl;
        data.Pop();

        data.Push(move_number);
    }

    cout << endl << "Last card: " << data.Front();

    return 0;
}