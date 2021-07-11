#include <string>
#include <unordered_map>
#include <vector>


using namespace std;
class Solution {
public:
    // https://leetcode-cn.com/problems/number-of-wonderful-substrings/solution/qian-zhui-he-chang-jian-ji-qiao-by-endle-t57t/
    long long wonderfulSubstrings(string word) {
        vector<int> count(1024);
        count[0] = 1;
        int res = 0, cur = 0;

        for (char w : word) {
            cur ^= 1 << (w - 'a');
            res += count[cur];

            for (int i = 0; i < 10; ++i) {
                res += count[cur ^ (1 << i)];
            }
            ++count[cur];
        }
        return res;
    }
};

void testWonderfulSubstrings() {
    Solution solution;

    assert(solution.wonderfulSubstrings("aba") == 4);
    assert(solution.wonderfulSubstrings("aabb") == 9);
    assert(solution.wonderfulSubstrings("he") == 2);
}

int main() {
    testWonderfulSubstrings();

    return 0;
}