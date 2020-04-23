#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int n = nums.size();
        if (n < 2)
            return 0;
        
        vector<int> count(32);
        for (int i = 0; i < n; ++i) {
            int j = 0;
            while (nums[i]) {
                count[j] = nums[i] & 0x1;
                nums[i] >>= 1;
                ++j;
            }
        }

        int res = 0;
        for (int x : count) {
            res += x * (n - x);
        }
        
        return res;
    }

    int totalHammingDistance1(vector<int>& nums) {   
        int n = nums.size();
        if (n < 2)
            return 0;
        
        int res = 0;
        while (true) {
            int count = 0;
            vector<int> digits(2, 0);
            for (int i = 0; i < n; ++i) {
                if (nums[i] == 0)
                    ++count;
                
                digits[nums[i] & 1]++;
                nums[i] >>= 1;
            }

            res += digits[0] * digits[1];

            if (count == n)
                return res;
        }
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