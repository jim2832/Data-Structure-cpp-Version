#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

class Solution {
    public:
        int leastInterval(vector<char>& tasks, int n) {
            //紀錄每種 tasks 有幾個
            unordered_map<char, int> counts;
            for(char t:tasks) counts[t]++;

            //將 tasks 的數量 push 進 priority queue
            priority_queue<int> pq;
            for(auto c:counts) pq.push(c.second);

            int result = 0;
            while(!pq.empty()){
                int time = 0;
                vector<int> temp;
                for(int i=0; i<n+1; ++i){
                    if(!pq.empty()){
                        temp.push_back(pq.top()-1);
                        pq.pop();
                        time++;
                    }
                }
                for(auto t:temp)
                    if(t) pq.push(t);
                result += pq.empty() ? time : n+1;
            }
            return result;
        }
};