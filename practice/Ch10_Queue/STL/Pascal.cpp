#include <iostream>
#include <queue>
using namespace std;

int main(){
    int N;
    cout << "Please enter a number: ";
    cin >> N;

    queue<int> Queue;
    int temp1, temp2;

    cout << "Pascal Triangle: " << endl;
    Queue.push(1);
    cout << 1 << endl;

    //印row2 -> N
    for(int i=2; i<=N; i++){
        temp1 = 0;
        for(int j=1; i<=i-1; j++){
            temp2 = Queue.front();
            Queue.pop();
            cout << temp1 + temp2 << " ";
            Queue.push(temp1 + temp2);
            temp1 = temp2;
        }
        Queue.push(1);
        cout << 1 << endl;
    }

    return 0;
}