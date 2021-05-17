#include <string>

using namespace std;
class Solution {
public:
    // https://leetcode.com/problems/number-of-steps-to-reduce-a-number-in-binary-representation-to-one/discuss/564323/Clean-Python-3-two-pointers-O(n)O(1)
    int numSteps(string s) {
        int middleZeros = 0;
        int prevOne = 0;
        for (int i = 1; i < s.size(); ++i) {
            if (s[i] == '1') {
                middleZeros += i - prevOne - 1;
                prevOne = i;
            }
        }

        if (prevOne == 0)
            return s.size() - 1;
        return middleZeros + s.size() + 1;
    }
};

void testNumSteps() {
    Solution solution;
    assert(solution.numSteps("1101") == 6);
    assert(solution.numSteps("10") == 1);
    assert(solution.numSteps("1") == 0);
}

int main() {
    testNumSteps();

    return 0;
}