#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(void){
    string str;
    cout << "Please enter a string: ";
    cin >> str;
    stack<char> s;

    //將每個字元push到stack中
    for(char c:str){
        s.push(c);
    }

    cout << "The reverse string is: ";
    //依序提出字元並印出來
    while(!s.empty()){
        cout << s.top();
        s.pop();
    }

    return 0;
}