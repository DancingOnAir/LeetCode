#include <string>

using namespace std;
class Solution {
public:
    int magicalString(int n) {
        string s = "122";
        int idx = 2;
        while (s.size() < n) {
            s += string(s[idx++] - '0', s.back() ^ 3);
        }

        return count(s.begin(), s.begin() + n, '1');
    }
};

void testMagicalString() {
    Solution solution;

    assert(solution.magicalString(6) == 3);
    assert(solution.magicalString(1) == 1);
}

int main() {
    testMagicalString();

    return 0;
}