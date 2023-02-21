#include <iostream>
#include <string>
using namespace std;

class Solution{
    public:
        string addBinary(string a, string b){
            string result;
            int a_index = a.size()-1;
            int b_index = b.size()-1;
            int carry = 0;
            while(a_index >= 0 || b_index >= 0){
                int sum = carry;
                if(a_index >= 0) sum += a[a_index--] - '0'; //取a的bit
                if(b_index >= 0) sum += b[b_index--] - '0'; //取bit
                //若sum >= 2則代表要進位
                if(sum >= 2){
                    carry = 1;
                }
                else{
                    carry = 0;
                }
                result += to_string(sum%2); //sum:要新增的bit 為 0:0 1:1 2:0 3:1
            }
            if(carry) result += to_string(carry); //最後一次檢查 若有進位在最左邊還要加上1
            reverse(result.begin(), result.end());
            return result;
        }
};