#include <iostream>
#include <string>

using namespace std;

class Person{
    private:
        string name;
        float height;
        float weight;

    public:
        void set_name(string); //設定名字
        string get_name(); //取得名字
        void set_height(float); //設定身高
        float get_height(); //取得身高
        void set_weight(float); //設定體重
        float get_weight(); //取得體重
        void print(); //印出所有資訊
};

void Person::set_name(string n){
    name = n;
}

string Person::get_name(){
    return name;
}

void Person::set_height(float n){
    height = n;
}

float Person::get_height(){
    return height;
}

void Person::set_weight(float n){
    weight = n;
}

float Person::get_weight(){
    return weight;
}

void Person::print(){
    cout << "Name: " << name << endl;
    cout << "Height: " << height << endl;
    cout << "Weight: " << weight << endl;
}

int main(){

    return 0;
}