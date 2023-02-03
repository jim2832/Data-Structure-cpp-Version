#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Solution{
    stack<char> Stack;

    public:
        bool isValid(string s){
            for(char c:s){
                if(c == '(' || c == '[' || c == '{'){
                    Stack.push(c);
                    continue;
                }

                if((c == ')' || c == ']' || c == '}') && Stack.empty()){
                    return false;
                }

                if(c == ')'){
                    if(Stack.top() == '('){
                        Stack.pop();
                    }
                    else{
                        return false;
                    }
                }
                else if(c == ']'){
                    if(Stack.top() == '['){
                        Stack.pop();
                    }
                    else{
                        return false;
                    }
                }
                else if(c == '}'){
                    if(Stack.top() == '{'){
                        Stack.pop();
                    }
                    else{
                        return false;
                    }
                }
            }
            if(Stack.empty()){
                return true;
            }
            else{
                return false;
            }
        }
};