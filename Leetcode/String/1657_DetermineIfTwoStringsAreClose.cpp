#include <string>
#include <vector>
#include <set>

using namespace std;
class Solution {
public:
    bool closeStrings(string word1, string word2) {
        vector<int> v1(26), v2(26);
        set<char> s1, s2;

        for (char w : word1) {
            ++v1[w - 'a'];
            s1.insert(w);
        }

        for (char w : word2) {
            ++v2[w - 'a'];
            s2.insert(w);
        }

        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());
        return s1 == s2 && v1 == v2;
    }
};

void testCloseStrings() {
    Solution solution;

    assert(solution.closeStrings("abc", "bca"));
    assert(!solution.closeStrings("a", "aa"));
    assert(solution.closeStrings("cabbba", "abbccc"));
    assert(!solution.closeStrings("cabbba", "aabbss"));
}

int main() {
    testCloseStrings();

    return 0;
}