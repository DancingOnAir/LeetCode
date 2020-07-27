#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        vector<pair<int, int>> v;
        for (int i = 0; i < n; ++i) {
            v.emplace_back(make_pair(i, accumulate(mat[i].begin(), mat[i].end(), 0)));
        }

        sort(v.begin(), v.end(), [](const pair<int, int>& x, const pair<int, int>& y) { 
            return (x.second == y.second) ? x.first < y.first : x.second < y.second;
        });

        vector<int> res;
        for (int i = 0; i < k; ++i) {
            res.emplace_back(v[i].first);
        }

        return res;
    }
};

void printNums(const vector<int>& nums) {
    for (int num : nums) {
        cout << num << ", ";
    }

    cout << endl;
}

void testKWeakestRows() {
    Solution solution;

    vector<vector<int>> mat1 = {{1,1,0,0,0},
                                {1,1,1,1,0},
                                {1,0,0,0,0},
                                {1,1,0,0,0},
                                {1,1,1,1,1}};
    int k1 = 3;
    auto res1 = solution.kWeakestRows(mat1, k1);
    printNums(res1);

    vector<vector<int>> mat2 = {{1,0,0,0},
                                {1,1,1,1},
                                {1,0,0,0},
                                {1,0,0,0}};
    int k2 = 2;
    auto res2 = solution.kWeakestRows(mat2, k2);
    printNums(res2);
}

int main() {
    testKWeakestRows();

    return 0;
}