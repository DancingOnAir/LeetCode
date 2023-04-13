#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        unordered_map<int, long long> leftSum, rightSum, leftCount, rightCount;
        vector<long long> res(nums.size());
        for (int i = 0; i < nums.size(); ++i) {
            res[i] = leftCount[nums[i]] * i - leftSum[nums[i]];
            leftSum[nums[i]] += i;
            ++leftCount[nums[i]];
        }
        for (int i = nums.size() - 1; i >= 0; --i) {
            res[i] += rightSum[nums[i]] - rightCount[nums[i]] * i;
            rightSum[nums[i]] += i;
            ++rightCount[nums[i]];
        }
        return res;
    }
};

void print(vector<long long>& nums) {
    for (long long x : nums) {
        cout << x << ", ";
    }
    cout << endl;
}

void testDistance() {
    Solution solution;
    vector<int> nums1 {1,3,1,1,2};
    auto res1 = solution.distance(nums1);
    print(res1);
    vector<int> nums2 {0,5,3};
    auto res2 = solution.distance(nums2);
    print(res2);
}

int main() {
    testDistance();
    return 0;
}