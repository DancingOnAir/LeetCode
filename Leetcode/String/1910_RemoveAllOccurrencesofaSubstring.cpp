#include <string>

using namespace std;
class Solution {
public:
    string removeOccurrences(string s, string part) {
        string t = s;
        int n = s.size(), m = part.size();
        int i = 0, j = 0;
        for (i = 0, j = 0; i < n; ++i) {
            t[j++] = s[i];
            if (j >= m && t.substr(j - m, m) == part) {
                j -= m;
            }
        }
        return t.substr(0, j);
    }
};

void testRemoveOccurrences() {
    Solution solution;
    assert(solution.removeOccurrences("daabcbaabcbc", "abc") == "dab");
    assert(solution.removeOccurrences("axxxxyyyyb", "xy") == "ab");
}

int main() {
    return 0;
}