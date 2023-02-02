#include <iostream>
#include <queue>
using namespace std;

int main(){
    queue<int> Queue;

    for(int i=0; i<10; i++){
        Queue.push(i);
    }
    cout << "Front: " << Queue.front() << endl;
    cout << "Back: " << Queue.back() << endl;

    Queue.pop();
    Queue.pop();

    cout << "Front: " << Queue.front() << endl;
    cout << "Back: " << Queue.back() << endl;

    return 0;
}