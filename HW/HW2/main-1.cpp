#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <list>
#include <time.h>

using namespace std;

int main(){
    vector<int> vec{1,2,3};
    list<int> lis{1,2,3};
    clock_t s,f;

    ifstream file_1("Homework_2_1_1.txt");
    ifstream file_2("Homework_2_1_2.txt");

    list<int>::iterator iter_list;
    vector<int>::iterator iter_vec;
    int index, number;
    // A.	Insert by index
    if(file_1){
        s = clock();
        while(file_1>>index>>number){
            vec.insert(vec.begin()+index, number);
        }
        f = clock();
        cout<<"(Vector) Time consumption for insert by index: "<< (f-s)/(double)CLOCKS_PER_SEC << " seconds" <<endl;

        file_1.clear(); // clear bad state after eof
        file_1.seekg(0);
        list<int>::iterator iter;
        s = clock();
        while(file_1>>index>>number){
            iter = lis.begin();
            advance(iter, index);
            lis.insert(iter, number);
        }
        f = clock();
        cout<<"(list) Time consumption for insert by index: "<< (f-s)/(double)CLOCKS_PER_SEC << " seconds" <<endl;
    }
    else
        cout << "File not exist!" <<endl;

    // Reset vector and list
    vec = {1,2,3};
    lis = {1,2,3};

    //B.	Insert by value
    if(file_2){
        s = clock();
        while(file_2>>index>>number){
            iter_vec = find(vec.begin(), vec.end(), index);
            vec.insert(iter_vec, number);
        }
        f = clock();
        cout<<"(Vector) Time consumption for insert by value: "<< (f-s)/(double)CLOCKS_PER_SEC << " seconds" <<endl;

        file_2.clear(); // clear bad state after eof
        file_2.seekg(0);
        s = clock();
        while(file_2>>index>>number){
            iter_list = find(lis.begin(), lis.end(), index);
            lis.insert(iter_list, number);
        }
        f = clock();
        cout<<"(list) Time consumption for insert by value: "<< (f-s)/(double)CLOCKS_PER_SEC << " seconds" <<endl;
    }
    else
        cout << "File not exist!" <<endl;
    file_1.close();
    file_2.close();

    int N = 1000000;

    // Reset vector and list
    vec.clear();
    lis.clear();

    // C.	Push Front
    s = clock();
    for(int i=0;i<N;i++){
        vec.insert(vec.begin(), i);
    }
    f = clock();
    cout<<"(Vector) Time consumption for insert " << N << " integer on the front: " <<(f-s)/(double)CLOCKS_PER_SEC << " seconds" <<endl;

    s = clock();
    for(int i=0;i<N;i++){
        lis.push_front(i);
    }
    f = clock();
    cout<<"(list) Time consumption for insert " << N << " integer on the front: " <<(f-s)/(double)CLOCKS_PER_SEC << " seconds" <<endl;

    // Reset vector and list
    vec.clear();
    lis.clear();

    // D.	Push Back
    s = clock();
    for(int i=0;i<N;i++){
        vec.push_back(i);
    }
    f = clock();
    cout<<"(Vector) Time consumption for insert " << N << " integer on the end: " <<(f-s)/(double)CLOCKS_PER_SEC << " seconds" <<endl;

    s = clock();
    for(int i=0;i<N;i++){
        lis.push_back(i);
    }
    f = clock();
    cout<<"(list) Time consumption for insert " << N << " integer on the end: " <<(f-s)/(double)CLOCKS_PER_SEC << " seconds" <<endl;

    return 0;

}
