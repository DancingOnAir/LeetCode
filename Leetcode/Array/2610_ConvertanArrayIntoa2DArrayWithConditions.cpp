#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        int n = nums.size();
        vector<int> count(n + 10);
        vector<vector<int>> res;
        for (int x : nums) {
            if (res.size() < count[x]) {
                res.push_back({});
            }
            res[count[x]++].push_back(x);
        }

        return res;
    }
};

void testFindMatrix() {
    Solution solution;
    vector<int> nums {1,3,4,1,2,3,1};
    auto res = solution.findMatrix(nums);
    for (auto& r : res) {
        cout << "[";
        for (auto& c : r) {
            cout << c << ", ";
        }
        cout << "], ";
    }
}

int main() {
    testFindMatrix();
    return 0;
}