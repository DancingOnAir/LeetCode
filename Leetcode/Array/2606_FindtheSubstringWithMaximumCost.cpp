#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;
class Solution {
public:
    int maximumCostSubstring(string s, string chars, vector<int>& vals) {
        unordered_map<char, int> m;
        for (int i = 0; i < chars.size(); ++i) {
            m[chars[i]] = vals[i];
        }

        for (int i = 1; i <= 26; ++i) {
            char c = 'a' + i - 1;
            if (!m.count(c)) {
                m[c] = i;
            }
        }

        int res = 0, cur = 0;
        for (const char& c : s) {
            cur += m[c];
            if (cur < 0) {
                cur = 0;
            }

            res = max(res, cur);
        }

        return res;
    }
};

void testMaximumCostSubstring() {
    Solution solution;
    vector<int> vals1 {-1000};
    cout << solution.maximumCostSubstring("adaa", "d", vals1) << endl;
    vector<int> vals2 {-1, -1, -1};
    cout << solution.maximumCostSubstring("abc", "abc", vals2) << endl;
}

int main() {
    testMaximumCostSubstring();
    return 0;
}
