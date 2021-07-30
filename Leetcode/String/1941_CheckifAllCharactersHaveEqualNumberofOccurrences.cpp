#include <string>
#include <unordered_map>
#include <algorithm>
#include <vector>

using namespace std;
class Solution {
public:
    // bool areOccurrencesEqual(string s) {
    //     unordered_map<char, int> m;
    //     for (auto c : s) {
    //         ++m[c];
    //     }
    //     int average = s.size() / m.size();
    //     return all_of(m.begin(), m.end(), [&average](auto t) { return t->second == average; });
    // }

    bool areOccurrencesEqual(string s) {
        vector<int> cnt(26);
        int mx = 0;
        for (auto c : s) {
            mx = max(mx, ++cnt[c - 'a']);
        }

        return all_of(cnt.begin(), cnt.end(), [&mx](int t) { return t == 0 || t == mx; });
    }
};

void testAreOccurrencesEqual() {
    Solution solution;
    assert(solution.areOccurrencesEqual("abacbc"));
    assert(!solution.areOccurrencesEqual("aaabb"));
}

int main() {
    testAreOccurrencesEqual();

    return 0;
}