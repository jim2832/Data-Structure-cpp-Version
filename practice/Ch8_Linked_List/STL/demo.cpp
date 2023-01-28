#include <iostream>
#include <list>
using namespace std;

int main(void){
    list<int> data;
    int value;

    do{
        cout << "Please enter a value: ";
        cin >> value;
        if(value != 0){
            data.push_back(value);
        }
    }while(value);

    for(auto iter=data.begin(); iter!=data.end(); iter++){
        cout << *iter << " ";
    }

    return 0;
}