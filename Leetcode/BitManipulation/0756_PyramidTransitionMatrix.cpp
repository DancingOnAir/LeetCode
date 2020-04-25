#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool helper(string s1, string s2, vector<string>& allowed) {
        if (s1.size() == 1)
            return true;

        if (s1.size() - s2.size() > 1) {
            bool res = false;

            for (string& s : allowed) {
                if (s1[s2.size()] == s[0] && s1[s2.size() + 1] == s[1]) {
                    res = res || helper(s1, s2 + s[2], allowed);
                }
            }
            return res;
        }else {
            return helper(s2, "", allowed);
        }
    }

    bool pyramidTransition(string bottom, vector<string>& allowed) {
        if (bottom.empty())
            return true;

        if (allowed.empty())
            return false;

        return helper(bottom, "", allowed);
    }
};

void testPyramidTransition() {
    Solution solution;

    string bottom1 = "BCD";
    vector<string> allowed1 = {"BCG", "CDE", "GEA", "FFF"};
    cout << (solution.pyramidTransition(bottom1, allowed1)? "True" : "False") << endl;

    string bottom2 = "AABA";
    vector<string> allowed2 = {"AAA", "AAB", "ABA", "ABB", "BAC"};
    cout << (solution.pyramidTransition(bottom2, allowed2)? "True" : "False") << endl;
}

int main() {
    testPyramidTransition();

    return 0;
}