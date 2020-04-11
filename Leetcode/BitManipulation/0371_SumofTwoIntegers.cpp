#include <iostream>
using namespace std;

class Solution {
public:
    int getSum(int a, int b)
    {
        return b == 0? a : getSum(a^b, static_cast<unsigned int>(a&b) << 1);
    }

    // 0^0 = 1^1 = 0, 0^1 = 1^0 = 1
    // 0&0 = 0&1 = 1&0 = 0, 1&1 = 1
    int getSum1(int a, int b) {
        
        int carry = a & b;
        int res = a ^ b;

        while (carry)
        {
            int temp = static_cast<unsigned int>(carry) << 1;
            carry = temp & res;

            res ^= temp;
        }

        return res;
    }
};

void testGetSum() {
    Solution solution;
    cout << solution.getSum(1, 2) << endl;
    cout << solution.getSum(-2, 3) << endl;
    cout << solution.getSum(-1, 1) << endl;
}

int main() {
    testGetSum();

    return 0;
}

