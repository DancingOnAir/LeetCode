#include <iostream>


class Solution {
public:
    int bitwiseComplement(int n) {
        int x = 1;
        while (n > x) {
            x = x * 2 + 1;
        }
        return x - n;
    }

    int bitwiseComplement1(int n) {
        if (!n) {
            return 1;
        }

        int sz = 0;
        int m = n;
        while (m) {
            m >>= 1;
            ++sz;
        }

        auto bitmask = (1 << sz) - 1;
        return bitmask ^ n;
    }
};

void testBitwiseComplement() {
    Solution solution;
    std::cout << solution.bitwiseComplement(5) << std::endl;
    std::cout << solution.bitwiseComplement(7) << std::endl;
    std::cout << solution.bitwiseComplement(10) << std::endl;
}

int main() {
    testBitwiseComplement();
    return 0;
}