#include <iostream>
#include <queue>
using namespace std;

struct Node{
    char character; //資料
    int counts; //頻率
    Node* left;
    Node* right;
};

class Compare{
    public:
        bool operator()(Node* n1, Node* n2){
            return n1->counts > n2->counts;
        }
};

class Huffman_Tree{
    private:
        priority_queue<Node*, vector<Node*>, Compare> all_nodes;
        Node* Pop_Node(); //用來輸出頻率最低的節點

    public:
        Node* root_node; //樹根
        Huffman_Tree(); //建構式
        void Clear_Queue(); //清空佇列
        void Insert(char, int); //插入節點
        void Build_Huffman_Tree(); //建立樹
        void Print_Code_Table(); //印出編碼表
        void Traversal(Node*, queue<char>); //走訪
};

//用來輸出頻率最低的節點
Node* Huffman_Tree::Pop_Node(){
    if(all_nodes.empty()){
        return nullptr;
    }
    else{
        Node* temp = all_nodes.top();
        all_nodes.pop();
        return temp;
    }
}

//建構式
Huffman_Tree::Huffman_Tree(){
    root_node = nullptr;
}

//清空佇列
void Huffman_Tree::Clear_Queue(){
    cout << "Start to clear priorty queue in this Huffman Tree..." << endl;
    while(!all_nodes.empty()){
        Node* temp = all_nodes.top();
        cout << "Char: " << temp->character << ", Counts: " << temp->counts << endl;
        all_nodes.pop();
    }
}

//插入節點
void Huffman_Tree::Insert(char c, int freqency){
    Node* temp = new Node;
    temp->character = c;
    temp->counts = freqency;
    temp->left = nullptr;
    temp->right = nullptr;
    all_nodes.push(temp);
}

//建立樹
void Huffman_Tree::Build_Huffman_Tree(){
    while(!all_nodes.empty()){
        Node* min_node = Pop_Node();
        if(all_nodes.empty()){
            root_node = min_node;
            return;
        }
        else{
            Node* second_min_node = Pop_Node();
            int new_frequency = min_node->counts + second_min_node->counts;
            Node* temp = new Node;
            temp->character = '\0';
            temp->counts = new_frequency;
            temp->left = min_node;
            temp->right = second_min_node;
            all_nodes.push(temp);
        }
    }
}

//印出編碼表
void Huffman_Tree::Print_Code_Table(){
    if(root_node == nullptr){
        cout << "This Huffman Tree is empty!" << endl;
        return;
    }
    queue<char> route; //用queue來記錄
    Traversal(root_node, route);
}

//走訪
void Huffman_Tree::Traversal(Node* current, queue<char> route){
    //向左走
    if(current->left != nullptr){
        queue<char> left_route = route;
        route.push('0'); //往左走是0
        Traversal(current->left, left_route);
    }
    //向右走
    if(current->right != nullptr){
        queue<char> right_route = route;
        route.push('1'); //往左走是0
        Traversal(current->right, right_route);
    }
    //如果左節點=右節點，這代表左右兩邊都是空的(樹葉)
    if(current->left == current->right){
        cout << "Character: " << current->character << ", Counts: " << current->counts << ", Code: ";
        while(!route.empty()){
            char c = route.front();
            cout << c;
            route.pop();
        }
        cout << endl;
    }
}


int main(){
    Huffman_Tree code;
    code.Insert('A', 67);
    code.Insert('B', 152);
    code.Insert('C', 92);
    code.Insert('D', 263);
    code.Insert('E', 128);
    code.Insert('F', 86);
    code.Insert('G', 20);
    code.Insert('H', 36);
    code.Build_Huffman_Tree();
    code.Print_Code_Table();

    return 0;
}