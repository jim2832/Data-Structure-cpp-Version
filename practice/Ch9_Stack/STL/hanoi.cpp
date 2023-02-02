#include <iostream>
#include <stack>
using namespace std;

stack<int> A;
stack<int> B;
stack<int> C;

void print_stack(stack<int> &s){
    if(s.empty()){
        return;
    }
    int data = s.top();
    s.pop();
    print_stack(s);
    cout << data << " ";
    s.push(data);
}

void print_all(){
    cout << endl << "A: ";
    print_stack(A);
    cout << endl << "B: ";
    print_stack(B);
    cout << endl << "C: ";
    print_stack(C);
    cout << endl << "--------------";
}

void Hanoi(int N, stack<int> &from, stack<int> &to, stack<int> &other){
    if(N == 1){
        //只要移動一個就結束
        to.push(from.top());
        from.pop();
        print_all();
        return;
    }
    else{
        //從左邊將N-1個盤子移動到中間
        Hanoi(N-1, from, other, to);

        //將左邊最大的移動到最右邊的
        to.push(from.top());
        from.pop();
        print_all();

        //將中間的N-1個盤子從中間移動到右邊
        Hanoi(N-1, other, to, from);
    }
}

int main(void){
    int N;
    cout << "Please enter a number: ";
    cin >> N;

    //製作河內塔本身
    for(int i=N; i>0; i--){
        A.push(i);
    }

    cout << endl << "--------------";
    Hanoi(N, A, C, B);

    return 0;
}