#ifndef ADT2_H_INCLUDED
#define ADT2_H_INCLUDED

#include <iostream>
#include <stdlib.h>
using namespace std;

template <typename T>
class Course{
    friend void print(Course&);
    template <typename T2> friend ostream& operator<<(ostream&, Course<T2>&);
    template <typename T2> friend istream& operator>>(istream&, Course<T2>&);

    private:
        string lecturer;
        int student_number;
        T *score;
    
    public:
        Course(string = "unknown", int = 0); //建構式
        ~Course(); //解構式
        T operator[](int); //overload

        void set_lecturer(string);
        string get_lecturer();
        void set_student_number(int);
        int get_student_number();
        void set_score_list(T*);
        T* get_score_list();
        float average();
};

template <typename T>
void Course<T>::set_lecturer(string name){
    lecturer = name;
}

template <typename T>
string Course<T>::get_lecturer(){
    return lecturer;
}

template <typename T>
void Course<T>::set_student_number(int n){
    student_number = n;
}

template <typename T>
int Course<T>::get_student_number(){
    return student_number;
}

template <typename T>
void Course<T>::set_score_list(T* p){
    score = p;
}

template <typename T>
T* Course<T>::get_score_list(){
    return score;
}

template <typename T>
float Course<T>::average(){
    T sum = 0;
    for(int i=0; i<student_number; i++){
        sum += *(score+i);
    }
    sum /= student_number;
    return sum;
}

//外部function
template <typename T>
void print(Course<T>& c){
    cout << "Lecturer:" << c.lecturer << endl;
    cout << "Student number:" << c.student_number << endl;

    for(int i=0; i<c.student_number; i++){
        cout << i+1 << "-th:" << *(c.score+i) << endl;
    }
}

//建構式
template <typename T>
Course<T>::Course(string name, int number){ //之所以不用*float是因為類別裡面的建構式會自動生成這個陣列
    lecturer = name;
    student_number = number;
    if(number!= 0){
        score = (T*) calloc(number, sizeof(T));
    }
}

//解構式
template <typename T>
Course<T>::~Course(){
    cout << "Course finished!" << endl;
    free(score);
}

//重載<<運算子 (cout)
template <typename T>
ostream& operator<<(ostream &os, Course<T> &c){
    os << "Lecturer:" << c.lecturer << endl;
    os << "Student number:" << c.student_number << endl;

    for(int i=0; i<c.student_number; i++){
        os << i+1 << "-th:" << *(c.score+i) << endl;
    }
    return os;
}

//重載>>運算子 (cin)
template <typename T>
istream& operator>>(istream &is, Course<T> &c){
    cout << "Please enter lecturer and student number:" << endl;
    is >> c.lecturer >> c.student_number;
    cout << "Please enter " << c.student_number << " scores:" << endl;
    for(int i=0; i<c.student_number; i++){
        is >> *(c.score + i);
    }
    return is;
}

//重載[]運算子
template <typename T>
T Course<T>::operator[](int index){
    return *(score + index);
}

#endif