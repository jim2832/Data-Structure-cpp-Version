#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <unordered_map>
#include <vector>
#include <stdlib.h>
using namespace std;

int main(){
    ifstream file("A-large-practice.in");
    ofstream ofile("Testoutput.txt");

    vector<int> data; //存物品的向量
    unordered_map<int, int> number_index; //雜湊表

    //檢查開檔成功
    if(file && ofile){
        //input
        int data_count, total_price, stuff_count;
        file >> data_count;
        for(int i=0; i<data_count; i++){
            file >> total_price >> stuff_count;
            data.resize(stuff_count);
            for(int j=0; j<stuff_count; j++){
                file >> data[j];
            }
            //每次有一筆新金額時 檢查total_price - data[j]是否存在於hash table中
            for(int j=0; j<stuff_count; j++){
                auto iter = number_index.find(total_price - data[j]); //透過迭代器去找目標
                //如果有找到
                if(iter != number_index.end()){
                    ofile << "Case #" << i+1 << ": " << number_index[total_price - data[j]] + 1 << " " << j+1 << endl;
                    cout << "Case #" << i+1 << ": " << number_index[total_price - data[j]] + 1 << " " << j+1 << endl;
                    break;
                }
                //如果沒找到
                number_index[data[j]] = j; //key and value -> key:150, value:0
            }
            number_index.clear(); //清除hash table
        }
    }

    return 0;
}