#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution{
    public:
        bool containsDuplicate(vector<int>& nums){
            unordered_map<int, bool> existed;
            for(int num:nums){
                auto iter = existed.find(num);
                //檢查是否存在
                if(iter != existed.end()){
                    return true;
                }
                existed[num] = true;
            }
            return false;
        }
};