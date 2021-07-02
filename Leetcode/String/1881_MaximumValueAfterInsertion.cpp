#include <string>
#include <iostream>

using namespace std;
class Solution {
public:
    string maxValue(string n, int x) {
        for (int i = 0; i < n.size(); ++i) {
            if (n[0] == '-'? x < (n[i] - '0') : x > (n[i] - '0')) {
                return n.substr(0, i) + char('0' + x) + n.substr(i);
            }
        }

        return n + char('0' + x);
    }
};

void testMaxValue() {
    Solution solution;
    assert(solution.maxValue("99", 9) == "999");
    assert(solution.maxValue("-13", 2) == "-123");
}

int main() {
    testMaxValue();

    return 0;
}