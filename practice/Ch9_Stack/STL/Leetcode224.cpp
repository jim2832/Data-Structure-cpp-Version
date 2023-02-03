#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Solution{
    public:
        int calculate(string s){
            stack<int> numbers; //存值
            stack<int> signs; //存運算元 //+1表示+ -1表示-
            long long int value = 0;
            int sign = +1; //+1表示+ -1表示-
            long long int result = 0; // a + b + c
            // ((a+b)+c)

            for(char c:s){
                //數字(運算元)
                if(c>= '0' && c <= '9'){
                    value = value * 10 + c - '0'; //char轉int '9' -> 9
                }
                //左括號
                else if(c == '('){
                    numbers.push(result); //將之前算完的結果先存進stack
                    signs.push(sign); //將正負號存進stack
                    value = result = 0; //歸零
                    sign = 1;
                }
                //右括號
                else if(c == ')'){
                    result += sign * value;
                    result *= signs.top();
                    signs.pop();
                    result += numbers.top();
                    numbers.pop();
                    value = 0;
                    sign = 1;
                }
                // +運算子
                else if(c == '+'){
                    // a + b + c
                    result += sign * value;
                    sign = 1;
                    value = 0;
                }
                // -運算子
                else if(c == '-'){
                    // a + b + c
                    result += sign * value;
                    sign = -1;
                    value = 0;
                }
            }
            if(value){
                // a + b + c
                result += sign * value;
            }
            return result;
        }
};