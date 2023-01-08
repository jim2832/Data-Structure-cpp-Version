#ifndef ADT_H_INCLUDED
#define ADT_H_INCLUDED

#include <iostream>
using namespace std;

template <typename T>
class Person{
    //friend function
    friend void print(Person&);
    template <typename T2> friend ostream& operator<<(ostream&, Person<T2>&);
    template <typename T2> friend istream& operator>>(istream&, Person<T2>&);

    rivate:
        string name;
        T height;
        T weight;

    public:
        Person(string = "anonymous", T = 0, T = 0); //建構式
        ~Person(); //解構式
        T operator+(Person &p);

        void set_name(string); 
        string get_name();
        void set_height(T);
        T get_height();
        void set_weight(T);
        T get_weight();
        void print();
};


template <typename T>
void Person<T>::set_name(string n){
    name = n;
}

template <typename T>
string Person<T>::get_name(){
    return name;
}

template <typename T>
void Person<T>::set_height(T n){
    height = n;
}

template <typename T>
T Person<T>::get_height(){
    return height;
}

template <typename T>
void Person<T>::set_weight(T n){
    weight = n;
}

template <typename T>
T Person<T>::get_weight(){
    return weight;
}

//class內部function
template <typename T>
void Person<T>::print(){
    cout << "Name: " << name << endl;
    cout << "Height: " << height << endl;
    cout << "Weight: " << weight << endl;
}

//外部function
template <typename T>
void print(Person<T>& p){
    cout << "Name: " << p.name << endl;
    cout << "Height: " << p.height << endl;
    cout << "Weight: " << p.weight << endl;
}

//建構式
template <typename T>
Person<T>::Person(string n, T h, T w){
    name = n;
    height = h;
    weight = w;
}

//解構式
template <typename T>
Person<T>::~Person(){
    cout << "Object was destructed!" << endl;
}

//重載<<運算子 (cout)
template <typename T>
ostream& operator<<(ostream &os, Person<T> &p){
    os << "Name: " << p.name << endl;
    os << "Height: " << p.height << endl;
    os << "Weight: " << p.weight << endl;
    return os;
}

//重載>>運算子 (cin)
template <typename T>
istream& operator>>(istream &is, Person<T> &p){
    is >> p.name >> p.height >> p.weight;
    return is;
}

//重載+運算子
template <typename T>
T Person<T>::operator+(Person<T> &p){
    return weight + p.weight;
}

#endif