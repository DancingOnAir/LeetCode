#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>


using namespace std;
class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        unordered_map<int, int> cnt;
        for (int x : nums) {
            ++cnt[((x % value) + value) % value];
        }

        int res = 0;
        while (cnt[((res % value) + value) % value] > 0) {
            cnt[((res++ % value) + value) % value]--;
        }

        return res;
    }
};

void testFindSmallestInteger() {
    Solution solution;
    vector<int> nums1 {1,-10,7,13,6,8};
    cout << solution.findSmallestInteger(nums1, 5) << endl;
    vector<int> nums2 {1,-10,7,13,6,8};
    cout << solution.findSmallestInteger(nums2, 7) << endl;
}

int main() {
    cout << "test negative mod" << endl;
    cout << "-5 mod 4 : " + to_string(-5 % 4) << endl;
    cout << "-5 mod 4 for positive result : " + to_string(((-5 % 4) + 4) % 4) << endl;

    testFindSmallestInteger();
    return 0;
}
