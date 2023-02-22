#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
    public:
        vector<int> runningSum(vector<int>& nums) {
            //input: [1,2,3,4]
            //output: [1,3,6,10]
            vector<int> result;
            int cur_sum = 0;
            for(int i=0; i<nums.size(); i++){
                cur_sum += nums[i];
                result.push_back(cur_sum);
            }
            return result;
        }
};