#include <iostream>
#include <deque>
using namespace std;

int main(void){
    int N;
    cout << "Please enter a number: ";
    cin >> N;
    deque<int> Deque;

    for(int i=1; i<=N; i++){
        Deque.push_back(i);
    }

    while(Deque.size() > 1){
        Deque.pop_front();
        int temp = Deque.front();
        Deque.pop_front();
        Deque.push_back(temp);
    }

    cout << "Last: " << Deque.front();

    return 0;
}