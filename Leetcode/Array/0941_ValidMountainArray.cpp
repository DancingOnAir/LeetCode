#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        int n = A.size();
        int i = 0, j = n - 1;
        while (i < n - 1 && A[i] < A[i + 1]) {
            ++i;
        }
        
        while (j > 0 && A[j - 1] > A[j]) {
            --j;
        }

        return (i > 0 && i == j && j < n - 1);
    }

    bool validMountainArray1(vector<int>& A) {
        int n = A.size();
        if (n < 3 || A[0] >= A[1])
            return false;

        int i = 1;
        while (i < n && A[i - 1] < A[i]) {
            ++i;
        }

        if (i == n || i == 1)
            return false;
        
        while (i < n && A[i - 1] > A[i]) {
            ++i;
        }

        return i == n;
    }
};

void testValidMountainArray() {
    Solution solution;

    // vector<int> A1 {2, 1};
    // cout << (solution.validMountainArray(A1) ? "True" : "False") << endl;
    // vector<int> A2 {3, 5, 5};
    // cout << (solution.validMountainArray(A2) ? "True" : "False") << endl;
    // vector<int> A3 {0, 3, 2, 1};
    // cout << (solution.validMountainArray(A3) ? "True" : "False") << endl;
    // vector<int> A4 {1, 3, 2};
    // cout << (solution.validMountainArray(A4) ? "True" : "False") << endl;
    vector<int> A5 {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    cout << (solution.validMountainArray(A5) ? "True" : "False") << endl;
}

int main() {
    testValidMountainArray();

    return 0;
}