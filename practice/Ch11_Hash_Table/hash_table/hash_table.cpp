#include <iostream>
#include <math.h>
#include <stdlib.h>
using namespace std;

template <typename T1, typename T2>
struct Data{
    T1 Key;
    T2 Value;
};

// Balance["Jim"]
template <typename T1, typename T2>
class Unordered_Map{
    private:
        int len; //陣列大小
        Data<T1,T2>* Pointer; //指向結構的指標
        int Hash_Function_Div(T1);
        int Hash_Function_Mul(T1);

    public:
        Unordered_Map(int = 128); //建構式
        T2& operator[](T1); //重載[]
};

//建構式
template <typename T1, typename T2>
Unordered_Map<T1,T2>::Unordered_Map(int m){
    len = m;
    Pointer = (Data<T1,T2>*)malloc(sizeof(Data<T1,T2>) * len);
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

//重載[]
template <typename T1, typename T2>
T2& Unordered_Map<T1,T2>::operator[](T1 input){
    int index = Hash_Function_Mul(input);
    cout << "index: " << index << endl;
    Pointer[index].Key = input;
    return Pointer[index].Value;
}

int main(void){
    string str;
    cout << "Please enter a string: ";
    cin >> str;
    int number;
    cout << "Please enter a number: ";
    cin >> number;

    Unordered_Map<string,int> balance;
    balance["Jim"] = 50;
    balance["Sam"] = 100;

    //cout << balance["Jim"];

    return 0;
}