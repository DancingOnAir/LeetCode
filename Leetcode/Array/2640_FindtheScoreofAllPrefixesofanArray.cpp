#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    vector<long long> findPrefixScore(vector<int>& nums) {
        vector<long long> res;
        long long preSum = 0;
        int mx = 0;
        for (int x : nums) {
            mx = max(mx, x);
            preSum += mx + x;
            res.push_back(preSum);
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

void testFindPrefixScore() {
    Solution solution;
    vector<int> nums1 {2,3,7,5,10};
    auto res1 = solution.findPrefixScore(nums1);
    print(res1);
    vector<int> nums2 {1,1,2,4,8,16};
    auto res2 = solution.findPrefixScore(nums2);
    print(res2);
}

int main() {
    testFindPrefixScore();
    return 0;
}