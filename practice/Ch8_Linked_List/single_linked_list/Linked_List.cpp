#include <iostream>
#include "Linked_List.h"
using namespace std;

int main(void){
    Linked_List<int> list; //建立linked list
    list.Push_Front(1);
    list.Push_Front(2);
    list.Push_Front(3);
    list.Print_List();
    list.Pop_Front();
    list.Print_List();
    list.Pop_Front();
    list.Pop_Front();
    list.Print_List();

    list.Push_Back(1);
    list.Push_Back(2);
    list.Push_Back(3);
    list.Print_List();
    list.Pop_Back();
    list.Print_List();

    // list.Clear();
    // list.Print_List();

    list.Reverse();
    list.Print_List();

    return 0;
}