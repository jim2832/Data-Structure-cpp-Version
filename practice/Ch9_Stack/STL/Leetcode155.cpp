#include <iostream>
#include <stack>
using namespace std;

class MinStack{
    stack<int> data;
    stack<int> min; //用來記錄到目前為止最小的值

    public:
        MinStack(){
        }

        void push(int val){
            data.push(val);

            if(min.empty()){
                min.push(val);
                return;
            }

            int current_min = min.top();

            if(val < current_min){
                min.push(val);
            }
            else{
                min.push(current_min);
            }
        }

        void pop(){
            if(data.empty()){
                return;
            }
            data.pop();
            min.pop();
        }

        int top(){
            return data.top();
        }

        int getMin(){
            return min.top();
        }
};