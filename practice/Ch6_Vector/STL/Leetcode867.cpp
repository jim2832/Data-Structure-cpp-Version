#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution{
    public:
        vector<vector<int>> tranpose(vector<vector<int>>& matrix){
            int row = matrix.size();
            int column = matrix[0].size();
            vector<vector<int>> result(column, vector<int>(row)); //存結果

            for(int i=0; i<row; i++){
                for(int j=0; j<column; j++){
                    result[i][j] = matrix[j][i];
                }
            }
            return result;
        }
            
};