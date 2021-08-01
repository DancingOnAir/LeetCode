#include <string>
#include <vector>
#include <algorithm>

using namespace std;
class Solution {
public:
    vector<int> diStringMatch(string s) {
        int left = count(s.begin(), s.end(), 'D');
        int right = left;
        vector<int> res {left};
        for (char& c : s) {
            res.push_back(c == 'I'? ++right: --left);
        }

        return res;
    }

    vector<int> diStringMatch1(string s) {
        vector<int> res;
        for (int lo = 0, hi = s.size(), i = 0; i <= s.size(); ++i) {
            res.push_back(i == s.size() || s[i] == 'I' ? lo++ : hi--);
        }
        return res;
    }
};

void testDiStringMatch() {
    Solution solution;

    vector<int> res1 {0,4,1,3,2};
    assert(solution.diStringMatch("IDID") == res1);

    vector<int> res2 {0,1,2,3};
    assert(solution.diStringMatch("III") == res2);

    vector<int> res3 {3,2,0,1};
    assert(solution.diStringMatch("DDI") == res3);
}

int main() {
    testDiStringMatch();

    return 0;
}