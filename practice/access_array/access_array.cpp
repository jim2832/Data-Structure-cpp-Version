#include <iostream>
#include <string>
using namespace std;

int main(void){
    int arr[3][3][3];

    int *p = (int*)arr;

    for(int i=0; i<27; i++){
        *(p+i) = i+1;
    }

    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            for(int k=0; k<3; k++){
                cout << arr[i][j][k] << " ";
            }
        }
    }

    return 0;
}