#include <string>
#include <bitset>

using namespace std;
class Solution {
public:
    bool canConstruct(string s, int k) {
        bitset<26> odd;
        for (char c : s) {
            odd.flip(c - 'a');
        }

        return odd.count() <= k && k <= s.size();
    }
};

void testCanConstruct() {
    Solution solution;

    assert(solution.canConstruct("annabelle", 2));
    assert(!solution.canConstruct("leetcode", 3));
    assert(solution.canConstruct("true", 4));
    assert(solution.canConstruct("yzyzyzyzyzyzyzy", 2));
    assert(!solution.canConstruct("cr", 7));
}

int main() {
    testCanConstruct();

    return 0;
}