#include <string>
#include <unordered_set>

using namespace std;
class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int res = 0;
        for (char c = 'a'; c <= 'z'; ++c) {
            int i = s.find(c);
            int j = s.rfind(c);

            if (i != string::npos && i + 1 < j) {
                res += unordered_set<char>(s.begin() + i + 1, s.begin() + j).size();
            }
        }

        return res;
    }
};

void testCountPalindromicSubsequence() {
    Solution solution;

    assert(solution.countPalindromicSubsequence("aabca") == 3);
    assert(solution.countPalindromicSubsequence("adc") == 0);
    assert(solution.countPalindromicSubsequence("bbcbaba") == 4);
}

int main() {
    testCountPalindromicSubsequence();

    return 0;
}