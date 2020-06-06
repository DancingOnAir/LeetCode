#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        int n = A.size();
        unordered_map<int, int> m;
        for (int i = 0; i < n; ++i) {
            m[A[i]]++;
            m[B[i]]++;
        }

        int maxCount = INT_MIN;
        int maxVal = INT_MIN;
        for (auto& i : m) {
            if (maxCount < i.second) {
                maxVal = i.first;
                maxCount = i.second;
            }
        }

        if (maxCount < n) {
            return -1;
        }

        int countA = 0;
        for (int i = 0; i < n; ++i) {
            if (maxVal == A[i]) {
                continue;
            }
            
            if (maxVal != B[i]) {
                return -1;
            }
            else {
                ++countA;
            }
        }

        int countB = 0;
        for (int i = 0; i < n; ++i) {
            if (maxVal == B[i]) {
                continue;
            }

            if (maxVal == A[i]) {
                ++countB;
            }
            else {
                return -1;
            }
        }

        return min(countA, countB);
    }
};

void testMinDominoRotations() {
    Solution solution;

    vector<int> A1 {2, 1, 2, 4, 2, 2};
    vector<int> B1 {5, 2, 6, 2, 3, 2};
    cout << solution.minDominoRotations(A1, B1) << endl;

    vector<int> A2 {3, 5, 1, 2, 3};
    vector<int> B2 {3, 6, 3, 3, 4};
    cout << solution.minDominoRotations(A2, B2) << endl;

    vector<int> A3 {1, 2, 1, 1, 1, 2, 2, 2};
    vector<int> B3 {2, 1, 2, 2, 2, 2, 2, 2};
    cout << solution.minDominoRotations(A3, B3) << endl;
}

int main() {
    testMinDominoRotations();

    return 0;
}