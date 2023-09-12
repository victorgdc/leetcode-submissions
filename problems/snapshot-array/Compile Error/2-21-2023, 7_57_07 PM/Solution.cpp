// https://leetcode.com/problems/snapshot-array

class SnapshotArray {
private:
    unordered_map<int, vector<int>> map;
    unordered_map<int, int> sn_ar;
    int snap_count = 0; 

public:
    SnapshotArray(int length) {
        // :sn_ar(length)
    }
    
    void set(int index, int val) {
        sn_ar[index] = val;
    }
    
    int snap() {
        map[snap_count] = sn_ar;
        snap_count++;

        return snap_count - 1;
    }
    
    int get(int index, int snap_id) {
        return map[snap_id][index];
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */