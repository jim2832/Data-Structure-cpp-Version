#include <iostream>
#include "stack.h"

using namespace std;

int main(){
    Stack_Array<int> stack;

    for(int i=0; i<5; i++){
        stack.Push(i);
        stack.Print_Stack();
    }
    cout << endl;

    for(int i=0; i<5; i++){
        stack.Print_Stack();
        //cout << stack.Top() << " ";
        stack.Pop();
    }

    //stack.Print_Stack();

    return 0;
}