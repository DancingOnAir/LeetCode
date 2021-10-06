#include <string>
#include <unordered_map>

using namespace std;
class Solution {
private:
    int traverse(unordered_map<char, int>& m) {
        int res = 0;
        for (auto iter = m.begin(); iter != m.end(); ++iter) {
            if (iter->second > 0) {
                ++res;

                --iter->second;
                res += traverse(m);
                ++iter->second;
            }
        }
        return res;
    }
public:
    int numTilePossibilities(string tiles) {
        unordered_map<char, int> m;
        for (char c : tiles) {
            ++m[c];
        }

        return traverse(m);
    }
};

void testNumTilePossibilities() {
    Solution solution;

    assert(solution.numTilePossibilities("AAB") == 8);
    assert(solution.numTilePossibilities("AAABBC") == 188);
    assert(solution.numTilePossibilities("V") == 1);
}

int main() {
    testNumTilePossibilities();

    return 0;
}