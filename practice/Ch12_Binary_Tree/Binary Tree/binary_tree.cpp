#include <iostream>
#include <string>
#include <queue>
using namespace std;

template <typename T>
struct Node{
    int index; //頂點的編號
    T data; //存資料
    Node<T> *left; //指向左節點的指標
    Node<T> *right; //指向右節點的指標
    Node<T> *parent; //指向父節點
};

template <typename T>
class Binary_Tree{
    public:
        Node<T>* root; //樹根
        Binary_Tree(); //建構式
        void Print(Node<T>); //印出節點
        bool Insert(int, T); //插入節點(若有插入成功則回傳true)
        bool Delete(int); //刪除節點(若有刪除成功則回傳true)
        Node<T>* Search(int); //尋找某個節點
        void Pre_Order(Node<T>*); //前序走訪
        void In_Order(Node<T>*); //中序走訪
        void Post_Order(Node<T>*); //後序走訪
        void Level_Order(Node<T>*); //level order
        Node<T>* Left_Most(Node<T>*); //回傳最左邊的節點
        Node<T>* Right_Most(Node<T>*); //回傳最右邊的節點
        Node<T>* Predecessor(Node<T>*); //回傳在中序中的前一個
        Node<T>* Successor(Node<T>*); //回傳在中序中的後一個
};

//建構式
template <typename T>
Binary_Tree<T>::Binary_Tree(){
    root = nullptr; //一棵空的樹
}

//印出節點
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
        root->parent = nullptr;
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
                current->left->parent = current;
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
                current->right->parent = current;
                return true;
            }
            current = current->right;
        }
    }
}

