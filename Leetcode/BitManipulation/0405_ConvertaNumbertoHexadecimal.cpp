#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
    
public:
    string toHex(int num) {
        if (!num)
            return "0";

        string res;

        const vector<char> hexes = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};
        int mask = 0b1111;

        for (int i = 0; i < sizeof(num) * 2 && num; ++i) {
            res = hexes[num & mask] + res;
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