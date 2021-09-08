#include <string>
#include <queue>

using namespace std;
class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int, char>> pq;
        pq.push(make_pair(a, 'a'));
        pq.push(make_pair(b, 'b'));
        pq.push(make_pair(c, 'c'));

        string res;
        while (!pq.empty()) {
            auto p1 = pq.top();
            pq.pop();
            int first = p1.first, char1 = p1.second;

            if (res.size() > 1 && char1 == res.back() && res.back() == res[res.size() - 2]) {
                if (pq.empty())
                    break;

                auto p2 = pq.top();
                pq.pop();
                int second = p2.first, char2 = p2.second;

                res.push_back(char2);
                --second;

                if (second != 0)
                    pq.push(make_pair(second, char2));
                pq.push(make_pair(first, char1));
                continue;
            }

            res.push_back(char1);
            --first;
            pq.push(make_pair(first, char1));
        }

        return res;
    }

    string longestDiverseString1(int a, int b, int c, char aa = 'a', char bb = 'b', char cc = 'c') {
        if (a < b)
            return longestDiverseString1(b, a, c, bb, aa, cc);
        if (b < c)
            return longestDiverseString1(a, c, b, aa, cc, bb);

        if (0 == b)
            return string(min(2, a), aa);
        int useA = min(2, a), useB = a - useA >= b ? 1 : 0;
        return string(useA, aa) + string(useB, bb) + longestDiverseString1(a - useA, b - useB, c, aa, bb, cc);
    }
};

void testLongestDiverseString() {
    Solution solution;

    assert(solution.longestDiverseString(1, 1, 7) == "ccaccbcc");
    assert(solution.longestDiverseString(2, 2, 1) == "aabbc");
    assert(solution.longestDiverseString(7, 1, 0) == "aabaa");
}

int main() {
    testLongestDiverseString();

    return 0;
}