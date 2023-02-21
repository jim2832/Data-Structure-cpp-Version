#include <iostream>
#include <string>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
using namespace std;

class Solution {
    public:
        int trailingZeroes(int n) {
            // 5的數量會決定10的數量，因為2很多
            // 因此尾數中0的數量 = 5的數量
            int count = 0;
            while(n != 0){
                count += n / 5;
                n /= 5;
            }
            return count;
        }
};