#include <iostream>
using namespace std;

class Solution {
public:
    bool isPowerOfFour(int num) {
        if (num <= 0)
            return false;

        while ((num & 0x3) == 0)
        {
            num >>= 2;
        }

        return num == 1;
    }
};

void testIsPowerOfFour()
{
    Solution solution;
    cout << (solution.isPowerOfFour(64)? "True" : "False") << endl;
    cout << (solution.isPowerOfFour(16)? "True" : "False") << endl;
    cout << (solution.isPowerOfFour(5)? "True" : "False") << endl;
    cout << (solution.isPowerOfFour(6)? "True" : "False") << endl;
    cout << (solution.isPowerOfFour(8)? "True" : "False") << endl;
    cout << (solution.isPowerOfFour(-2147483648)? "True" : "False") << endl;
}

int main()
{
    testIsPowerOfFour();

    return 0;
}