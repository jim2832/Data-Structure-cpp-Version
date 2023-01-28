#include <iostream>
#include <list>
using namespace std;

void print_list(list<int> List){
    for(auto iter=List.begin(); iter!=List.end(); iter++){
        cout << *iter << " ";
    }
    cout << endl;
}

int main(void){
    list<int> List;
    List.assign(3, 0); // 0 0 0
    List.push_back(1); // 0 0 0 1 
    List.push_back(2); // 0 0 0 1 2
    List.push_back(3); // 0 0 0 1 2 3
    print_list(List);

    cout << "Front: " << List.front() << endl;
    cout << "Back: " << List.back() << endl;
    List.pop_front(); // 0 0 1 2 3
    List.pop_back(); //0 0 1 2

    auto iter = List.begin();
    advance(iter, 2); // iter -> 1
    List.insert(iter, 4); // 0 0 4 1 2, iter -> 1
    advance(iter, 1); // iter -> 2
    List.erase(iter); // 0 0 4 1
    print_list(List);

    List.sort(); // 0 0 1 4
    cout << "Sort: ";
    print_list(List);

    List.reverse(); // 4 1 0 0
    cout << "Reverse: ";
    print_list(List);

    return 0;
}