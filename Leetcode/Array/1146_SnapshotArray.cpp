#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class SnapshotArray {
private:
    int curSnap;
    vector<vector<pair<int, int>>> snapshots;
public:
    SnapshotArray(int length): curSnap(0), snapshots(vector<vector<pair<int, int>>>(length, vector<pair<int, int>>(1, {0,0}))) {

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