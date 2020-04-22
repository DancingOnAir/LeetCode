#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int hammingWeight(unsigned int num) {
        num = (num & 0x55555555) + ((num >> 1) & 0x55555555);
        num = (num & 0x33333333) + ((num >> 2) & 0x33333333);
        num = (num & 0x0f0f0f0f) + ((num >> 4) & 0x0f0f0f0f);
        num = (num & 0x00ff00ff) + ((num >> 8) & 0x00ff00ff);
        num = (num & 0x0000ffff) + ((num >> 16) & 0x0000ffff);

        return num;
    }

    int totalHammingDistance(vector<int>& nums) {
        int n = nums.size();
        if (n < 2)
            return 0;
        
        int res = 0;
        for (int i = 0; i < n - 1; ++i) {
            for (int j = i + 1; j < n; ++j) {
                res += hammingWeight(nums[i] ^ nums[j]);
            }
        }

        return res;
    }
};

void testTotalHammingDistance() {
    Solution solution;
    vector<int> nums {4, 14, 2};
    cout << solution.totalHammingDistance(nums) << endl;
}

int main() {
    testTotalHammingDistance();
    return 0;
}