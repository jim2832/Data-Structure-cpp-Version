#include <iostream>
#include <string>
using namespace std;

int main(void){
    int arr[2][3] = {1, 2, 3, 4, 5, 6};
    int arr2[3][3] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    cout << "arr = " << arr << endl;

    for(int i=0; i<2; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    for(int i=0; i<2; i++){
        for(int j=0; j<3; j++){
            cout << &arr[i][j] << " content: " << *(*(arr + i)+j) << " ";
        }
        cout << endl;
    }

    int *p = (int*)arr2;
    for(int i=0; i<9; i++){
        cout << *(p+i) << " ";
    }

    return 0;
}