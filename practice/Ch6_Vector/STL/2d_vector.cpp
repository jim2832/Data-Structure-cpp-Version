#include <iostream>
#include <string>
#include <vector>
using namespace std;

//vector為5*7
int main(void){
    //第一種方法
    vector<vector<int>> vec(5);

    //第二種方法
    vector<int> vec2[5];

    //第三種方法
    for(int i=0; i<vec.size(); i++){
        vec[i].resize(7);
    }

    return 0;
}