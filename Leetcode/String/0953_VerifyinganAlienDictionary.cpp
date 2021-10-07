#include <string>
#include <vector>

using namespace std;
class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        vector<int> m(26);
        for (int i = 0; i < order.size(); ++i) {
            m[order[i] - 'a'] = i;
        }

        for (string& w : words) {
            for (char& c : w) {
                c = m[c - 'a'];
            }
        }

        return is_sorted(words.begin(), words.end());
    }
};

void testIsAlienSorted() {
    Solution solution;

    vector<string> words1{"hello","leetcode"};
    assert(solution.isAlienSorted(words1, "hlabcdefgijkmnopqrstuvwxyz"));

    vector<string> words2{"word","world","row"};
    assert(!solution.isAlienSorted(words2, "worldabcefghijkmnpqstuvxyz"));

    vector<string> words3{"apple","app"};
    assert(!solution.isAlienSorted(words3, "abcdefghijklmnopqrstuvwxyz"));
}

int main() {
    testIsAlienSorted();

    return 0;
}