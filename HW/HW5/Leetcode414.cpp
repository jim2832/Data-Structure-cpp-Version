#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

class Solution {
    public:
        int thirdMax(vector<int>& nums) {
            stack<int> s;
            sort(nums.begin(), nums.end()); //排序
            nums.erase(unique(nums.begin(),nums.end()),nums.end()); //移除重複項
            for(int i=0; i<nums.size(); i++){
                s.push(nums[i]);
            }

            //另一種解法
            /*
            int max = s.top();
            s.pop();
            if(s.empty()){
                return max;
            }
            int second_max = s.top();
            s.pop();
            if(s.empty()){
                return max;
            }
            */


            if(s.size() < 3){
                return s.top();
            }
            else{
                s.pop();
                s.pop();
                return s.top();
            }

        }
};