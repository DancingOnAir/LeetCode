#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
class Solution {
public:
    bool primeSubOperation(vector<int>& nums) {
        vector<int> primes{0};
        vector<bool> isPrime(1000, false);
        for (int i = 2; i < 1000; ++i) {
            if (!isPrime[i]) {
                primes.push_back(i);
                for (int j = i; j < 1000 / i; ++j) {
                    isPrime[i * j] = true;
                }
            }
        }

        int pre = 0;
        for (int x : nums) {
            if (x <= pre)
                return false;
            pre = x - *--lower_bound(primes.begin(), primes.end(), x - pre);
        }

        return true;
    }
};

void testPrimeSubOperation() {
    Solution solution;
    vector<int> nums1{4,9,6,10};
    cout << (solution.primeSubOperation(nums1) ? "true" : "false") << endl;
    vector<int> nums2{6,8,11,12};
    cout << (solution.primeSubOperation(nums2) ? "true" : "false") << endl;
    vector<int> nums3{5,8,3};
    cout << (solution.primeSubOperation(nums3) ? "true" : "false") << endl;
}

int main() {
    testPrimeSubOperation();
    return 0;
}