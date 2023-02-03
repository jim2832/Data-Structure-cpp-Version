#include <iostream>
#include <deque>
using namespace std;

bool isValid(string str){
    deque<char> Deque;
    for(char c:str){
        if(c == '(' || c == '[' || c == '{'){
            Deque.push_back(c);
            continue;
        }
        if((c == ')' || c == ']' || c == '}') && Deque.empty()){
            cout << "Error";
            return false;
        }

        if(c == ')'){
            if(Deque.back() == '('){
                Deque.pop_back();
            }
            else{
                return false;
            }
        }
        else if(c == ']'){
            if(Deque.back() == '['){
                Deque.pop_back();
            }
            else{
                return false;
            }
        }
        else if(c == '}'){
            if(Deque.back() == '{'){
                Deque.pop_back();
            }
            else{
                return false;
            }
        }
    }
    if(Deque.empty()){
        return true;
    }
    else{
        return false;
    }
}

int main(void){
    string str = "{[a+b+(s+f)-d]+2}";

    if(isValid(str)){
        cout << "Valid!" << endl;
    }
    else{
        cout << "Not valid!" << endl;
    }

    return 0;
}