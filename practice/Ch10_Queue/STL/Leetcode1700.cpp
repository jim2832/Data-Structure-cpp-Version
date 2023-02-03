#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

class Solution{
    public:
        int countStudents(vector<int>& students, vector<int>& sandwiches){
            queue<int> Queue;

            //存每個學生要吃的口味
            for(int n:students){
                Queue.push(n);
            }

            for(int i=0; i<sandwiches.size(); i++){
                int favor = sandwiches[i];
                int len = Queue.size();
                int count = 0;
                while(true){
                    if(favor == Queue.front()){
                        Queue.pop();
                        break;
                    }
                    else{
                        Queue.push(Queue.front());
                        Queue.pop();
                        count++;
                        if(count == len){
                            return count;
                        }
                    }
                }
            }
            return 0;
        }
};