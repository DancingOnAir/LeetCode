#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    // use vector to count characters
    bool checkIfCanBreak(string s1, string s2) {
        vector<int> v(26);
        for (int i = 0; i < s1.size(); ++i) {
            ++v[s1[i] - 'a'];
            --v[s2[i] - 'a'];
        }

        bool flag1 = true, flag2 = true;
        int total = 0;
        for (int val : v) {
            total += val;
            if (total < 0)
                flag1 = false;
            if (total > 0)
                flag2 = false;

            if (!flag1 && !flag2)
                return false;
        }

        return true;
    }

    // sort and compare: O(nlogn)
    bool checkIfCanBreak1(string s1, string s2) {
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());

        bool flag1 = true, flag2 = true;
        for(int i = 0; i < s1.size(); ++i) {
            if (s1[i] > s2[i]) {
                flag1 = false;
            }
            if (s1[i] < s2[i]) {
                flag2 = false;
            }
        }

        if (flag1 || flag2)
            return true;
        
        return false;
    }
};

void testCheckIfCanBreak() {
    Solution solution;
    assert(solution.checkIfCanBreak("abc", "xya"));
    assert(!solution.checkIfCanBreak("abe", "acd"));
    assert(solution.checkIfCanBreak("leetcodee", "interview"));
}

int main() {
    testCheckIfCanBreak();

    return 0;
}