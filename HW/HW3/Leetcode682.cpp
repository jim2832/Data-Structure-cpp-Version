#include <iostream>
#include <stack>
#include <queue>
#include <unordered_map>
#include <typeinfo>
using namespace std;

class Solution {
    public:
        stack<int> s;
        int calPoints(vector<string>& operations) {
            for(int i=0; i<operations.size(); i++){
                //新增一筆為「前兩筆資料總和」的資料
                if(operations[i] == "+"){
                    if(s.size() == 1){
                        s.push(s.top());
                    }
                    else if(!s.empty()){
                        int temp = s.top();
                        s.pop();
                        int temp2 = s.top();
                        s.push(temp);
                        s.push(temp + temp2);
                    }
                }

                //新增一筆為「2倍前一筆資料」的資料
                else if(operations[i] == "D"){
                    if(!s.empty()){
                        s.push(2 * s.top());
                    }
                }

                //使前一筆資料無效
                else if(operations[i] == "C"){
                    s.pop();
                }

                //新增一個int
                else{
                    s.push(stoi(operations[i]));
                }
            }

            //運算結果
            int sum = 0;
            while(!s.empty()){
                sum += s.top();
                s.pop();
            }

            return sum;
        }
};