#include <iostream>
#include <time.h>
#include <map>
#include <unordered_map>
using namespace std;

int main(){
    clock_t start, finish;

    //有序的map
    start = clock();
    map<int, int> data_map;
    for(int i=0; i<10000000; i++){
        data_map[i] = i;
    }
    finish = clock();
    cout << "Time comsumption of map: " << (finish - start)/(double)CLOCKS_PER_SEC << endl;

    //無序的map
    start = clock();
    unordered_map<int, int> data_unordered_map;
    for(int i=0; i<10000000; i++){
        data_unordered_map[i] = i;
    }
    finish = clock();
    cout << "Time comsumption of unordered_map: " << (finish - start)/(double)CLOCKS_PER_SEC << endl;

    return 0;
}