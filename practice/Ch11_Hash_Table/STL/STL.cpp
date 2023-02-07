#include <iostream>
#include <map>
#include <string>
#include <unordered_map>
using namespace std;

int main(){
    unordered_map<string, int> balance;
    balance["Jim"] = 100;
    balance.insert(pair<string, int>("Amy", 500));
    for(auto& element:balance){
        cout << "Key: " << element.first << ", Value: " << element.second << endl;
    }

    //如果有找到資料就印出來
    auto iter = balance.find("Jim");
    if(iter != balance.end()){
        cout << "Value: " << iter->second << endl;
    }
    else{
        cout << "Not found in this map!" << endl;
    }

    //因為已經刪除Key所以找不到
    balance.erase("Jim");
    iter = balance.find("Jim");
    if(iter != balance.end()){
        cout << "Value: " << iter->second << endl;
    }
    else{
        cout << "Not found in this map!" << endl;
    }
    for(iter=balance.begin(); iter!=balance.end(); iter++){
        cout << "Key: " << iter->first << ", Value: " << iter->second << endl;
    }

    return 0;
}