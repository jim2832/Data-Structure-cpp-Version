#include <iostream>
#include "template.h"

using namespace std;

template <typename T>
void Function(T *p, int len){
    for(int i=0; i<len; i++){
        cout << *(p+i) << " ";
    }
    cout << endl;
}

int main(void){
    int arr1[3] = {1, 7, 9};
    float arr2[3] = {1.0, 7.0, 9.0};
    double arr3[3] = {1.0, 7.0, 9.0};

    Function(arr1, 3);
    Function(arr2, 3);
    Function(arr3, 3);

    return 0;
}