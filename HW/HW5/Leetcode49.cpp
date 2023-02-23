#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <unordered_map>
using namespace std;

class Solution {
    public:
        vector<vector<string>> groupAnagrams(vector<string>& strs) {
            //建立hash table
            unordered_map<string, vector<string>> m;
            for(string s:strs){
                string t = s;
                sort(t.begin(), t.end());
                m[t].push_back(s);
            }

            //輸出結果
            vector<vector<string>> result;
            for(auto s:m){
                result.push_back(s.second);
            }
            return result;
        }
};