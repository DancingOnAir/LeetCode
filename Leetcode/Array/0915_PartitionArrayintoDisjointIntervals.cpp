#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
using namespace std;

class Solution {
public:
    int partitionDisjoint(vector<int>& A) {
        int n = A.size();
        vector<pair<int, int>> vii(n);
        for (int i = 0; i < n; ++i) {
            vii[i] = make_pair(A[i], i);
        }

        stable_sort(vii.begin(), vii.end(), [](pair<int, int> lhs, pair<int, int> rhs) { return lhs.first < rhs.first; });
        set<int> original, now;

        for (int i = 0; i < n; ++i) {
            original.emplace(vii[i].second);
            now.emplace(i);

            if (original == now)
                return i + 1;
        }

        return 0;
    }

    int partitionDisjoint1(vector<int>& A) {
        int n = A.size();

        vector<int> left(n);
        int leftMax = A[0];
        for (int i = 0; i < n; ++i) {
            leftMax = max(leftMax, A[i]);
            left[i] = leftMax;
        }

        vector<int> right(n);
        int rightMin = A[n - 1];
        for (int i = n - 1; i >= 0; --i) {
            rightMin = min(rightMin, A[i]);
            right[i] = rightMin;
        }

        for (int i = 1; i < n; ++i) {
            if (left[i - 1] <= right[i]) {
                return i;
            }
        }

        return 0;
    }

    int partitionDisjoint2(vector<int>& A) {
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