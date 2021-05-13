#include <string>

using namespace std;

class Solution {
public:
    // sort and compare: O(nlogn)
    bool checkIfCanBreak(string s1, string s2) {
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