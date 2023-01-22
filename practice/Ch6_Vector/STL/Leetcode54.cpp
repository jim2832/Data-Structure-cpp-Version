#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution{
    public:
        vector<int> spiralOrder(vector<vector<int>>& matrix){
            int row = matrix.size();
            int col = matrix[0].size();
            vector<int> result;

            int row_lower = 0;
            int row_upper = row - 1;
            int col_lower = 0;
            int col_upper = col - 1;
            // 0:up, 1:down, 2:left, 3:right
            // 3(right) -> 1(down) -> 2(left) -> 0(up) -> 3(right) -> ...
            int i = 0, j = 0;
            int direction = 3;

            while(row_upper >= row_lower && col_upper >= col_lower){
                result.push_back(matrix[i][j]);
                switch (direction){
                    //up
                    case 0:
                        if(i-1 >= row_lower){ //若往上走還沒超過row的下界
                            i--;
                        }
                        else{
                            direction = 3;
                            col_lower++;
                            j++;
                        }
                        break;

                    //down
                    case 1:
                        if(i+1 <= row_upper){
                            i++;
                        }
                        else{
                            direction = 2;
                            col_upper--;
                            j--;
                        }
                        break;

                    //left
                    case 2:
                        if(j-1 >= col_lower){
                            j--;
                        }
                        else{
                            direction = 0;
                            row_upper--;
                            i--;
                        }
                        break;

                    //right
                    case 3:
                        if(j+1 <= col_upper){
                            j++;
                        }
                        else{
                            direction = 1;
                            row_lower++;
                            i++;
                        }
                        break;
                }
            }
            return result;
        }
};