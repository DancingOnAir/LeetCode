#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for (int num : nums) {
            m[num]++;
        }

        for (int num : nums) {
            int start = num;
            while (m[start - 1])
                --start;
            
            for (; start <= num; ++start) {
                int times = m[start];
                if (times) {
                    for (int i = start; i < start + k; ++i) {
                        if (m[i] < times) {
                            return false;
                        }

                        m[i] -= times;
                    }
                }
            }
        }

        return true;
    }

    bool isPossibleDivide1(vector<int>& nums, int k) {
        int n = nums.size();
        if (n % k != 0) {
            return false;
        }

        map<int, int> counts;
        for (int num : nums) {
            counts[num]++;
        }

        for (auto& iter : counts) {
            if (counts[iter.first] > 0) {
                for (int i = k - 1; i >= 0; --i) {
                    if ((counts[iter.first + i] -= counts[iter.first]) < 0)
                        return false;
                }
            }
        }

        return true;
    }
};

void testIsPossibleDivide() {
    Solution solution;

    vector<int> nums1 {1, 2, 3, 3, 4, 4, 5, 6};
    int k1 = 4;
    cout << (solution.isPossibleDivide(nums1, k1) ? "True" : "False") << endl;

    vector<int> nums2 {3, 2, 1, 2, 3, 4, 3, 4, 5, 9, 10, 11};
    int k2 = 3;
    cout << (solution.isPossibleDivide(nums2, k2) ? "True" : "False") << endl;

    vector<int> nums3 {3, 3, 2, 2, 1, 1};
    int k3 = 3;
    cout << (solution.isPossibleDivide(nums3, k3) ? "True" : "False") << endl;

    vector<int> nums4 {1, 2, 3, 4};
    int k4 = 3;
    cout << (solution.isPossibleDivide(nums4, k4) ? "True" : "False") << endl;
}

int main() {
    testIsPossibleDivide();

    return 0;
}