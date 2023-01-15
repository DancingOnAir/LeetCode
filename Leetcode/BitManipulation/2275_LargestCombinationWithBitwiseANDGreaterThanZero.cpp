#include <vector>
#include <iostream>

using namespace std;
class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int res = 0;
        for (int i = 0; i < 24; ++i) {
            int cur = 0;
            for (int x : candidates) {
                if ((x & (1 << i)) > 0) {
                    ++cur;
                }
            }
            res = max(res, cur);
        }

        return res;
    }
};

void testLargestCombination() {
    Solution solution;
    vector<int> candidates1 = {16, 17, 71, 62, 12, 24, 14};
    cout << solution.largestCombination(candidates1) << endl;

    vector<int> candidates2 = {8, 8};
    cout << solution.largestCombination(candidates2) << endl;
}

int main() {
    testLargestCombination();
    return 0;
}