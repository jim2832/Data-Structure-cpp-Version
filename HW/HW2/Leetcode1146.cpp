#include <iostream>
#include <vector>
#include <string>
#include <list>
using namespace std;

class SnapshotArray {
    public:
        vector<vector<pair<int, int>>> arr;
        int snap_index;
        SnapshotArray(int length) {
            arr.resize(length);
            snap_index = 0;
        }
        
        void set(int index, int val) {
            if (arr[index].empty() || arr[index].back().first < snap_index)
                arr[index].emplace_back(snap_index, val);
            else
                arr[index].back().second = val;
        }
        
        int snap() {
            return snap_index++;
        }
        
        int get(int index, int snap_id) {
            auto it = upper_bound(arr[index].begin(), arr[index].end(), make_pair(snap_id, INT_MAX));
            if (it == arr[index].begin())  // no data at snap_id
                return 0;
            else    // return the data with snap_index <= snap_id, which is the prev of upper_bound
                return prev(it)->second;
        }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */