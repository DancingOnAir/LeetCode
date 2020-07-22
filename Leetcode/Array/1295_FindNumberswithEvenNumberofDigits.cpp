#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int res = 0;
        for (int num : nums) {
            if ((to_string(num).size() & 1) == 0)
                ++res;
        }

        return res;
    }

    int getDigit(int num) {
        int res = 0;
        while (num) {
            num /= 10;
            ++res;
        }

        return res;
    }

    int findNumbers2(vector<int>& nums) {
        int res = 0;
        for (int num : nums) {
            if ((getDigit(num) & 1) == 0)
                ++res;
        }

        return res;
    }
};

void testFindNumbers() {
    Solution solution;

    vector<int> nums1 {12, 345, 2, 6, 7896};
    cout << solution.findNumbers(nums1) << endl;

    vector<int> nums2 {555, 901, 482, 1771};
    cout << solution.findNumbers(nums2) << endl;
}

int main() {
    testFindNumbers();

    return 0;
}