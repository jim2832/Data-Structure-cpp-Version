#include <iostream>
#include <stdlib.h>
#include "ADT2.h"
using namespace std;

int main(){
    float score[5] = {85,95,60,82,78};
    Course<float> math("LKM", 5);
    // math.set_lecturer("LKM");
    // math.set_student_number(5);
    // math.set_score_list(score);
    cin >> math;
    cout << math;

    //透過重載[]來將物件直接像存取陣列般操作
    for(int i=0; i<math.get_student_number(); i++){
        cout << math[i] << " ";
    }
    cout << endl;

    return 0;
}