#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(void){
    string str = "((a+(b*c))+d)";
    stack<char> sign;

    for(char c:str){
        //左括號
        if(c == '('){
            continue;
        }
        //運算元
        else if(c >= 'a' && c <= 'z'){
            cout << c;
        }
        //右括號
        else if(c == ')'){
            cout << sign.top();
            sign.pop();
        }
        //運算子
        else{
            sign.push(c);
        }
    }

    return 0;
}