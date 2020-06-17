#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    int heightChecker(vector<int>& heights) {
        auto n = heights.size();
        if (n < 2)
            return 0;

        vector<int> copy(heights);
        sort(copy.begin(), copy.end());
        int res = 0;
        for (auto i = 0; i < n; ++i) {
            if (copy[i] != heights[i]) {
                ++res;
            }
        }

        return res;
    }
};

void testHeightChecker() {
    Solution solution;

    vector<int> heights1 {1, 1, 4, 2, 1, 3};
    cout << solution.heightChecker(heights1) << endl;

    vector<int> heights2 {5, 1, 2, 3, 4};
    cout << solution.heightChecker(heights2) << endl;

    vector<int> heights3 {1, 2, 3, 4, 5};
    cout << solution.heightChecker(heights3) << endl;
}

int main() {
    testHeightChecker();

    return 0;
}