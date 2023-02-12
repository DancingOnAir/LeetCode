#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;
class Solution {
public:
    // hash set
    int maxCount(vector<int>& banned, int n, int maxSum) {
        unordered_set<int> st(banned.begin(), banned.end());
        int res = 0;
        for (int i = 1; i <= n && maxSum >= 0; ++i) {
            if (!st.count(i)) {
                maxSum -= i;
                res += maxSum >= 0;
            }
        }
        return res;
    }
};

void testMaxCount() {
    Solution solution;

    vector<int> banned1 {1, 6, 5};
    cout << solution.maxCount(banned1, 5, 6) << endl;

    vector<int> banned2 {1, 2, 3, 4, 5, 6, 7};
    cout << solution.maxCount(banned2, 8, 1) << endl;

    vector<int> banned3 {11};
    cout << solution.maxCount(banned3, 7, 50) << endl;
}

int main() {
    testMaxCount();
    return 0;
}
