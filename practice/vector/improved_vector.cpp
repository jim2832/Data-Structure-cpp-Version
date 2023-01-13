#include <iostream>
#include <string>
#include "improved_vector.h"
#include "time.h"
using namespace std;

int main(void){
    clock_t start, finish;
    Vector<int> v;

    start = clock();
    for(int i=0; i<10000; i++){
        v.Push_Back(i);
    }
    finish = clock();
    cout << "Time: " << (finish - start)/(double) (CLOCKS_PER_SEC) << " s." << endl;

    return 0;
}