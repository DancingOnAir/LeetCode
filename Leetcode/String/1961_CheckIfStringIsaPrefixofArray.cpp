#include <string>
#include <vector>

using namespace std;
class Solution {
public:
    bool isPrefixString(string s, vector<string>& words) {
        int i = 0;
        for (auto& w : words) {
            if (s.substr(i, w.size()) != w)
                return false;
            i += w.size();
            if (i == s.size())
                return true;
        }

        return false;
    }
};

void testIsPrefixString() {
    Solution solution;

    vector<string> words1{"i", "love", "leetcode", "apples"};
    assert(solution.isPrefixString("iloveleetcode",words1));

    vector<string> words2{"apples", "i", "love", "leetcode"};
    assert(!solution.isPrefixString("iloveleetcode",words2));
}

int main() {
    testIsPrefixString();

    return 0;
}