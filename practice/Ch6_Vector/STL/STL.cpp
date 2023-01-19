#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(void){
    vector<int> vec(3);
    vector<int>::iterator it;
    fill(vec.begin(), vec.end(), 5);

    for(int i=0; i<vec.size(); i++){
        cout << vec[i] << " ";
    }
    cout << endl;

    for(auto iter=vec.begin(); iter!=vec.end(); iter++){
        cout << *iter << " ";
    }
    cout << endl;

    return 0;
}