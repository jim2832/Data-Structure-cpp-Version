#include <iostream>
#include <math.h>
using namespace std;

//利用除法
int Hash_Function_Div(string input, int m){
    long long int sum = 0;
    for(char c:input){
        sum += c;
    }
    return sum % m;
}

//利用乘法
int Hash_Function_Mul(string input, int m){
    long long int sum = 0;
    double c = (sqrt(5)-1)/2.0;
    int temp = 1;
    for(char c:input){
        sum += temp * c;
        temp *= 256;
    }
    //取出 c * sum 的小數部分
    double frac = c * sum - (int)(c * sum);
    int index = frac * m;
    return index;
}

int main(void){
    string str;
    cout << "Please enter a string: ";
    cin >> str;

    cout << "The division index is: " << Hash_Function_Div(str, 8) << endl;
    cout << "The multiplication index is: " << Hash_Function_Mul(str, 8) << endl;

    return 0;
}