#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    vector<int> leftRigthDifference(vector<int>& nums) {
        int rightSum = 0;
        for (int x : nums) {
            rightSum += x;
        }

        vector<int> res;
        int leftSum = 0;
        for (int x : nums) {
            rightSum -= x;
            res.push_back(abs(rightSum - leftSum));
            leftSum += x;
        }

        return res;
    }
};

void print(vector<int>& nums) {
    if (nums.empty())
        return;
    for (int x : nums) {
        cout << x << ", ";
    }
    cout << endl;
}

void testLeftRigthDifference() {
    Solution solution;
    vector<int> nums1 {10,4,8,3};
    auto res1 = solution.leftRigthDifference(nums1);
    print(res1);
    vector<int> nums2 {1};
    auto res2 = solution.leftRigthDifference(nums2);
    print(res2);
}

int main() {
    testLeftRigthDifference();
    return 0;
}