#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution{
    public:
        int findMaxLength(vector<int>& nums){
            unordered_map<int, int> data; //Key:數值 Value:最早出現過的index
            data[0] = -1; //邊界條件
            int sum = 0; //紀錄加總到目前的和
            int longest = 0; //紀錄目前最長的子序列
            for(int i=0; i<nums.size(); i++){
                if(nums[i] == 1){ //if(nums[i])也可以
                    sum++;
                }
                //把0當作是-1 因此遇到了要sum--
                else{
                    sum--;
                }

                //尋找hash table中是否有紀錄這個加總值
                auto iter = data.find(sum);
                if(iter != data.end()){
                    //longest = max(longest, i-data[sum]) -> 比較之前找到的最長值和現在找到的哪個大
                    longest = longest > i-data[sum]?longest:i-data[sum];
                }
                else{
                    data[sum] = i;
                }
            }
            return longest;
            // time complexity: O(n)
        }  
};