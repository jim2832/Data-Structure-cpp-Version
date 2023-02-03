#include <iostream>
#include <stack>
using namespace std;

class MyQueue{
    public:
        stack<int> data, temp;

        MyQueue(){
        }

        void push(int x){
            data.push(x);
        }

        int pop(){
            //將data stack push到temp(反序)
            while(!data.empty()){
                temp.push(data.top());
                data.pop();
            }

            //存要回傳的資料
            int result = temp.top();
            temp.pop();

            //將資料放回去原本的stack
            while(!temp.empty()){
                data.push(temp.top());
                temp.pop();
            }

            return result;
        }

        int peek(){
            //將data stack push到temp(反序)
            while(!data.empty()){
                temp.push(data.top());
                data.pop();
            }

            //存要回傳的資料
            int result = temp.top();

            //將資料放回去原本的stack
            while(!temp.empty()){
                data.push(temp.top());
                temp.pop();
            }

            return result;
        }

        bool empty(){
            return data.empty();
        }
};