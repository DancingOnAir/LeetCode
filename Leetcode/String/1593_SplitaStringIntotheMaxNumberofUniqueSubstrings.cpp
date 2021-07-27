#include <string>
#include <unordered_set>

using namespace std;
class Solution {
private:
    void backtrack(int idx, int split, int& maxSplit, string& s, unordered_set<string>& seen) {
        if (idx >= s.size()) {
            maxSplit = max(maxSplit, split);
        }
        else {
            for (int i = idx; i < s.size(); ++i) {
                auto ss = s.substr(idx, i - idx + 1);
                if (!seen.count(ss)) {
                    seen.insert(ss);
                    backtrack(i + 1, split + 1, maxSplit, s, seen);
                    seen.erase(ss);
                }
            }
        }
    }

public:
    int maxUniqueSplit(string s) {
        int res = 1;
        unordered_set<string> seen;

        backtrack(0, 0, res, s, seen);
        return res;
    }
};

void testMaxUniqueSplit() {
    Solution solution;
    
    assert(solution.maxUniqueSplit("ababccc") == 5);
    assert(solution.maxUniqueSplit("aba") == 2);
    assert(solution.maxUniqueSplit("aa") == 1);
}

int main() {
    testMaxUniqueSplit();

    return 0;
}