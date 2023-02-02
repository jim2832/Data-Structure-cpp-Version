#include <iostream>
#include <stack>
#include <vector>
#define ROW 10
#define COL 12
using namespace std;

/*
struct pair{
    first,
    second
};
*/

int main () {
    int MAZE[ROW][COL]={
        {1,1,1,1,1,1,1,1,1,1,1,1},
        {1,0,0,0,1,1,1,1,1,1,1,1},
        {1,1,1,0,1,1,0,0,0,0,1,1},
        {1,1,1,0,1,1,0,1,1,0,1,1},
        {1,1,1,0,1,0,0,1,1,0,1,1},
        {1,1,1,0,1,1,0,1,1,0,1,1},
        {1,1,1,0,0,0,0,1,1,0,1,1},
        {1,1,1,1,1,1,0,1,1,0,1,1},
        {1,1,0,0,0,0,0,0,1,0,0,1},
        {1,1,1,1,1,1,1,1,1,1,1,1}
    };

    //紀錄點有沒有走過
    vector< vector<bool> > visited(ROW, vector<bool>(COL, false));
    //紀錄座標
    stack< pair<int, int> > path;

    path.push(make_pair(1, 1));
    visited[1][1] = true;

    while(!path.empty()){
        pair<int, int> current = path.top();
        int x = current.first;
        int y = current.second;
        //到終點
        if(x == 8 && y == 10){
            break;
        }

        //往下走
        if(visited[x+1][y] == false && MAZE[x+1][y] == 0){
            path.push(make_pair(x+1, y));
            visited[x+1][y] = true;
        }
        //往上走
        else if(visited[x-1][y] == false && MAZE[x-1][y] == 0){
            path.push(make_pair(x-1, y));
            visited[x-1][y] = true;
        }
        //往右走
        else if(visited[x][y+1] == false && MAZE[x][y+1] == 0){
            path.push(make_pair(x, y+1));
            visited[x][y+1] = true;
        }
        //往左走
        else if(visited[x][y-1] == false && MAZE[x][y-1] == 0){
            path.push(make_pair(x, y-1));
            visited[x][y-1] = true;
        }
        //上下左右都不能走
        else{
            path.pop();
        }
    }

    while(!path.empty()){
        pair<int, int> current = path.top();
        int x = current.first;
        int y = current.second;
        MAZE[x][y] = 2;
        path.pop();
    }

    for(int i=0; i<ROW; i++){
        for(int j=0; j<COL; j++){
            cout << MAZE[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}