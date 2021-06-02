#include <string>
#include <vector>
#include <set>

using namespace std;
class Solution {
public:
    int countGoodSubstrings(string s) {
        vector<int> cnt(26);
        int res = 0;
        int repeat = 0;
        for (auto i = 0; i < s.size(); ++i) {
            if (cnt[s[i] - 'a']++ == 1)
                ++repeat;
            
            if (i >= 3) {
                if (cnt[s[i - 3] - 'a']-- == 2)
                    --repeat;
            }

            if (i >= 2 && repeat == 0)
                ++res;
        }

        return res;
    }
};

void testCountGoodSubstrings() {
    Solution solution;

    assert(solution.countGoodSubstrings("xyzzaz") == 1);
    assert(solution.countGoodSubstrings("aababcabc") == 4);
}

int main() {
    testCountGoodSubstrings();

    return 0;
}