#include <iostream>
#include <vector>
#include <set>

using namespace std;
class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        // 这里不能unordered_set，vector没有hash方法
        set<vector<int>> res;
        auto n = nums.size();
        for (int bitmask = 0; bitmask < (1 << n); ++bitmask) {
            vector<int> cur;
            for (int i = 0; i < n; ++i) {
                if ((bitmask >> i) & 1) {
                    cur.push_back(nums[i]);
                }
            }

            if (cur.size() > 1) {
                bool flag = true;
                for (int i = 0; i < cur.size() - 1; ++i) {
                    if (cur[i] > cur[i + 1]) {
                        flag = false;
                        break;
                    }
                }

                if (flag) {
                    res.emplace(cur);
                }
            }
        }

        return vector(res.begin(), res.end());
    }
};

void testFindSunsequences() {
    Solution solution;
    vector<int> nums1 {4,6,7,7};
    auto res1 = solution.findSubsequences(nums1);
    for (auto& r : res1) {
        cout << "[";
        for (auto x : r) {
            cout << x << ", ";
        }
        cout << "], ";
    }
    cout << endl;
}

int main() {
    testFindSunsequences();
    return 0;
}