#include <iostream>
#include <string>
#include <math.h>
using namespace std;

class Solution {
    public:
        int reverse(int x) {
            int sign = x < 0 ? -1 : 1;
            long int result = 0;
            x = abs(x); //使x變正數
            while(x > 0){
                result = result * 10 + x % 10;
                x /= 10; 
            }
            if(result > pow(2,31) -1 || result < -pow(2,31)){
                return 0;
            }
            return result * sign;
        }
};