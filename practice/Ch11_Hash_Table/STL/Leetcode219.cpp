#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution{
    public:
        bool containsNearbyDuplicate(vector<int>& nums, int k){
            unordered_map<int, int> index; //紀錄某個數字上一次出現的index
            for(int i=0; i<nums.size(); i++){
                // 檢查nums[i]是否有出現在index過
                auto iter = index.find(nums[i]);
                if(iter != index.end()){
                    //index[nums[i]]代表nums[i]所對應到的value(也就是上一次出現的位置)
                    if(i - index[nums[i]] <= k){
                        return true;
                    }
                }
                index[nums[i]] = i; //更新位置
            }
            return false;
        }
};