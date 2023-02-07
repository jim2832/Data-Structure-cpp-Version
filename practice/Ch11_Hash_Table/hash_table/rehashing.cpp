#include <iostream>
#include <math.h>
#include <vector>
#include <list>
#include <stdlib.h>
using namespace std;

template <typename T1, typename T2>
struct Data{
    T1 Key;
    T2 Value;
};

// hash table
template <typename T1, typename T2>
class Unordered_Map{
    private:
        int len; //陣列大小
        int amount; //紀錄有幾筆資料
        vector<list<Data<T1,T2>>> data; //存linked list 的 vector
        int Hash_Function_Div(T1);
        int Hash_Function_Mul(T1);
        void Rehashing();
        
    public:
        Unordered_Map(int = 128); //建構式
        T2& operator[](T1); //重載[]
        void Print(); //印出資料
};

//建構式
template <typename T1, typename T2>
Unordered_Map<T1,T2>::Unordered_Map(int m){
    len = m;
    amount = 0;
    data.resize(m);
}

//利用除法
template <typename T1, typename T2>
int Unordered_Map<T1,T2>::Hash_Function_Div(T1 input){
    long long int sum = 0;
    for(char c:input){
        sum += c;
    }
    return sum % len;
}

//利用乘法
template <typename T1, typename T2>
int Unordered_Map<T1,T2>::Hash_Function_Mul(T1 input){
    long long int sum = 0;
    double c = (sqrt(5)-1)/2.0;
    int temp = 1;
    for(char c:input){
        sum += temp * c;
        temp *= 256;
    }
    //取出 c * sum 的小數部分
    double frac = c * sum - (int)(c * sum);
    int index = frac * len;
    return index;
}

// rehashing -> 重新調整向量大小
template <typename T1, typename T2>
void Unordered_Map<T1,T2>::Rehashing(){
    len *= 2; //長度變兩倍
    vector<list<Data<T1,T2>>> new_data(len); //新的vector
    //將舊資料移至新vector
    for(int i=0; i<data.size(); i++){
        // data[i] -> linked list
        for(auto iter=data[i].begin(); iter!=data[i].end(); iter++){
            T1 key = (*iter).Key;
            T2 value = (*iter).Value;
            int index = Hash_Function_Mul(key); //計算舊資料在新 hash table 內的 index
            new_data[index].push_back(Data<T1,T2>{key,value});
        }
    }
    data = new_data;
}

//重載[] -> 用來新增資料
template <typename T1, typename T2>
T2& Unordered_Map<T1,T2>::operator[](T1 input){
    int index = Hash_Function_Mul(input);
    //data[index]: linked list
    for(auto iter=data[index].begin(); iter!=data[index].end(); iter++){
        //若有找到相符的Key則直接輸出他的Value
        if((*iter).Key == input){
            return (*iter).Value;
        }
    }
    amount++;
    if(amount/len > 5){
        Rehashing();
        int index = Hash_Function_Mul(input);
    }
    //若沒找到則在linked list尾端新增資料
    data[index].push_back(Data<T1,T2>{input, 0});
    return data[index].back().Value;
}

//印出資料
template <typename T1, typename T2>
void Unordered_Map<T1,T2>::Print(){
    for(int i=0; i<data.size(); i++){
        // data[i] -> linked list
        cout << i << "-th: ";
        for(auto iter=data[i].begin(); iter!=data[i].end(); iter++){
            T1 key = (*iter).Key;
            T2 value = (*iter).Value;
            cout << "{" << key << ", " << value << "} ";
        }
        cout << endl;
    }
}

int main(void){
    Unordered_Map<string,int> balance(1);
    balance["Jim"] = 50;
    balance["Sam"] = 100;
    balance["Amy"] = 31;
    balance["Judy"] = 66;
    balance["Peter"] = 32;

    balance.Print();
    balance["Sandy"] = 60;
    balance.Print();

    cout << balance["Jim"] << endl << balance["Sam"] << endl;

    return 0;
}