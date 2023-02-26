#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    int maxJump(vector<int>& stones) {
        int res = stones[1] - stones[0];
        for (int i = 2; i < stones.size(); ++i) {
            res = max(res, stones[i] - stones[i - 2]);
        }
        return res;
    }
};

void testMaxJump() {
    Solution solution;

    vector<int> stones1 {0,2,5,6,7};
    cout << solution.maxJump(stones1) << endl;
    vector<int> stones2 {0,3,9};
    cout << solution.maxJump(stones2) << endl;
}

int main() {
    testMaxJump();
    return 0;
}