#include <iostream>
using namespace std;

void Max_Heapify(int *data, int root, int len){ //陣列開始點、樹根、陣列長度
    int left = 2 * root + 1; //左子點
    int right = 2 * root + 2; //右子點

    int largest = root;

    //若左子點在陣列內 且 這個資料比上面的節點大 則更新
    if(left < len && data[left] > data[largest]){
        largest = left;
    }
    //若右子點在陣列內 且 這個資料比上面的節點大 則更新
    if(right < len && data[right] > data[largest]){
        largest = right;
    }
    //若目前的樹根並不是最大值 (不符合Max-Heap)
    if(largest != root){
        //把 data[root] 和 data[largest] 互換
        int temp = data[root];
        data[root] = data[largest];
        data[largest] = temp;
        Max_Heapify(data, largest, len); //因為原本 data[largest] 的節點有被更動過，則其底下的子樹也要做Heapify
    }
}

void Min_Heapify(int *data, int root, int len){ //陣列開始點、樹根、陣列長度
    int left = 2 * root + 1; //左子點
    int right = 2 * root + 2; //右子點

    int smallest = root;

    //若左子點在陣列內 且 這個資料比上面的節點小 則更新
    if(left < len && data[left] < data[smallest]){
        smallest = left;
    }
    //若右子點在陣列內 且 這個資料比上面的節點小 則更新
    if(right < len && data[right] < data[smallest]){
        smallest = right;
    }
    //若目前的樹根並不是最小值 (不符合Min-Heap)
    if(smallest != root){
        //把 data[root] 和 data[smallest] 互換
        int temp = data[root];
        data[root] = data[smallest];
        data[smallest] = temp;
        Min_Heapify(data, smallest, len); //因為原本 data[smallest] 的節點有被更動過，則其底下的子樹也要做Heapify
    }
}

//建立 Max-Heap
void Build_Max_Heap(int *arr, int len){
    for(int i=(len/2)-1; i>=0; i--){
        Max_Heapify(arr, i, len);
    }
}

//建立Min-Heap
void Build_Min_Heap(int *arr, int len){
    for(int i=(len/2)-1; i>=0; i--){
        Min_Heapify(arr, i, len);
    }
}

void Print_Array(int *arr, int len){
    cout << "Array: ";
    for(int i=0; i<len; i++){
        cout << arr[i] << " ";
    }
    cout << endl << endl;
}

int main(void){
    int data[] = {15, 18, 6, 25, 8, 11, 34, 20, 2, 38};

    cout << "Before Heapify: " << endl;
    Print_Array(data, 10);

    cout << "After Max-Heapify: " << endl;
    Build_Max_Heap(data, 10);
    Print_Array(data, 10);

    cout << "After Min-Heapify: " << endl;
    Build_Min_Heap(data, 10);
    Print_Array(data, 10);

    return 0;
}