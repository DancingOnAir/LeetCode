#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        int i = 0, j = 0;
        vector<vector<int>> res;
        while (i < nums1.size() || j < nums2.size()) {
            int id = min(i < nums1.size() ? nums1[i][0] : INT_MAX, j < nums2.size() ? nums2[j][0] : INT_MAX);
            res.push_back({id, 0});
            if (i < nums1.size() && nums1[i][0] == id) {
                res.back()[1] += nums1[i++][1];
            }
            if (j < nums2.size() && nums2[j][0] == id) {
                res.back()[1] += nums2[j++][1];
            }
        }

        return res;
    }
};

void print(vector<vector<int>>& matrix) {
    for (auto& r : matrix) {
        cout << "{";
        for (auto& c : r) {
            cout << c << ", ";
        }
        cout << "}, " << endl;
    }
}

void testMergeArrays() {
    Solution solution;

    vector<vector<int>> nums1{{1,2},{2,3},{4,5}};
    vector<vector<int>> nums2{{1,4},{3,2},{4,1}};
    auto res1 = solution.mergeArrays(nums1, nums2);
    print(res1);
}

int main() {
    testMergeArrays();
    return 0;
}