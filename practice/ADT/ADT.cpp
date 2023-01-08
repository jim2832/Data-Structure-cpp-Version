#include <iostream>
#include "ADT.h"

using namespace std;

int main(){
    Person<int> p1("Jim", 169, 59);
    Person<int> p2("Mick",168,60);
    // p.set_name("LKM");
    // p.set_height(168);
    // p.set_weight(60);

    // p.print();
    // print(p1);
    // print(p2);
    cin >> p1;
    cout << p1;
    // cout << "total weight is: " << p1 + p2 << endl;

    return 0;
}