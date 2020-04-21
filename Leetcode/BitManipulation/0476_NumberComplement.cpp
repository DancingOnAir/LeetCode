#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    int findComplement(int num) {
        // The left shift and right shift operators should not be used for negative numbers. 
        // The result of is undefined behaviour if any of the operands is a negative number.
        unsigned int mask = ~0;
        while (num & mask) {
            mask <<= 1;
        }

        return num ^ ~mask;
    }

    int findComplement1(int num) {

        int count = 0, mask = 0;
        int reverse = ~num;
        while (num) {
            mask <<= 1;
            num >>= 1;

            ++mask;
            ++count;
        }

        return (reverse & mask);
    }
};

void testFindComplement() {
    Solution solution;

    cout << solution.findComplement(5) << endl;
    cout << solution.findComplement(1) << endl;
}

int main() {
    testFindComplement();
    return 0;
}