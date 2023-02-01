#include <iostream>
#include <stack>

using namespace std;

void print_stack(stack<int> &s){
    if(s.empty()){
        return;
    }
    int Top = s.top();
    s.pop();
    print_stack(s); //遞迴
    cout << Top << " ";
    s.push(Top);
}

int main(){
    stack<int> Stack;

    for(int i=0; i<10; i++){
        Stack.push(i);
    }
    cout << Stack.top() << endl;

    for(int i=0; i<5; i++){
        Stack.pop();
    }

    cout << Stack.top() << endl << Stack.size() << endl;

    return 0;
}