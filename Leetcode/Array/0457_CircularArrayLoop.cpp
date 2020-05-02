#include <iostream>
#include <vector>
#include <unordered_set>

using std::vector;
using std::unordered_set;
using std::cout;
using std::endl;

class Solution {
private:
    int len;
    inline int getNextIndex(const vector<int>& nums, int k) {
        return (nums[k] + k + len) % len;
    }

public:
    bool circularArrayLoop(vector<int>& nums) {
        len = nums.size();
        for (int& num : nums) {
            num %= len;
        }

        for (int i = 0; i < len; ++i) {
            if (!nums[i])
                continue;

            int sign = nums[i] > 0 ? 1 : -1;
            int slow = i;
            int fast = i;

            while (true) {
                fast = getNextIndex(nums, fast);
                if (sign * nums[fast] <= 0)
                    break;

                fast = getNextIndex(nums, fast);
                if (sign * nums[fast] <= 0)
                    break;

                slow = getNextIndex(nums, slow);
                if (slow == fast) {
                    return true;
                }
            }

            slow = i;
            while (slow != fast) {
                int temp = slow;
                slow = getNextIndex(nums, slow);
                nums[temp] = 0;
            }
        }

        return false;
    }

    bool circularArrayLoop1(vector<int>& nums) {
        if (nums.empty())
            return false;

        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            int idx = i;
            if (!nums[idx])
                continue;

            unordered_set<int> s;
            vector<int> v;

            while (!s.count(idx)) {
                s.emplace(idx);
                v.emplace_back(idx);

                int temp = nums[idx] % n;
                idx = (idx + temp + n) % n;
            }

            auto iter = find(v.begin(), v.end(), idx);
            if (iter == prev(v.end()))
                continue;

            bool isPositive = true;
            for (int i = iter - v.begin(); i < v.size() - 1; ++i) {
                if (nums[v[i]] * nums[v[i + 1]] < 0) {
                    isPositive = false;
                    break;
                }

            }

            if (isPositive)
                return true;
        }

        return false;
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