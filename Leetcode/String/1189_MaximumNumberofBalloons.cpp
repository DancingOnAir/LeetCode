#include <string>
#include <unordered_map>

using namespace std;
class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char, int> cnt;
        for (char c : text) {
            ++cnt[c];
        }
        
        return min(cnt['b'], min(cnt['a'], min(cnt['l'] / 2, min(cnt['o'] / 2, cnt['n']))));
    }
};

void testMaxNumberOfBalloons() {
    Solution solution;
    assert(solution.maxNumberOfBalloons("nlaebolko") == 1);
    assert(solution.maxNumberOfBalloons("loonbalxballpoon") == 2);
    assert(solution.maxNumberOfBalloons("leetcode") == 0);
}

int main() {
    testMaxNumberOfBalloons();

    return 0;
}