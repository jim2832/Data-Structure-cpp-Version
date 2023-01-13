#include <iostream>
#include <string>
using namespace std;

class rectangle{
    friend ostream& operator<<(ostream&, rectangle&); //重載cout
    friend istream& operator>>(istream&, rectangle&); //重載cin

    private:
        float width;
        float height;
};

// 重載<<運算子
ostream& operator<<(ostream& os, rectangle& r){
    os << "Width: " << r.width << endl;
    os << "Height: " << r.height << endl;
    return os; //之所以要return os的原因是可以一次輸出多個結果
}

// 重載>>運算子
istream& operator>>(istream& is, rectangle& r){
    is >> r.width >> r.height;
    return is; //之所以要return os的原因是可以一次輸出多個結果
}

int main(void){

    return 0;
}