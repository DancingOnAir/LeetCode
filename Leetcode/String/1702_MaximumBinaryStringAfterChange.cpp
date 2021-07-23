#include <string>

using namespace std;
class Solution {
public:
    string maximumBinaryString(string binary) {
        int firstZero = -1;
        int numOfZero = 0;

        for (int i = 0; i < binary.size(); ++i) {
            if (binary[i] == '0') {
                ++numOfZero;
                if (firstZero == -1)
                    firstZero = i;
            }
        }

        if (numOfZero < 2)
            return binary;
        return string(firstZero + numOfZero - 1, '1') + "0" + string(binary.size() - firstZero - numOfZero, '1');
    }
};

void testMaximumBinaryString() {
    Solution solution;

    assert(solution.maximumBinaryString("000110") == "111011");
    assert(solution.maximumBinaryString("01") == "01");
}

int main() {
    testMaximumBinaryString();

    return 0;
}