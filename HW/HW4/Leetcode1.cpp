#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            unordered_map<int, int> hash; //key: num, value: index
            vector<int> result;

            for(int i=0; i<nums.size(); i++){
                //尋找num[i]是否有出現在hash中
                auto iter = hash.find(target - nums[i]);
                //找到
                if(iter != hash.end()){
                    result.push_back(hash[target - nums[i]]);
                    result.push_back(i);
                }
                hash[nums[i]] = i;
            }

            return result;
        }
};