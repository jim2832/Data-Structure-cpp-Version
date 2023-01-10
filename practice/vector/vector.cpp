#include <iostream>
#include <string>
#include "vector.h"
using namespace std;

int main(void){
    Vector<int> v;

    v.Push_Back(1);
    v.Push_Back(2);
    v.Push_Back(3);
    v.Push_Back(4);
    v.Push_Back(5);
    for(int i=0; i<v.Size(); i++){
        cout << v[i] << " ";
    }
    cout << endl;

    v.Insert(4, 100);
    for(int i=0; i<v.Size(); i++){
        cout << v[i] << " ";
    }
    cout << endl;

    v.Erase(2, 4);
    for(int i=0; i<v.Size(); i++){
        cout << v[i] << " ";
    }
    cout << endl;

    v.Clear();
    for(int i=0; i<v.Size(); i++){
        cout << v[i] << " ";
    }
    cout << endl;

    // v[0] = 12;
    // v.At(3) = 10;

    // cout << "第一筆資料為: " << v.Front() << endl;
    // cout << "最後一筆資料為:" << v.Back() << endl;
    // cout << "Index 1 的元素為:" << v.At(1) << endl;
    // cout << "v[1] = " << v[1] << endl;
    // cout << "v的size為: " << v.Size() << endl;
    // cout << "v是否為空: " << v.Empty() << endl;

    return 0;
}