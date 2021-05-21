#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string sortString(string s) {
        vector<int> freq(26);
        for (char c : s) {
            ++freq[c - 'a'];
        }

        string res;
        while (res.size() != s.size()) {
            for (auto i = 0; i < 26; ++i) {
                res += string(freq[i]-- > 0 ? 1 : 0, 'a' + i);
            }

            for (auto i = 25; i >= 0; --i) {
                res += string(freq[i]-- > 0 ? 1 : 0, 'a' + i);
            }
        }

        return res;
    }
};

void testSortString() {
    Solution solution;
    assert(solution.sortString("aaaabbbbcccc") == "abccbaabccba");
    assert(solution.sortString("rat") == "art");
    assert(solution.sortString("leetcode") == "cdelotee");
    assert(solution.sortString("ggggggg") == "ggggggg");
    assert(solution.sortString("spo") == "ops");
}

int main() {
    testSortString();

    return 0;
}