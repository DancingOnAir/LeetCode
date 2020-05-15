#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
using namespace std;

class Solution {
public:
    int partitionDisjoint(vector<int>& A) {
        int n = A.size();
        if (n < 2)
            return -1;

        int left = 0, right = 1;
        int leftMax = A[0], curMax = A[1];
        while (right < n) {
            if (A[right] < leftMax) {
                left = right;
                leftMax = max(leftMax, curMax);
            }
            else {
                curMax = max(curMax, A[right]);
            }

            ++right;
        }

        return left + 1;
    }
};

void testPartitionDisjoint() {
    Solution solution;

    vector<int> A1 {5, 0, 3, 8, 6};
    cout << solution.partitionDisjoint(A1) << endl;

    vector<int> A2 {1, 1, 1, 0, 6, 12};
    cout << solution.partitionDisjoint(A2) << endl;
}

int main() {
    testPartitionDisjoint();

    return 0;
}