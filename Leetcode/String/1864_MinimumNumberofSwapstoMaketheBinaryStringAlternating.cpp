#include <string>

using namespace std;
class Solution {
public:
    int minSwaps(string s) {
        int ones = count(s.begin(), s.end(), '1');
        int zeros = s.size() - ones;
        if (abs(ones - zeros) > 1)
            return -1;

        int missOnes = 0;
        int missZeros = 0;
        for (int i = 0; i < s.size(); i += 2) {
            if (s[i] != '0')
                ++missZeros;
            if (s[i] != '1')
                ++missOnes;
        }

        return ones == zeros? min(missZeros, missOnes): ones > zeros? missOnes: missZeros;
    }
};

void testMinSwaps() {
    Solution solution;

    assert(solution.minSwaps("111000") == 1);
    assert(solution.minSwaps("010") == 0);
    assert(solution.minSwaps("1110") == -1);
}

int main() {
    testMinSwaps();

    return 0;
}