#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(void){
    vector<int> vec;
    int input;

    while(true){
        cout << "Please enter an input number: " << endl;
        cin >> input;
        if(input == 0){
            break;
        }
        vec.push_back(input);
    }
    cout << "The vector length is: " << vec.size() << endl;

    //印出所有資料
    for(vector<int>::iterator iter=vec.begin(); iter!=vec.end(); iter++){
        cout << *iter << " ";
    }
    cout << endl;

    //二維向量
    vector< vector<int> > data1(9);
    vector<int> data2[9];

    for(int i=0; i<data1.size(); i++){
        data1[i].resize(9);
        data2[i].resize(9);
    }

    for(int i=0; i<data1.size(); i++){
        for(int j=0; j<data1[0].size(); j++){
            data1[i][j] = (i+1)*(j+1);
            cout << data1[i][j] << "\t";
        }
        cout << endl;
    }

    return 0;
}