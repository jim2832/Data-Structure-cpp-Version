#include <iostream>
#include <queue>
using namespace std;

int main(){
    queue<char> boys, girls;
    int rounds, boy_num, girl_num;

    cout << "Please enter the rounds, boy number and the girl number: ";
    cin >> rounds >> boy_num >> girl_num;

    for(int i=0; i<boy_num; i++){
        boys.push('A' + i); //i=0 -> A , i=1 -> B ...
    }

    for(int i=0; i<girl_num; i++){
        girls.push('a' + i);
    }

    cout << "It's party time!" << endl;
    for(int i=0; i<rounds; i++){
        //男女各取出一個來跳舞
        char boy = boys.front();
        boys.pop();
        char girl = girls.front();
        girls.pop();

        cout << "Rounds " << i+1 << ": " << boy << " <--> " << girl << endl;

        //重新列隊
        boys.push(boy);
        girls.push(girl);
    }

    return 0;
}