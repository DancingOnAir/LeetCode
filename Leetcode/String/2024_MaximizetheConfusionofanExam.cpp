#include <string>
#include <unordered_map>

using namespace std;
class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int maxf = 0;
        int res = 0;
        unordered_map<char, int> m;

        for (int i = 0; i < answerKey.size(); ++i) {
            m[answerKey[i]] += 1;
            maxf = max(maxf, m[answerKey[i]]);

            if (res - maxf < k) {
                res += 1;
            }
            else {
                m[answerKey[i - res]] -= 1;
            }
        }

        return res;
    }
};

void testMaxConsecutiveAnswers() {
    Solution solution;

    assert(solution.maxConsecutiveAnswers("TTFF", 2) == 4);
    assert(solution.maxConsecutiveAnswers("TFFT", 1 ) == 3);
    assert(solution.maxConsecutiveAnswers("TTFTTFTT", 1) == 5);
}

int main() {
    testMaxConsecutiveAnswers();

    return 0;
}