//刪除節點
template <typename T>
bool Binary_Tree<T>::Delete(int target){
    Node<T>* delete_node = Search(target);
    
    //如果根本沒有這個頂點
    if(delete_node == nullptr){
        return false;
    }

    //Case 1: 刪除的節點 degree 為 0 (也就是樹葉)
    if(delete_node->left == nullptr && delete_node->right == nullptr){
        //刪除的節點是樹根且總共只有一筆資料
        if(delete_node == root){
            root = nullptr;
        }
        //刪除的節點是父節點的左子點
        if(delete_node == delete_node->parent->left){
            delete_node->parent->left = nullptr;
        }
        //刪除的節點是父節點的右子點
        else{
            delete_node->parent->right = nullptr;
        }
        delete delete_node;
    }

    //Case 3: 刪除的節點 degree 為 2 (有左右子點)
    else if(delete_node->left != nullptr && delete_node->right != nullptr){
        // 用後繼者來取代要刪除的節點
        Node<T>* successor = Left_Most(delete_node->right); //右子樹的最小值
        int temp1 = successor->index; //先將後繼者的索引存起來
        T temp2 = successor->data; //先將後繼者的資料存起來
        Delete(successor->index); //之所以可以用遞迴 是因為successor的degree只會是0或1 因為如果degree是2的話代表還能往左走
        delete_node->index = temp1;
        delete_node->data = temp2;
    }
    
    //Case 2: 刪除的節點 degree 為 1 (有一個子節點)
    else{
        Node<T>* child = (delete_node->left != nullptr)?delete_node->left:delete_node->right; //指向子點的指標
        //如果刪除的是樹根
        if(delete_node == root){
            root = child;
        }
        //如果要刪除的節點是父節點的左節點
        if(delete_node == delete_node->parent->left){
            delete_node->parent->left = child; //將父節點的左指標指向刪除節點的子節點
        }
        //如果要刪除的節點是父節點的右節點
        else{
            delete_node->parent->right = child; //將父節點的右指標指向刪除節點的子節點
        }
        delete delete_node;
    }

    return true;
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

//前序走訪
template <typename T>
void Binary_Tree<T>::Pre_Order(Node<T>* node){
    //空樹
    if(node == nullptr) return;

    cout << node->index << " "; //走訪中間
    Pre_Order(node->left); //走訪左節點
    Pre_Order(node->right); //走訪右節點
}

//中序走訪
template <typename T>
void Binary_Tree<T>::In_Order(Node<T>* node){
    //空樹
    if(node == nullptr) return;

    In_Order(node->left); //走訪左節點
    cout << node->index << " "; //走訪中間
    In_Order(node->right); //走訪右節點
}

//後序走訪
template <typename T>
void Binary_Tree<T>::Post_Order(Node<T>* node){
    //空樹
    if(node == nullptr) return;

    Post_Order(node->left); //走訪左節點
    Post_Order(node->right); //走訪右節點
    cout << node->index << " "; //走訪中間
}

//level order (利用queue來實作)
template <typename T>
void Binary_Tree<T>::Level_Order(Node<T>* node){
    queue<Node<T>*> Queue;
    Queue.push(node);

    while(!Queue.empty()){
        Node<T>* current = Queue.front(); //目前走訪到的節點
        Queue.pop();
        cout << current->index;

        //如果現在指標的位置有左子點，則push進queue
        if(current->left){
            Queue.push(current->left);
        }
        if(current->right){
            Queue.push(current->right);
        }
    }
}

//最左邊的節點
template <typename T>
Node<T>* Binary_Tree<T>::Left_Most(Node<T>* node){
    if(node == nullptr){
        return nullptr;
    }
    while(node->left != nullptr){
        node = node->left;
    }
    return node;
}

//最右邊的節點
template <typename T>
Node<T>* Binary_Tree<T>::Right_Most(Node<T>* node){
    if(node == nullptr){
        return nullptr;
    }
    while(node->right != nullptr){
        node = node->right;
    }
    return node;
}

//中序中的前一個
template <typename T>
Node<T>* Binary_Tree<T>::Predecessor(Node<T>* node){
    //node有左子樹
    if(node->left != nullptr){
        return Right_Most(node->left);
    }
    //node沒有左子樹 (左子樹為空)
    Node<T>* current = node->parent; //current為父節點
    //如果現在指的節點不為空 以及 現在指的節點是父節點的左子點 則繼續做
    while(current != nullptr && node == current->left){
        node = current; //現在的子點往上走
        current = current->parent; //current往上走
    }
    return current; //最後回傳current 也就是要的結果
}

//中序中的後一個
template <typename T>
Node<T>* Binary_Tree<T>::Successor(Node<T>* node){
    //node有右子樹
    if(node->right != nullptr){
        return Left_Most(node->right);
    }
    //node沒有右子樹 (右子樹為空)
    Node<T>* current = node->parent; //current為父節點
    //如果現在指的節點不為空 以及 現在指的節點是父節點的右子點 則繼續做
    while(current != nullptr && node == current->right){
        node = current; //現在的子點往上走
        current = current->parent; //current往上走
    }
    return current; //最後回傳current 也就是要的結果
}


int main(void){
    Binary_Tree<string> tree;

    tree.Insert(58, "A");
    tree.Insert(24, "B");
    tree.Insert(97, "C");
    tree.Insert(12, "D");
    tree.Insert(49, "E");
    tree.Insert(82, "F");
    tree.Insert(55, "G");

    tree.Delete(58);

    //前序
    cout << "Pre-order(前序): ";
    tree.Pre_Order(tree.root);
    cout << endl;

    //中序
    cout << "In-order(中序): ";
    tree.In_Order(tree.root);
    cout << endl;

    //後序
    cout << "Post-order(後序): ";
    tree.Post_Order(tree.root);
    cout << endl;

    //level order
    cout << "Level-order: ";
    tree.Level_Order(tree.root);
    cout << endl;

    //最左邊的點
    cout << "Left most of 24(24最左邊的點): " << tree.Left_Most(tree.Search(24))->index << endl;
    //最右邊的點
    cout << "Right most of 24(24最右邊的點): " << tree.Right_Most(tree.Search(24))->index << endl;

    //前繼點
    cout << "Predecessor(前繼點) of 55: " << tree.Predecessor(tree.Search(55))->index << endl;
    //後繼點
    cout << "Successor(後繼點) of 82: " << tree.Successor(tree.Search(82))->index << endl;

    return 0;
}