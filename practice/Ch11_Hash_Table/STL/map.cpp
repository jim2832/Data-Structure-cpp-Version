#include <iostream>
#include <time.h>
#include <map>
#include <unordered_map>
using namespace std;

int main(){
    map<int, int> Map;
    map<int, int>::iterator iter;

    //搜尋
    iter =  Map.find(Key);

    //刪除
    iter =  Map.find(Key);
    Map.erase(iter);
    bool flag = Map.erase(Key);

    //全部清空
    bool flag = Map.erase(Map.begin(), Map.end());
    Map.clear();

    //判斷是否為空
    bool flag = Map.empty();

    //取出所有資料
    for(auto& element:Map){
        cout << "Key: " << element.first << ", Value: " << element.second << endl;
    }

    //設定大小
    Map.rehash(len);

    //擴充容量
    Map.reserve(len);

    //取出雜湊韓式的韓式指標
    auto hash_func = Map.hash_function();

    //取出比較key的函式指標
    auto key_eq_func = Map.key_eq();

    return 0;
}