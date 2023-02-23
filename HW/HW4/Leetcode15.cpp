#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
using namespace std;

class Solution {
    public:
        vector<vector<int>> threeSum(vector<int>& nums) {
            sort(nums.begin(), nums.end()); //將input排序
            int target = 0;
            set<vector<int>> s; //存三個數的集合
            vector<vector<int>> result;

            for(int i=0; i<nums.size(); i++){
                int j = i + 1; //第一個指標：從i+1開始
                int k = nums.size() - 1; //第二個指標：從最後一個index開始
                while(j < k){
                    int sum = nums[i] + nums[j] + nums[k];
                    //如果相加剛好是0
                    if(sum == target){
                        s.insert({nums[i], nums[j], nums[k]});
                        j++;
                        k--;
                    }
                    //如果相加<0
                    else if(sum < target){
                        j++;
                    }
                    //相加>0
                    else{
                        k--;
                    }
                }
            }

            for(auto triplets:s){
                result.push_back(triplets);
            }
            return result;
        }
};