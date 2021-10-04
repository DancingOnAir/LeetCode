#include <string>
#include <vector>

using namespace std;
class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        vector<int> res(seq.size());
        for (int i = 0; i < seq.size(); ++i) {
            res[i] = (i & 1) ^ (seq[i] == '(');
        }

        return res;
    }
};

void testMaxDepthAfterSplit() {
    Solution solution;
    assert(solution.maxDepthAfterSplit("(()())") == vector<int>({0,1,1,1,1,0}));
    assert(solution.maxDepthAfterSplit("()(())()") == vector<int>({0,0,0,1,1,0,1,1}));
}

int main() {
    testMaxDepthAfterSplit();

    return 0;
}