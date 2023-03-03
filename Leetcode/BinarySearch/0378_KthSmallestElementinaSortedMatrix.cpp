#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    int countLessOrEqual(vector<vector<int>>& matrix, int x) {
        int res = 0;
        int c = matrix.size() - 1;
        for (int r = 0; r < matrix.size(); ++r) {
            while (c >= 0 && matrix[r][c] > x) {
                --c;
            }
            res += c + 1;
        }

        return res;
    }

    // binary search
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int left = matrix[0][0], right = matrix[n - 1][n - 1];
        int res = 0;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (countLessOrEqual(matrix, mid) >= k) {
                res = mid;
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }

        return res;
    }
};

void testKthSmallest() {
    Solution solution;
    vector<vector<int>> matrix1 {{1,5,9},{10,11,13},{12,13,15}};
    cout << solution.kthSmallest(matrix1, 8) << endl;
    vector<vector<int>> matrix2 {{-5}};
    cout << solution.kthSmallest(matrix2, 1) << endl;
}

int main() {
    testKthSmallest();
    return 0;
}
