#include <string>
#include <vector>


using namespace std;
class Solution {
public:
    // two pointers
    string removeDuplicates(string s, int k) {
        int i = 0;
        int n = s.size();
        vector<int> cnt(n);

        for (int j = 0; j < n; ++i, ++j) {
            s[i] = s[j];
            cnt[i] = i > 0 && s[i - 1] == s[i] ? cnt[i - 1] + 1 : 1;
            if (cnt[i] == k)
                i -= k;
        }

        return s.substr(0, i);
    }
};

void testRemoveDuplicates() {
    Solution solution;

    assert(solution.removeDuplicates("abcd", 2) == "abcd");
    assert(solution.removeDuplicates("deeedbbcccbdaa", 3) == "aa");
    assert(solution.removeDuplicates("pbbcggttciiippooaais", 2) == "ps");
}

int main() {
    testRemoveDuplicates();

    return 0;
}