#include <vector>
#include <iostream>


using namespace std;
class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int left = 1, right = 1000000;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            long long total = 0;
            for (int x : nums) {
                total += (long long)(x - 1 + mid ) / mid;
            }

            if (total > threshold) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }

        return left;
    }
};

void testSmallestDivisor() {
    Solution solution;
    vector<int> nums1 {1,2,5,9};
    cout << solution.smallestDivisor(nums1, 6) << endl;
    vector<int> nums2 {44,22,33,11,1};
    cout << solution.smallestDivisor(nums2, 5) << endl;
}

int main() {
    testSmallestDivisor();
    return 0;
}
