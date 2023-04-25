#include <iostream>
#include <vector>
#include <numeric>


using namespace std;
class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int idx = -1, mx = -1;
        for (int i = 0; i < mat.size(); ++i) {
            int cur = accumulate(mat[i].begin(), mat[i].end(), 0);
            if (cur > mx) {
                mx = cur;
                idx = i;
            }
        }

        return {idx, mx};
    }
};

void print(vector<int>& nums) {
    for (int x : nums) {
        cout << x << ", ";
    }
    cout << endl;
}

void testRowAndMaximumOnes() {
    Solution solution;
    vector<vector<int>> mat1 {{0,1},{1,0}};
    auto res1 = solution.rowAndMaximumOnes(mat1);
    print(res1);
}

int main() {
    testRowAndMaximumOnes();
    return 0;
}
