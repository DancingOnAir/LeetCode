#include <iostream>
#include <unordered_set>

using namespace std;

// for prime numbers between 0-32, contain: 2, 3, 5, 7, 11, 13, 17, 19, 23, 29
class Solution {
public:
    int countPrimeSetBits(int L, int R) {
        int res = 0;
        while (L <= R) {
            res += (0b100000100010100010100010101100 >> __builtin_popcount(L++)) & 1;
        }

        return res;
    }

    int hammingWeight(int num) {
        num = (num & 0x55555555) + ((num >> 1) & 0x55555555);
        num = (num & 0x33333333) + ((num >> 2) & 0x33333333);
        num = (num & 0x0f0f0f0f) + ((num >> 4) & 0x0f0f0f0f);
        num = (num & 0x00ff00ff) + ((num >> 8) & 0x00ff00ff);
        num = (num & 0xffff) + ((num >> 16) & 0xffff);

        return num;
    }

    int countPrimeSetBits1(int L, int R) {
        unordered_set<int> primes {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};

        int res = 0;
        for (int i = L; i <= R; ++i) {
            if (primes.count(hammingWeight(i)))
                ++res;
        }

        return res;
    }
};

void testCountPrimeSetBits() {
    Solution solution;
    cout << solution.countPrimeSetBits(6, 10) << endl;
    cout << solution.countPrimeSetBits(10, 15) << endl;
}

int main() {
    testCountPrimeSetBits();

    return 0;
}