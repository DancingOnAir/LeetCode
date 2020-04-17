#include <iostream>
#include <string>

using namespace std;

class Solution {
    
public:
    string toHex(int num) {
        if (!num)
            return "0";
        
        string res;
        const string HEX = "0123456789abcdef";
        int mask = 0b1111;

        for (int i = 0; i < sizeof(num) * 2 && num; ++i) {
            res = HEX[num & mask] + res;
            num >>= 4;
        }

        return res;
    }
};

void testToHex() {
    Solution solution;

    cout << solution.toHex(26) << endl;
    cout << solution.toHex(-1) << endl;
}

int main() {
    testToHex();

    return 0;
}