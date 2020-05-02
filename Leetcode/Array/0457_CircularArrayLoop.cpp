#include <iostream>
#include <vector>
#include <unordered_set>

using std::vector;
using std::unordered_set;
using std::cout;
using std::endl;

class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
        if (nums.empty())
            return false;

        int n = nums.size();
        unordered_set<int> s;
        vector<int> v;
        int idx = 0;

        while (!s.count(idx)) {
            if (!nums[idx])
                return false;

            s.emplace(idx);
            v.emplace_back(idx);

            int temp = nums[idx] % n;
            idx = (idx + temp + n) % n;
        }

        auto iter = find(v.begin(), v.end(), idx);
        if (iter == prev(v.end()))
            return false;

        for (int i = iter - v.begin(); i < v.size() - 1; ++i) {
            if (nums[v[i]] * nums[v[i + 1]] < 0)
                return false;
        }

        return true;
    }
};

void testCircularArrayLoop() {
    Solution solution;
    
    vector<int> nums1 {2, -1, 1, 2, 2};
    cout << (solution.circularArrayLoop(nums1) ? "True" : "False") << endl;

    vector<int> nums2 {-1, 2};
    cout << (solution.circularArrayLoop(nums2) ? "True" : "False") << endl;

    vector<int> nums3 {-2, 1, -1, -2, -2};
    cout << (solution.circularArrayLoop(nums3) ? "True" : "False") << endl;
}

int main() {
    testCircularArrayLoop();

    return 0;
}