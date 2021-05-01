#include <unordered_set>
#include <string>
#include <deque>

using namespace std;

class Solution {
public:
    // sliding window
    bool hasAllCodes(string s, int k) {
        unordered_set<string> seen;
        deque<char> q;

        for (char c : s) {
            q.push_back(c);
            if (q.size() == k) {
                seen.insert({q.begin(), q.end()});
                q.pop_front();
            }
        }

        return seen.size() == pow(2, k);
    }

    bool hasAllCodes1(string s, int k) {
        unordered_set<string> seen;
        for (int i = 0; i + k <= s.size(); ++i) {
            seen.insert(s.substr(i, k));
        }
        return seen.size() == pow(2, k);
    }
};

void testHasAllCodes() {
    Solution solution;

    // assert(solution.hasAllCodes("00110110", 2));
    // assert(solution.hasAllCodes("00110", 2));
    // assert(solution.hasAllCodes("0110", 1));
    // assert(!solution.hasAllCodes("0110", 2));
    assert(!solution.hasAllCodes("0000000001011100", 4));
}

int main() {
    testHasAllCodes();

    return 0;
}