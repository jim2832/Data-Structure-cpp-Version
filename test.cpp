#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;

int main(void){
    vector<int> nums = {100000,0,100000,0,100000,0,100000,0,100000,0,100000,0};
    nums.erase(unique(nums.begin(),nums.end()),nums.end());
    int old_len = nums.size() / 2; //the type number that Alice can eat
    nums.erase(unique(nums.begin(),nums.end()),nums.end()); //移除重複項
    int new_len = nums.size();
    cout << old_len << endl << new_len << endl;

    return 0;
}