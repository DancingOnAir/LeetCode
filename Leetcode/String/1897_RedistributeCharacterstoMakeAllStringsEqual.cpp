#include <string>
#include <vector>

using namespace std;
class Solution {
public:
    bool makeEqual(vector<string>& words) {
        vector<int> cnt(26);
        for (auto& w : words) {
            for (auto& ch : w) {
                ++cnt[ch - 'a'];
            }
        }

        return all_of(cnt.begin(), cnt.end(), [&](int x) { return x % words.size() == 0; });
    }
};

void testMakeEqual() {
    Solution solution;

    vector<string> words1{"abc", "aabc", "bc"};
    assert(solution.makeEqual(words1));

    vector<string> words2{"ab", "a"};
    assert(!solution.makeEqual(words2));
}

int main() {
    testMakeEqual();

    return 0;
}