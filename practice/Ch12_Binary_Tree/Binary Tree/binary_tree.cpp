#include <iostream>
#include <string>
using namespace std;

template <typename T>
struct Node{
    int index; //頂點的編號
    T data; //存資料
    Node<T> *left; //指向左節點的指標
    Node<T> *right; //指向右節點的指標
};

template <typename T>
class Binary_Tree{
    public:
        Node<T>* root; //樹根
        Binary_Tree(); //建構式
        void Print(Node<T>); //印出二元樹
        bool Insert(int, T); //插入節點(若有插入成功則回傳true)
        bool Delete(int); //刪除節點(若有刪除成功則回傳true)
        Node<T>* Search(int); //尋找某個節點
};

//建構式
template <typename T>
Binary_Tree<T>::Binary_Tree(){
    root = nullptr; //一棵空的樹
}

//印出二元樹
template <typename T>
void Binary_Tree<T>::Print(Node<T> node){
    cout << "Index: " << node.index << endl;
    cout << "Data: " << node.data << endl;
}

//插入節點
template <typename T>
//target:頂點的編號(index) value:頂點的值(data)
bool Binary_Tree<T>::Insert(int target, T value){
    //空樹
    if(root == nullptr){
        root = new Node<T>;
        root->index = target;
        root->data = value;
        root->left = nullptr;
        root->right = nullptr;
        return true;
    }

    Node<T>* current = root; //一開始current指標在樹根
    while(true){
        //有重複的頂點
        if(current->index == target){
            return false;
        }
        //如果target的index小於現在的，則向左走
        else if(target < current->index){
            //若左子點為空
            if(current->left == nullptr){
                current->left = new Node<T>;
                current->left->index = target;
                current->left->data = value;
                current->left->left = nullptr;
                current->left->right = nullptr;
                return true;
            }
            current = current->left;
        }
        //向右走
        else{
            if(current->right == nullptr){
                current->right = new Node<T>;
                current->right->index = target;
                current->right->data = value;
                current->right->left = nullptr;
                current->right->right = nullptr;
                return true;
            }
            current = current->right;
        }
    }
}

//搜尋
template <typename T>
Node<T>* Binary_Tree<T>::Search(int target){
    //空樹
    if(root == nullptr){
        return nullptr;
    }

    Node<T>* current = root; //一開始current指標在樹根
    while(true){
        //有重複的頂點
        if(current->index == target){
            return current;
        }
        //如果target的index小於現在的，則向左走
        else if(target < current->index){
            //若左子點為空
            if(current->left == nullptr){
                return nullptr;
            }
            current = current->left;
        }
        //向右走
        else{
            if(current->right == nullptr){
                return nullptr;
            }
            current = current->right;
        }
    }
}


int main(void){
    Binary_Tree<string> tree;

    tree.Insert(1, "Nick");
    tree.Insert(2, "Jim");
    tree.Insert(3, "Sam");

    Node<string>* found = tree.Search(2);
    tree.Print(*found);

    return 0;
}