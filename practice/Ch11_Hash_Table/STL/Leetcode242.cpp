#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution{
    public:
        bool isAnagram(string s, string t){
            //檢查長度是否一樣
            if(s.size() != t.size()){
                return false;
            }
            unordered_map<char, int> count; //紀錄每個字元出現的次數

            //檢查string s
            for(char c:s){
                auto iter = count.find(c);
                //檢查c是否有在hash table中出現過
                if(iter != count.end()){
                    count[c]++;
                }
                else{
                    count[c] = 1; //第一次出現
                }
            }

            //檢查string t
            for(char c:t){
                auto iter = count.find(c);
                //檢查c是否有在hash table中出現過
                if(iter != count.end()){
                    // 字元c出現的次數要>0才能減
                    if(count[c] > 0){
                        count[c]--;
                    }
                    else{
                        return false;
                    }
                }
                //若t中的字元不存在於hash table，則代表兩個字串有不同的字
                else{
                    return false;
                }
            }

            return true;
        }  
};