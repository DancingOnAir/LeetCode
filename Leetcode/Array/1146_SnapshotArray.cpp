#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
using namespace std;

class SnapshotArray {
private:
    int curSnap;
    unordered_map<int, unordered_map<int, int>> snapshots;
public:
    SnapshotArray(int length): curSnap(0), snapshots({}) {

    }
    
    void set(int index, int val) {
        snapshots[index][curSnap] = val;
    }
    
    int snap() {
        return curSnap++;
    }
    
    int get(int index, int snap_id) {
        while (snap_id >= -1) {
            if (snapshots[index].count(snap_id))
                return snapshots[index][snap_id];

            --snap_id;
        }

        return 0;
    }
};

class SnapshotArray2 {
private:
    int curSnap;
    unordered_map<int, map<int, int>> snapshots;
public:
    SnapshotArray2(int length): curSnap(0) {
        for (int i = 0; i < length; ++i) {
            snapshots[i][curSnap] = 0;
        }
    }
    
    void set(int index, int val) {
        snapshots[index][curSnap] = val;
    }
    
    int snap() {
        return curSnap++;
    }
    
    int get(int index, int snap_id) {
        auto iter = snapshots[index].upper_bound(snap_id);
        return prev(iter)->second;
    }
};

class SnapshotArray1 {
private:
    int curSnap;
    vector<vector<pair<int, int>>> snapshots;
public:
    SnapshotArray1(int length): curSnap(0), snapshots(vector<vector<pair<int, int>>>(length, vector<pair<int, int>>(1, {0,0}))) {

    }
    
    void set(int index, int val) {
        if (snapshots[index].back().first == curSnap) {
            prev(snapshots[index].end())->second = val;
            return;
        }

        snapshots[index].push_back({curSnap, val});
    }
    
    int snap() {
        return curSnap++;
    }
    
    int get(int index, int snap_id) {
        auto iter = upper_bound(snapshots[index].begin(), snapshots[index].end(), pair<int, int>(snap_id, INT_MAX));
        return iter == snapshots[index].begin() ? 0: prev(iter)->second;
    }
};

void testSnapshotArray() {
    SnapshotArray snapshotArray(3);
    snapshotArray.set(0, 5);
    cout << snapshotArray.snap() << endl;
    snapshotArray.set(0, 6);
    cout << snapshotArray.get(0, 0) << endl;
}

int main() {
    testSnapshotArray();

    return 0;
}