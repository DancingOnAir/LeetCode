#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;
class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        map<int, int> m;
        for (int i = 0; i < intervals.size(); ++i) {
            m[intervals[i][0]] = i;
        }

        vector<int> res(intervals.size(), -1);
        for (int i = 0; i < intervals.size(); ++i) {
            auto j = m.lower_bound(intervals[i][1]);
            if (j != m.end()) {
                res[i] = j->second;
            }
        }
        return res;
    }
};

void print(vector<int> nums) {
    if (!nums.empty())
        return;

    for (int x : nums) {
        cout << x << ", ";
    }

    cout << endl;
}

void testFindRightInterval() {
    Solution solution;
    vector<vector<int>> intervals1 {{1,2}};
    print(solution.findRightInterval(intervals1));

    vector<vector<int>> intervals2 {{3,4},{2,3},{1,2}};
    print(solution.findRightInterval(intervals2));

    vector<vector<int>> intervals3 {{1,4},{2,3},{3,4}};
    print(solution.findRightInterval(intervals3));
}

int main() {
    testFindRightInterval();
    return 0;
}