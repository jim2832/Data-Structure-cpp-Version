#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(void){
    int N, M; 
    //N:row
    //M:column
    cin >> N >> M;

    //宣告向量
    vector< vector<int> > data(N);
    for(int i=0; i<N; i++){
        data[i].resize(M);
    }
    
    //輸入
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> data[i][j];
        }
    }

    //找每列最大值
    int max_sum = 0; //總共的最大值總和
    vector<int> max_value(N);
    for(int i=0; i<N; i++){
        int max = data[i][0];
        for(int j=0; j<M; j++){
            max = max < data[i][j] ? data[i][j] : max; //if(max < data[i][j]) {max = data[i][j]}
        }
        max_sum += max;
        max_value[i] = max;
    }

    cout << max_sum << endl;

    int max_that_can_be_devided = 0;
    for(int i=0; i<N; i++){
        if(max_sum % max_value[i] == 0){
            cout << max_value[i] << " ";
            max_that_can_be_devided++;
        }
        else if(i == N-1 && max_that_can_be_devided == 0){
            cout << -1 << endl;
        }
    }
}