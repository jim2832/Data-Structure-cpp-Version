#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
using namespace std;

class Solution {
    public:
        bool isPalindrome(string s){
            int len = s.length();
            bool is_Alphanumeric = false;
            for(int i=0; i<len; i++){
                //判斷是否為數字或字母
                if(!isalnum(s[i])){
                    s[i] = ' ';
                }
                s[i] = tolower(s[i]); //轉為小寫
            }
            s.erase(std::remove(s.begin(), s.end(), ' '), s.end()); //將空格消除
            len = s.length();

            if(s.length() == 1){
                return true;
            }

            //判斷是否為回文
            for(int i=0; i<len/2; i++){
                if(s[i] != s[len-i-1]){
                    return false;
                }
            }
            return true;
        }
};