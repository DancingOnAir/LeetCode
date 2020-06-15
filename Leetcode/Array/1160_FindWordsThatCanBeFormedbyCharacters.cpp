#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        vector<int> counts(26);
        for (char c : chars) {
            counts[c - 'a']++;
        }

        vector<int> copy(counts);
        int res = 0;
        for (string& w : words) {
            bool flag = true;
            for (char c : w) {
                if (copy[c - 'a']-- < 1) {
                    flag = false;
                    break;
                }
            }

            if (flag) {
                res += w.size();
            }

            copy = counts;
        }

        return res;
    }
};

void testCountCharacters() {
    Solution solution;

    vector<string> words1 {"cat", "bt", "hat", "tree"};
    string chars1 = "atach";
    cout << solution.countCharacters(words1, chars1) << endl;

    vector<string> words2 {"hello", "world", "leetcode"};
    string chars2 = "welldonehoneyr";
    cout << solution.countCharacters(words2, chars2) << endl;
}

int main() {
    testCountCharacters();

    return 0;
}