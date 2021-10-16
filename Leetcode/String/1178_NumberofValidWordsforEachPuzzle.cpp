#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;
class Solution {
public:
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        unordered_map<int, int> m;
        for (string& w : words) {
            unordered_set<char> s(w.begin(), w.end());
            if (s.size() > 7) {
                continue;
            }

            int cur = 0;
            for (char c : w) {
                cur |= 1 << (c - 'a');
            }

            ++m[cur];
        }

        vector<int> res;
        for (string& p : puzzles) {
            vector<int> bfs = {1 << (p[0] - 'a')};
            for (char c : p.substr(1)) {
                for (int b : bfs) {
                    bfs.push_back(b | (1 << (c - 'a')));
                }
            }

            int cur = 0;
            for (int b : bfs) {
                cur += m[b];
            }
            res.push_back(cur);
        }

        return res;
    }
};

void testFindNumOfValidWords() {
    Solution solution;

    vector<string> words1 = {"aaaa","asas","able","ability","actt","actor","access"};
    vector<string> puzzles1 = {"aboveyz","abrodyz","abslute","absoryz","actresz","gaswxyz"};
    vector<int> res1 = {1,1,3,2,4,0};
    assert(solution.findNumOfValidWords(words1, puzzles1) == res1);

    vector<string> words2 = {"aaaa","asas","able","ability","actt","actor","access"};
    vector<string> puzzles2 = {"aboveyz","abrodyz","abslute","absoryz","actresz","gaswxyz"};
    vector<int> res2 = {1,1,3,2,4,0};
    assert(solution.findNumOfValidWords(words2, puzzles2) == res2);
}

int main() {
    testFindNumOfValidWords();

    return 0;
}