#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <numeric>

using namespace std;
class Solution {
public:
    int maximumCostSubstring(string s, string chars, vector<int>& vals) {
        vector<int> m(26);
        iota(m.begin(), m.end(), 1);

        for (int i = 0; i < chars.size(); ++i) {
            m[chars[i] - 'a'] = vals[i];
        }

        int res = 0, cur = 0;
        for (auto& ch : s) {
            cur = max(cur + m[ch - 'a'], 0);
            res = max(res, cur);
        }

        return res;
    }

    int maximumCostSubstring1(string s, string chars, vector<int>& vals) {
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
