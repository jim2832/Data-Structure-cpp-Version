#include <iostream>
#include <string>
#include "iterator.h"
using namespace std;

int main(void){
    Vector<int> v;

    v.Push_Back(1);
    v.Push_Back(2);
    v.Push_Back(3);
    v.Push_Back(4);
    v.Push_Back(5);
    

    Vector<int>::Iterator iter(&v[0]);
    for(int i=0; i<5; i++){
        cout << *iter << " ";
        iter++;
    }
    cout << endl;


    Vector<int>::Iterator iter2 = iter;
    if(iter == iter2){
        cout << "The same" << endl;
    }
    else{
        cout << "Different" << endl;
    }

    return 0;
}