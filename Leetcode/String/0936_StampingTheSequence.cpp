#include <string>
#include <vector>

using namespace std;
class Solution {
public:
    vector<int> movesToStamp(string stamp, string target) {
        int sn = stamp.size();
        int tn = target.size();

        vector<int> res;
        bool matched = false;
        do {
            matched = false;
            for (int i = 0; i < tn - sn + 1; ++i) {
                bool valid = true;
                int numDot = 0;
                for (int j = 0; j < sn; ++j) {
                    if (target[i + j] == '.')
                        ++numDot;
                    if (target[i + j] != '.' && stamp[j] != target[i + j]) {
                        valid = false;
                        break;
                    }
                }

                if (valid && numDot < sn) {
                    matched = true;
                    res.emplace_back(i);
                    for (int j = 0; j < sn; ++j) {
                        target[i + j] = '.';
                    }
                }
                
            }
        }
        while (matched);

        for (char c : target) {
            if (c != '.')
                return vector<int>({});
        }

        reverse(res.begin(), res.end());
        return res;
    }
};

void testMovesToStamp() {
    Solution solution;
    assert(solution.movesToStamp("abc", "ababc") == vector<int>({0, 2}));
    assert(solution.movesToStamp("abca", "aabcaca") == vector<int>({0, 3, 1}));
}

int main() {
    testMovesToStamp();

    return 0;
}