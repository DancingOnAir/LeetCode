#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        if (strs.empty())
            return 0;

        int res = 0;
        for (int i = 0; i < strs[0].size(); ++i) {
            for (int j = 0; j < strs.size() - 1; ++j) {
                if (strs[j][i] > strs[j+1][i]) {
                    ++res;
                    break;
                }
            }
        }
        
        return res;
    }
};

void testMminDeletionSize() {
    Solution solution;

    vector<string> strs1{"cba","daf","ghi"};
    assert(solution.minDeletionSize(strs1) == 1);

    vector<string> strs2{"a","b"};
    assert(solution.minDeletionSize(strs2) == 0);

    vector<string> strs3{"zyx","wvu","tsr"};
    assert(solution.minDeletionSize(strs3) == 3);
}

int main() {
    testMminDeletionSize();

    return 0;
}