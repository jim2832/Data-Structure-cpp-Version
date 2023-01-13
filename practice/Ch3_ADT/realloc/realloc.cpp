#include <iostream>
#include <iomanip>
#include <stdlib.h>
using namespace std;

int main(void){
    int *p = (int*)malloc(1);
    *p = 100;
    int *last = p;

    for(int i=2; i<50000; i++){
        p = (int*)realloc(p, i);
        if(last != p){
            cout << setw(5) << i << "-th address" << p << endl;
            cout << *p << endl; //搬到新空間後原空間的資料還是會被保留
        }
        last = p;
    }

    return 0;
}