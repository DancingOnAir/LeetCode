#include <iostream>
#include <queue>


using namespace std;
class Solution {
public:
    int kthLargestValue(vector<vector<int>>& matrix, int k) {
        auto R = matrix.size();
        auto C = matrix[0].size();

        vector<vector<int>> res(R + 1, vector<int>(C + 1, 0));
        // 这里greater是小顶堆，每次把计算的结果入堆，如果size > k，就把最小值出堆，最后剩下k个最大值，堆顶的就是第k大的值。cpp里默认是大顶堆，即less
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < C; ++j) {
                res[i + 1][j + 1] = matrix[i][j] ^ res[i][j + 1] ^ res[i + 1][j] ^ res[i][j];
                pq.push(res[i + 1][j + 1]);
                if (pq.size() > k) {
                    pq.pop();
                }
            }
        }

        return pq.top();
    }
};


void testKthLargestValue() {
    Solution solution;
    vector<vector<int>> matrix {{5, 2}, {1, 6}};
    cout << solution.kthLargestValue(matrix, 1) << endl;
    cout << solution.kthLargestValue(matrix, 2) << endl;
    cout << solution.kthLargestValue(matrix, 3) << endl;
}

int main() {
    testKthLargestValue();
}