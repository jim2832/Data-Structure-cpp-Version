#include <iostream>
#include "Double_Linked_List.h"
#include "Circular_Linked_List.h"
using namespace std;

int main() {
    Linked_List<int> list;

    /*
    list.Push_Back(2);
    list.Push_Back(2);
    list.Push_Back(3);
    list.Push_Back(4);
    list.Push_Back(2);
    list.Push_Back(2);
    list.Push_Back(7);
    list.Push_Back(2);
    for(auto iter=list.Begin();iter != list.End();iter++){
        cout << *iter << " ";
    }
    cout << endl;
    for(auto iter=Begin(list);iter != End(list);iter++){
        cout << *iter << " ";
    }
    cout << endl;

    auto iter=Begin(list);
    Advance(iter, 3);
    cout << *iter << endl;
    // 4

    Advance(iter, -2);
    cout << *iter << endl;
    // 2

    auto iter_1 = Find(list, 5);
    auto iter_2 = Find(list, 8);
    cout << Distance(iter_1, iter_2);
    // 3

    for(auto iter=list.Begin();iter != list.End();iter++){
        cout << *iter << " ";
    }
    cout << endl;
    list.Remove(2);
    for(auto iter=list.Begin();iter != list.End();iter++){
        cout << *iter << " ";
    }
    */

    // Circular test
    list.Push_Back(1);
    list.Push_Back(2);
    list.Push_Back(3);
    list.Push_Back(4);
    list.Push_Back(5);
    list.Push_Back(6);
    list.Push_Back(7);
    list.Push_Back(8);
    bool first = true;
    for(auto iter=list.Begin();iter != list.Begin() || first;iter++){
        cout << *iter << " ";
        if(first)
            first = false;
    }
    cout << endl;

    list.Rotate(3);
    first = true;
    for(auto iter=list.Begin();iter != list.Begin() || first;iter++){
        cout << *iter << " ";
        if(first)
            first = false;
    }

    return 0;
}