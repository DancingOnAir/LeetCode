#include <queue>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;
class Solution {
public:
    int minDeletions(string s) {
        vector<int> freq(26);
        unordered_map<char, int> m;
        for (char c : s) {
            ++freq[c - 'a'];
        }
        // remove non-exsiting characters
        freq.erase(remove(freq.begin(), freq.end(), 0), freq.end());

        priority_queue<int> pq(freq.begin(), freq.end());
        int res = 0;
        while (pq.size() > 1) {
            auto cur = pq.top();
            pq.pop();
            if (cur != 0 and cur == pq.top()) {
                res += 1;
                if (cur - 1 != 0) {
                    pq.push(cur - 1);
                }
            }
        }

        return res;
    }
};

void testMinDeletions() {
    Solution solution;

    assert(solution.minDeletions("aab") == 0);
    assert(solution.minDeletions("aaabbbcc") == 2);
    assert(solution.minDeletions("ceabaacb") == 2);
    assert(solution.minDeletions("accdcdadddbaadbc") == 1);
}

int main() {
    testMinDeletions();

    return 0;
}