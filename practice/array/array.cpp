#include <iostream>
#include <string>
using namespace std;

int main(void){
    bool bool_arr[5] = {0, 0, 1, 0, 1};
    int int_arr[5] = {4, 1, 71, 12, 51};
    char char_arr[5] = {'1', '2', '3', '4', '5'};

    int arr[2][3] = {1, 2, 3, 4, 5, 6};

    for(int i=0; i<sizeof(bool_arr)/sizeof(bool); i++){
        cout << &bool_arr[i] << " "; //印出來的記憶體位址是會連續的
    }

    cout << endl;

    for(int i=0; i<sizeof(int_arr)/sizeof(int); i++){
        cout << &int_arr[i] << " "; //印出來的記憶體位址會間隔4個位址
    }

    cout << endl;

    for(int i=0; i<sizeof(char_arr)/sizeof(char); i++){
        cout << &char_arr[i] << " "; //印出來會是 12345 2345 345 45 5(非記憶體位址)
    }

    cout << endl;

    for(int i=0; i<sizeof(char_arr)/sizeof(char); i++){
        cout << (void*) &char_arr[i] << " ";
    }

    cout << endl;
    
    //在多為陣列中記憶體位址也是連續的
    for(int i=0; i<2; i++){
        for(int j=0; j<3; j++){
            cout << &arr[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}